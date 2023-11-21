#include "include/Game.h"

Game::Game(){
    this->initWindow();
    this->initPlayer();
}

void Game::initWindow(){
    this->window.create(sf::VideoMode(HAUTEUR, LARGEUR), "Le jeu", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(144);
}

void Game::initPlayer(){
    this->player = new Player();
}

void Game::updatePlayer()
{
    this->player->update();
}

void Game::update(){

    // Gere les evenements de la fenetre
    while (this->window.pollEvent(this->ev))
    {
        if(this->ev.type == sf::Event::Closed)
            this->window.close();
        else if(this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
            this->window.close();
    }

    this->updatePlayer();

}

void Game::renderPlayer(){
    this->player->render(this->window);
}

void Game::render()
{
    this->window.clear();

    this->renderPlayer();
    //Render game

    this->window.display();
}

const sf::RenderWindow & Game::getWindow() const{
    return this->window;    
}