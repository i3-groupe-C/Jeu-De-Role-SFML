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

/*
void Player::initPhysique(){
    //this->velocity
}
*/

    // Definie la taille du personnage
void Player::setSize(){
    this->size_x = this->sprite.getTexture()->getSize().x;
    this->size_y = this->sprite.getTexture()->getSize().y;
}

Player::Player(){
    this->initTexture();
    this->initSprite();
    this->setSize();
    //this->initPhysique();
}

void Player::updateMovement()
{
    //std::cout << "x:" << this->sprite.getPosition().x << " y:" << this->sprite.getPosition().y << "\n";

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) // Gauche
    {
        if (this->direction_horizontale == 1){
            this->sprite.move( this->size_x, 0.f);
        }
        this->direction_horizontale = -1;
        this->sprite.move(this->direction_horizontale * 1.f, 0.f);
        this->sprite.setScale(this->direction_horizontale * 1.f, 1.f); // Mirror horizontally
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // Droite
    {
        if (this->direction_horizontale == -1){
            this->sprite.move( -this->size_x, 0.f);
        }
        this->direction_horizontale = 1;
        this->sprite.move(this->direction_horizontale * 1.f, 0.f);
        this->sprite.setScale(this->direction_horizontale * 1.f, 1.f); // Mirror horizontally
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

/*
void updatePhysique(){
    //this->
}
*/

void Player::update()
{
    this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}