#include "Points.h"
#include <fstream>
Points::Points(float posX, float posY)
{
	hp = 3;
	setFont();
	setText();
	text.setPosition(0, 0);
	best.setPosition(0, text.getPosition().y+20);
	distance.setPosition(0,best.getPosition().y+20);
}

void Points::setFont()
{
	if (!font.loadFromFile("Inter-Black.ttf")); {
		//std::cout << "blad odczytu";
	}
}

void Points::setText()
{
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	

	best.setFont(font);
	best.setCharacterSize(20);
	best.setFillColor(sf::Color::White);

	distance.setFont(font);
	distance.setCharacterSize(20);
	distance.setFillColor(sf::Color::White);
	
}

void Points::saveBest()
{
	
		std::ofstream best_score("best_score.txt");
		best_score << p;
	

}

void Points::loadBest()
{
	std::ifstream best_score("best_score.txt");
	best_score >> last_best_score;
}

bool Points::isBestBeaten()
{
	if (p >= last_best_score) return true;
	else return false;
}

void Points::ResetPoints()
{
	p = 0;
}

void Points::ResetDistance()
{
	road = 0;
}

void Points::render(sf::RenderTarget& target)
{
	text.setString(s + std::to_string(p));
	best.setString(bstr + std::to_string(last_best_score));
	distance.setString(distancet + std::to_string(road));
	target.draw(text);
	target.draw(best);
	target.draw(distance);
}

int Points::getPoints()
{
	return p;
}

void Points::updaeteScore()
{
	p++;
	if (isBestBeaten()) {
		last_best_score = p;
	}
	
}

void Points::updateDistance()
{
	road++;
	
}
