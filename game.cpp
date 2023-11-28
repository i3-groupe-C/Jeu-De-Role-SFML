#include "include/Game.h"

    // Initialise fenetre + Joueur
Game::Game(){
    this->initWindow();
    this->initPlayer();
}

    // Créer la fenetre
void Game::initWindow(){
    this->window.create(sf::VideoMode(HAUTEUR, LARGEUR), "Le jeu", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(180);
    window.setVerticalSyncEnabled(false);
}

    // Créer un joueur
void Game::initPlayer(){
    this->player = new Player();
}

    // Fonction principale qui actualise la fenetre de jeu
void Game::update(){

    // Gere les evenements de la fenetre
    while (this->window.pollEvent(this->ev))
    {
        if(this->ev.type == sf::Event::Closed)
            this->window.close();
        else if(this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
            this->window.close();
    }

    // Actualise les données du joueur
    this->updatePlayer();
    this->updateCollision();
}

void Game::updatePlayer(){
    this->player->update(); // Fonction Player::update
    
}

void Game::renderPlayer(){
    this->player->render(this->window); // Fonction Player::render
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

void Game :: updateCollision()
{
    //collision en bas de l'ecran
    if(this->player->getGlobalBounds().top + this->player->getGlobalBounds().height> this->window.getSize().y)
    {   this->player->resetVelocityY();
        this->player->setPosition(
            this->player->getGlobalBounds().left,
            this->window.getSize().y - this->player->getGlobalBounds().height
        );
    }
}