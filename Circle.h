#pragma once
#include "libraries.h"


class Circle 
{
public:

	Circle(float c_x, float c_y, float c_radius);
	~Circle()=default;
	void update();
	void create(int,std::vector<Circle>);
	void paused();
	void ResetCirclePos();
	void ResetVelocity();
	void SetToYZero();
	void render(sf::RenderTarget& circleTarget);
	 bool isOut() ;
	float rand_size();
	float currentY();
	float randomX();
	float randomY();
	sf::FloatRect globalBounds() const;
	void difficulty(int);
	void circleColor();
	void updatevelocity(float);
	void update_times_shot();

private:

	int randomize(int,int);
	int times_shot = 0;
		float c_x;
		float c_y;
		float c_radius;
	sf::CircleShape circle;
	sf::Vector2f resetVelocity{ 0.0f, 5.0f };
	sf::Vector2f velocity{ 0.0f, 5.0f };
	sf::Vector2f maxVelocity{ 0.0f,14.f };
};



