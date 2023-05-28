#pragma once
#include "libraries.h"
#include "player.h"
class Menu
{
public:
	Menu();
	~Menu() = default;
	void render(sf::RenderTarget& window);
	void defaultPosition();
	void defaultAtrib();
	void loadFont();
	void updateoptions(sf::FloatRect, sf::Event, player);
	bool isGameON(sf::RenderWindow&,player);
	bool isGamePaused();
	bool isMouseOver(sf::Text);
	void setPosition();
	void DeathScreen(sf::RenderTarget&);
	void drawHP(sf::RenderTarget&,player);
	bool resurrect();
	void resetState();
	sf::Vector2f MousePosition; 
private:
	bool reset=false;
	int chosen_option;
	bool wait=false;
	std::string s_tab[4] = {"Graj", "Wyjdz", "PAUZA","Powtorz"};
	std::string deathText="You Died";
	std::string HPText="HP: ";
	sf::Font font;
	sf::Text options[4];
	sf::Text deathscreen;
	sf::Text HPwrite;

	int size = sizeof(options)/sizeof(sf::Text);
	float option_width[4];
	float option_X[4];
	float option_height[4];
	float option_Y[4];
};

