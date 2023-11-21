#include "../header.h"

class Player
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        //Animation
        int direction_horizontale = 0;
        int direction_verticale = 0;

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