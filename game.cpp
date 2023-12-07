#include"stdafx.h"
#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(800, 600), "Game 4", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initTileSheet()
{
	if (!this->tileSheet.loadFromFile("Textures/player_sheet.png"))
	{
		std::cout << "ERROR::GAME::Could not load the tile sheet!" << "\n";
	}
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initTileMap()
{
	this->tileMap = new TileMap(20, 20, &this->tileSheet, 50);
	this->tileMap->addTile(0, 0);
}


void Game::initGUI()
{
	// Charles la font
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	// Initialise le texte
	this->pointText.setPosition(700.f, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Score un jour");

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
	this->getWindow().getSize().x/ 2.f - this->gameOverText.getGlobalBounds().width / 2.f, 
	this->getWindow().getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

Game::Game()
{
	this->initWindow();
	this->initGUI();
	this->initTileSheet();
	this->initWorld();
	this->initPlayer();
	this->initTileMap();
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCollision()
{
	//Collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->setCanJump(true);
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height
		);
	}
}

void Game::updateTileMap()
{
	this->tileMap->update();
}

void Game::update()
{
	//Polling window events
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();

		if (
			this->ev.type == sf::Event::KeyReleased &&
			(
				this->ev.key.code == sf::Keyboard::Q ||
				this->ev.key.code == sf::Keyboard::D
				)
			)
		{
			this->player->resetAnimationTimer();
		}
	}

	this->updatePlayer();

	this->updateCollision();

	this->updateTileMap();
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderTileMap()
{
	this->tileMap->render(this->window);
}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("./Textures/background1.jpg"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << "\n";
	}

	this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::renderGUI()
{
	this->window.draw(this->pointText);
	this->window.draw(this->playerHpBarBack);
	this->window.draw(this->playerHpBar);
	
}

// Dessine la map
void Game::renderWorld()
{
	this->window.draw(this->worldBackground);
}

void Game::render()
{
	this->window.clear();

	//Draw world
	this->renderWorld();

	if(this->player->getscore() > 10){
		//Game over screen
		this->window.draw(this->gameOverText);
		std::cout << "Gagner le score est de = " << this->player->getscore() << "\n";
	}

	//Draw all the stuffs
	this->player->render(this->window);

	this->renderGUI();

	//Render game
	this->renderTileMap();
	this->renderPlayer();

	this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
