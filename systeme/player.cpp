#include "../include/Player.h"

void Player::initTexture()
{
    if(!this->texture.loadFromFile("data/images/personnages/ichigo1.png")){
        std::cout << "ERROR::PLAYER::Ne peut pas charger l'avatar" << "\n";
    }
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



void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}