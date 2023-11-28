#include "../header.h"

class Player
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        // Animation
        float size_x;
        float size_y;
        int direction_horizontale = 0;
        int direction_verticale = 0;

        // Physique
        sf::Vector2f velocity;
        float velocityMax;
        float acceleration;
        float drag;

        // Core

        void initTexture();
        void initSprite();
        void setSize();
        void initPhysique();

    public:
        Player();

        // Functions
        void updatePhysique();
        void updateMovement();
        void update();
        void render(sf::RenderTarget& target);
};