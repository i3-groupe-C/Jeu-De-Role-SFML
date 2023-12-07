#pragma once


#include<sstream>

#include"Player.h"
#include"TileMap.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;
	sf::Texture tileSheet;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	//Systems
	unsigned points;

	// Player
	Player* player;

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	TileMap* tileMap;

	void initWindow();
	void initTileSheet();
	void initWorld();
	void initPlayer();
	void initTileMap();
	void initGUI();

public:

	//Functions
	Game();

	//Functions
	void updateInput();
	void updatePlayer();
	void updateCollision();
	void update();

	void updateGUI();

    void renderPlayer();
    void renderTileMap();

    void renderGUI();
	void renderWorld();
	void render();

	const sf::RenderWindow& getWindow() const;
};

