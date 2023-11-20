#include "../include/Player.h"

void Player::initTexture()
{
    if(!this->texture.loadFromFile("data/images/personnages/ichigo2.png")){
        std::cout << "ERROR::PLAYER::Ne peut pas charger l'avatar" << "\n";
    }
    else{std::cout << "Sa marche pas";}
}

void Player::initSprite()
{
    this->sprite.setTexture(this->texture);
}

Player::Player()
{
    this->initTexture();
    this->initSprite();
}
/*
void Player::updateMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) //gauche
    {
        this->sprite.move(-5.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // Droite
    {
        this->sprite.move(5.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) // Haut
    {
        this->sprite.move(0.f, -5.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) // Bas
    {
        this->sprite.move(0.f, 5.f);
    }
}
*/

void Player::update()
{
    //this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}