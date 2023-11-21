#include "../include/Player.h"
#include "../header.h"

void Player::initTexture(){
    if(!this->texture.loadFromFile("./data/images/personnages/ichigo3.png")){
        std::cout << "ERROR::PLAYER::Ne peut pas charger l'avatar" << "\n";
   }
}

void Player::initSprite(){
    this->sprite.setTexture(this->texture);
}

Player::Player(){
    this->initTexture();
    this->initSprite();
}

void Player::updateMovement()
{
    std::cout << "x:" << this->sprite.getPosition().x << " y:" << this->sprite.getPosition().y << "\n";
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) //gauche
    {
        if (this->direction_horizontale == 1){
            this->sprite.move( this->sprite.getTexture()->getSize().x/2, 0.f);
        }
        this->direction_horizontale = -1;
        this->sprite.move(this->direction_horizontale, 0.f);
        this->sprite.setScale(this->direction_horizontale, 1.f); // Mirror horizontally
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // Droite
    {
        if (this->direction_horizontale == -1){
            this->sprite.move( -100, 0.f);
        }
        this->direction_horizontale = 1;
        this->sprite.move(1.f, 0.f);
        this->sprite.setScale(1.f, 1.f); // Mirror horizontally
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) // Haut
    {
        this->sprite.move(0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) // Bas
    {
        this->sprite.move(0.f, 1.f);
    }
}


void Player::update()
{
    this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}