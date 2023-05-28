#pragma once
#include "libraries.h"
class Points
{
public:
	Points(float posX, float posY);
	void setFont();
	void setText();
	void saveBest();
	void loadBest();
	bool isBestBeaten();
	void ResetPoints();
	void ResetDistance();
	void render(sf::RenderTarget& target);

	static int last_best_score;
	int getPoints();
	void updaeteScore();
	void updateDistance();


private:
	static int p;
	std::string s = "Points: ";
	std::string bstr = "Best Score: ";
	std::string distancet = "Distance Travelled: ";
	int hp;
	int road = 0;
	sf::Text best;
	sf::Text distance;
	sf::Text text;
	sf::Font font;
};

