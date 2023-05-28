#include "Circle.h"
#include "libraries.h"

Circle::Circle(float c_x, float c_y, float c_radius)
{
	circle.setPosition(c_x, c_y);
	circle.setRadius(c_radius);
}

void Circle::update()
{
	circle.move(velocity);
}



void Circle::paused()
{
	circle.move(0, 0);
}

void Circle::ResetCirclePos()
{


	circle.setPosition(randomize(10,WINDOW_WIDTH), randomize(-150,150));
}

void Circle::ResetVelocity()
{
	velocity=resetVelocity;
}

void Circle::SetToYZero()
{
	//std::mt19937 generator(std::random_device{}()); //generuje liczby bardziej losoweni¿ rand()!!
	//std::uniform_int_distribution<int> distribution(10, 1910);
	
	circle.setPosition(randomize(10, 1910) , -300.f);
}

void Circle::render(sf::RenderTarget& circleTarget)
{
	circleTarget.draw(circle);
}

bool Circle::isOut() 
{
	return currentY() > WINDOW_HEIGHT;
}

float Circle::currentY()
{
	return circle.getPosition().y;
}


sf::FloatRect Circle::globalBounds() const
{
	return circle.getGlobalBounds();
}

void Circle::circleColor()
{
	if(velocity.y>=5.0f && velocity.y<=7.0f) circle.setFillColor(sf::Color::White);
	else if(velocity.y>7.0f && velocity.y<=9.0f) circle.setFillColor(sf::Color::Blue);
	else if(velocity.y>9.0f && velocity.y<=11.0f) circle.setFillColor(sf::Color::Magenta);
	else if(velocity.y>11.0f) circle.setFillColor(sf::Color::Red);
	

}

void Circle::updatevelocity(float points)
{
	if (velocity.y <= maxVelocity.y) {
		velocity.y += times_shot / 1;
	}
	else velocity.y = velocity.y;
}

void Circle::update_times_shot()
{
	times_shot++;
}

int Circle::randomize(int _x,int _y)
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(_x, _y);
	
	return distribution(generator);
}


