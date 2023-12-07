#include "stdafx.h"
#include "Player.h"

void Player::initVariables() //initiation des variables pour l'animation et la vie du joueur

{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	this->hpMax = 100;
	this->hp = this->hpMax;

	this->score = 0;
}

void Player::initTexture()//initiation des textures du fichier
{
	if (!this->textureSheet.loadFromFile("Textures/player_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << "\n";
	}
}

void Player::initSprite()//initiation du spite
{	
	//Donne les texture au sprite
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); //SHOULD BE 40 50

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
	//Set la taille du sprite
}

void Player::initAnimations()//cycle des animations 
{
	this->animationTimer.restart();
	this->animationSwitch = true;
	this->currentFrame.left = 0.f;
}

void Player::initPhysics()//initiation des variables de la physique
{
	this->velocityMax = 22.f;
	this->velocityMin = 2.0f;
	this->acceleration = 3.0f;
	this->drag = 0.80f;
	this->gravity = 3.f;
	this->velocityMaxY = 30.f;
	this->canJump = false;
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
}


const int & Player::getHp() const//renvoie les hp
{
	return this->hp;
}

const int & Player::getHpMax() const
{
	return this->hpMax;
}

const int & Player::getscore() const
{
	return this->score;
}

void Player::setHp(const int hp)//initialise les hp
{
	this->hp = hp;
}

const bool& Player::getAnimSwitch()//changement de frame pour les animations
{
	this->anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return this->anim_switch;
}

const sf::Vector2f Player::getPosition() const //va chercher sa position
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const //declare la fenetre du joueur
{
	return this->sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y)//declare sa position
{
	this->sprite.setPosition(x, y);
}

void Player::resetVelocityY()//mets sa vitess a 0
{
	this->velocity.y = 0.f;
}

void Player::resetAnimationTimer()//fin du cycle des animations
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;

	//Limitation de la vitess
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//Gravite
	this->velocity.y += 1.0 * this->gravity;
	

	//Ralentissement
	this->velocity *= this->drag;

	//Limit du ralentissement
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	if(std::abs(this->velocity.x) <= 1.f)
		this->velocity.x = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()//changement des movements
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) //gauche
	{
		this->move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Droite
	{
		this->move(1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && canJump)//saut
	{
		this->score += 1;
		std::cout << "Score = " << this->getscore() << "\n";
		this->velocity.y = -70.f;
		this->canJump = false;
	}
	
	if(this->velocity.x > 0.f)
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	else if(this->velocity.x < 0.f)
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	else
		this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::updateAnimations()
{
	float speedPercent = (abs(this->velocity.x) / this->velocityMax);// Calcul du pourcentage de la vitesse du joueur par rapport à la vitesse maximale
	//std::cout << speedPercent << "\n";

	if (this->animState == PLAYER_ANIMATION_STATES::IDLE) // Si le joueur est immobile
	{
		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 200.f || this->getAnimSwitch())  // Si le temps écoulé dépasse 200 millisecondes ou si le commutateur d'animation est activé
		{	
			// Passage à la prochaine frame de l'animation
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 40.f;
			// Réinitialisation de la position si elle dépasse la largeur totale de l'animation
			if (this->currentFrame.left > 160.f)
				this->currentFrame.left = 0;		
			// Redémarrage du compteur de temps
			this->animationTimer.restart();
			// Application de la nouvelle frame au sprite
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 40.f / speedPercent || this->getAnimSwitch())
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left > 360.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		// Réglage de l'échelle et de l'origine du sprite pour le mouvement vers la droite
		this->sprite.setScale(3.f, 3.f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 40.f / speedPercent || this->getAnimSwitch())
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left > 360.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		// Réglage de l'échelle et de l'origine du sprite pour le mouvement vers la gauche
		this->sprite.setScale(-3.f, 3.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else
		// Si le joueur est dans un état inconnu, redémarrage du compteur de temps
		this->animationTimer.restart();
}

void Player::update()
{
	this->updateMovement(); //mets a jour les movements
	this->updateAnimations(); //mets a jour les animations
	this->updatePhysics(); //mets a jour la  physique
}

void Player::render(sf::RenderTarget & target)
{
	// Dessine le joueur
	target.draw(this->sprite);

	sf::CircleShape circ;
	circ.setFillColor(sf::Color::Red);
	circ.setRadius(2.f);
	circ.setPosition(this->sprite.getPosition());

	target.draw(circ);
}
