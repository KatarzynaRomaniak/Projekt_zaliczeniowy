
#include"libraries.h"
#include"player.h"
#include"Circle.h"
#include"Projectile.h"
#include"Menu.h"
#include"Points.h"
#include"circular_motion.h"
#include"background.h"
#include"explosion.h"



int Points::p;
int Points::last_best_score;
int main()
{
    background bg;
    
    circular_motion* motion;
    motion = new circular_motion;
    sf::Clock timer;
    
    sf::Texture *bullet=new sf::Texture;
    bullet->loadFromFile("textures/enemy.png"); //w mainie ¿eby nie ³¹dowaæ jej za ka¿dym strza³em tylko przesy³aæ adres
    sf::Texture *explode= new sf::Texture;
    explode->loadFromFile("textures/explosion.png");
    float spawner = 0.195f;
    
    player play(PLAYER_START_X, PLAYER_START_Y);
    explosion* boom;
    std::vector<Projectile*> shot;
    
    std::vector<Circle> circles;

    Points counter(0,0);
    counter.loadBest();

    Menu* menu=new Menu;

    sf::RenderWindow window{ sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"SPACESHIP"};
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);
    sf::Event ev;
   
    srand(time(NULL));
    
    for (int i = 0; i < 20; i++) {
        //tworzy nowe kulki

        std::mt19937 generator(std::random_device{}()); //generuje liczby bardziej losoweni¿ rand()!!
        std::uniform_int_distribution<int> distribution(10, WINDOW_WIDTH);
        std::uniform_int_distribution<int> distributionY(-100,0);
        std::uniform_int_distribution<int> distributionSize(14,25);
        
        
            
            circles.push_back(Circle(distribution(generator), distributionY(generator), distributionSize(generator))); //wklada je do wektora
        
    }
    
    
    while (1) {

        window.clear(sf::Color::Black);
        window.pollEvent(ev);
        if (ev.type == sf::Event::Closed) {
            window.close();
            break;
        }
        bg.render(window);
        menu->render(window);
        menu->updateoptions(play.globalBounds(),ev,play);
        
        if (menu->isGameON(window,play)) {
            menu->setPosition();
            
            
            counter.render(window);
            if (counter.getPoints() % 11 == 0 && !motion->isSpawned() && counter.getPoints() !=0 ) {
                
                motion->spawn(play.get_currentXPosition(), play.get_currentYPosition());
            }
           // motion.update();
            if (menu->resurrect()) { //reset
                
                if (counter.isBestBeaten()) {
                    counter.saveBest();
                }

                counter.ResetPoints();
                play.resetHP();
                play.resetPosition();
                
                for (int i = 0; i < circles.size(); i++) {
                    circles[i].ResetCirclePos();
                    circles[i].ResetVelocity();
                }
                
            }
            
            if (!play.isPlayerDead()) {
                menu->drawHP(window, play);
                play.render(window);
                play.player_move(ev);

                if (motion->isSpawned()) { 
                motion->render(window); 
                motion->update();
                }
               if(!menu->isGamePaused()) counter.updateDistance();
                
                }
            menu->resetState();
                // if (menu->isGameON(window)) play.hp = 3;

           

                if (timer.getElapsedTime().asSeconds() >= spawner) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        shot.push_back(new Projectile(bullet, play.bulletOrigin()));
                        
                    }
                    timer.restart();
                }

                for (int j = 0; j < shot.size(); j++) {

                     shot[j]->update();
                    shot[j]->render(&window);
                    if (shot[j]->ProjectileIsOut()) {
                        delete shot[j];
                        shot.erase(shot.begin() + j);

                    }
                    else if (shot[j]->getProjectileBounds().intersects(motion->getGlobalBounds())) {
                        motion->turnOff();
                        counter.updaeteScore();
                        delete shot[j];
                        shot.erase(shot.begin() + j);
                        play.upHP();
                    }
                }
            

                for (int i = 0; i < circles.size(); i++) {//

                    if (!play.isPlayerDead()) {
                        circles[i].circleColor();
                        circles[i].render(window);
                        if (!menu->isGamePaused()) {
                            circles[i].update();
                        }
                        else circles[i].paused();
                    }
                    //else circles[i].paused();


                    if (circles[i].isOut()) {
                        circles[i].SetToYZero();
                    }
                    if (motion->getGlobalBounds().intersects(play.globalBounds())) {
                        play.kill();
                    }

                    //zderzenie z graczem
                    if (circles[i].globalBounds().intersects(play.globalBounds())) {
                        circles[i].SetToYZero();
                        play.HPdown();
                        boom = new explosion(play.get_currentXPosition(), play.get_currentYPosition(), explode);
                        boom->render(window);
                        
                    }
                    //zderzenie strzalu z kulka
                    if(!menu->isGamePaused()){
                        for (int j = 0; j < shot.size(); j++) {
                            if (shot[j]->getProjectileBounds().intersects(circles[i].globalBounds())) {
                                circles[i].SetToYZero();
                                circles[i].update_times_shot();
                                circles[i].updatevelocity(counter.getPoints());
                                delete shot[j];
                                shot.erase(shot.begin() + j);

                                //punkty i funkcje update do nich
                                counter.updaeteScore();

                                if (counter.isBestBeaten()) {
                                    counter.saveBest();
                                }

                            }
                        }
                    }//
                
            }
                if (play.isPlayerDead()) {

                    counter.ResetDistance();
                    menu->DeathScreen(window);
                    
                }
                
        }
       
        window.display();
     }    

    return 0;
}

