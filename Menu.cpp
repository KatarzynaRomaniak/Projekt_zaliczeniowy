#include "Menu.h"


Menu::Menu()
{
	loadFont();
	defaultAtrib();
	defaultPosition();
}

void Menu::render(sf::RenderTarget& target)
{
	for( int i = 0; i < size; i++){
	target.draw(options[i]);
	
	}
}
void Menu::defaultPosition()
{
	options[0].setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	for (int i = 1; i <= size; i++) {
		options[i].setPosition(options[0].getPosition().x, options[i - 1].getPosition().y + 100.f);

	}
}
void Menu::defaultAtrib()
{
	for (int i = 0; i < size; i++) {
		options[i].setFont(font);
		options[i].setString(s_tab[i]);
		options[i].setCharacterSize(60);
	}
}
void Menu::loadFont()
{
	if (!font.loadFromFile("Fonts/BebasNeue-Regular.ttf")); {
		//std::cout << "blad odczytu";
	}
}
void  Menu::updateoptions(sf::FloatRect pl,sf::Event choice, player play)
{
	for(int i = 0; i < size; i++) {
		if (pl.intersects(options[i].getGlobalBounds()) || isMouseOver(options[i]) ) {
			
				options[i].setFillColor(sf::Color::Cyan);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || choice.type==sf::Event::MouseButtonPressed ) {
					if (i == 0) {
						chosen_option = 1;
						
					}
					else if (i == 1) chosen_option = 2;
					else if (i == 2) chosen_option = 3;
					else if (i == 3) { 
						
						chosen_option = 4; }
				}
		}
		else {
			options[i].setFillColor(sf::Color::White);
			
		}
	}
}

bool Menu::isGameON(sf::RenderWindow& window, player play)
{
	if (chosen_option == 1) {
		
		 return true;
	}
	else if (!chosen_option) {
		return false;
	}
	else if (chosen_option == 2) {
		
		window.close();
		exit(0);
		return false;
	}
	else if (chosen_option == 4) {
		reset = true;
		chosen_option = 1;
	}
	//else return false;
	
}

bool Menu::isGamePaused()
{
	if (chosen_option == 3) {
		wait = !wait;
	}
	return wait;
}

bool Menu::isMouseOver(sf::Text option)
{
	float mouse_X = sf::Mouse::getPosition().x;
	float mouse_Y = sf::Mouse::getPosition().y;
	
	float option_X = option.getPosition().x;
	float option_Y = option.getPosition().y;

	float option_width = option_X + option.getGlobalBounds().width + 25;
	float option_height = option_Y + option.getGlobalBounds().height + 35;

	if (mouse_X < option_width && mouse_X>option_X && mouse_Y<option_height && mouse_Y>option_Y) {
		return true;
	}
	else return false;
	/*for (int i = 0; i < 3; i++) {
		option_X[i] = options[i].getPosition().x;
		option_Y[i] = options[i].getPosition().y;

		 option_width[i] = options[i].getPosition().x + options[i].getGlobalBounds().width;
		 option_height[i] = options[i].getPosition().y + options[i].getGlobalBounds().height;

		 if (mouse_X < option_width[i] && mouse_X > option_X[i] && mouse_Y < option_height[i] && mouse_Y > option_Y[i]) {
			 return true;
		 }
		 else return false;
	}*/
	
}

void Menu::setPosition()
{
	options[0].setPosition(WINDOW_WIDTH - WINDOW_WIDTH/6, 0);
	options[1].setPosition(options[0].getPosition().x+ 75, 0);
	options[2].setPosition(options[1].getPosition().x+ 115 , 0);
	options[3].setPosition(options[0].getPosition().x - 135 , 0);
	for (int i = 0; i < size; i++) {
		options[i].setCharacterSize(45);
	}
}

void Menu::DeathScreen(sf::RenderTarget& target)
{
	deathscreen.setFont(font);
	deathscreen.setString(deathText);
	deathscreen.setFillColor(sf::Color::Cyan);
	deathscreen.setCharacterSize(200);
	deathscreen.setPosition(WINDOW_WIDTH/2.0f - 300.f,WINDOW_HEIGHT/2.0f- 350.f);
	target.draw(deathscreen);
	defaultPosition();
}

void Menu::drawHP(sf::RenderTarget& target,player play)
{
	
	HPwrite.setFont(font);
	HPwrite.setString(HPText+std::to_string(play.getHP()));
	HPwrite.setFillColor(sf::Color::Yellow);
	HPwrite.setCharacterSize(20);
	HPwrite.setPosition(play.get_currentXPosition(), play.get_currentYPosition()+110);
	target.draw(HPwrite);
}

bool Menu::resurrect()
{
	return reset;
}

void Menu::resetState()
{
	reset = false;
}




