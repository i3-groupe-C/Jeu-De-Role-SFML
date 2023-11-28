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


void Player::initPhysique(){
    this->velocityMax = 10.f;
    this->velocityMin = 1.f;
    this->acceleration = 3.f;
    this->drag = 0.95f;
    this->gravity = 4.f;
    this->velocityMaxY = 15.f;
}


    // Definie la taille du personnage
void Player::setSize(){
    this->size_x = this->sprite.getTexture()->getSize().x;
    this->size_y = this->sprite.getTexture()->getSize().y;
}

Player::Player(){
    this->initTexture();
    this->initSprite();
    this->setSize();
    this->initPhysique();
}

void Player::updateMovement()
{
    std::cout << "x:" << this->sprite.getPosition().x << " y:" << this->sprite.getPosition().y << "\n";

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) // Gauche
    {
        if (this->direction_horizontale == 1){
            this->sprite.move( this->size_x, 0.f);
        }
        this->direction_horizontale = -1;
        this->move(this->direction_horizontale * 1.f, 0.f);
        this->sprite.setScale(this->direction_horizontale * 1.f, 1.f); // Mirror horizontally

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // Droite
    {
        if (this->direction_horizontale == -1){
            this->sprite.move( -this->size_x, 0.f);
        }
        this->direction_horizontale = 1;
        this->move(this->direction_horizontale * 1.f, 0.f);
        this->sprite.setScale(this->direction_horizontale * 1.f, 1.f); // Mirror horizontally
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) // Haut
    {
        this->move(0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) // Bas
    {
        this->move(0.f, 1.f);
    }
}



void Player::move(const float dir_x, const float dir_y){
    // Acceleration
    this->velocity.x += dir_x * this->acceleration;
    // this->velocity.y += dir_y * this->acceleration; GRAVITE
    //Limit velocity
    if(std::abs(this->velocity.x) > this->velocityMax)
    {
        this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f );
    }

}


void Player::updatePhysique(){
    //Gravity
    this->velocity.y += 1.0 * this->gravity;
    if (std::abs(this->velocity.x) > this->velocityMaxY)
    {
        this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
    }
    

    // Déceleration
    this->velocity *= this->drag;
    //Limit deceleration
    if(std::abs(this->velocity.x) < this->velocityMin)
        this->velocity.x = 0.f;
    if (std::abs(this->velocity.y) < this->velocityMin)
        this->velocity.y = 0.f;
    
    this->sprite.move(this->velocity);
}


void Player::update()
{
    this->updateMovement();
    this->updatePhysique();
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

const sf::FloatRect Player::getGlobalBounds() const{
    return this->sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y){
    this->sprite.setPosition(x, y);
}

void Player::resetVelocityY(){
    this->velocity.y = 0.f;
}