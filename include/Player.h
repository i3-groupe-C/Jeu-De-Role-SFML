#include "../header.h"

class Player
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        //Animation
        float size_x;
        float size_y;
        int direction_horizontale = 0;
        int direction_verticale = 0;

        // Mouvement


        // Core

        void initTexture();
        void initSprite();
        void setSize();
        

    public:
        Player();

        // Functions
        void updateMovement();
        void update();
        void render(sf::RenderTarget& target);
};