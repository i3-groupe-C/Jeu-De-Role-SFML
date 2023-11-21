#include "../header.h"

class Player
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        //Animation


        // Mouvement


        // Core

        void initTexture();
        void initSprite();

    public:
        Player();

        // Functions
        void updateMovement();
        void update();
        void render(sf::RenderTarget& target);
};