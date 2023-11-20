#include "../header.h"
#include "Player.h"

class Game
{
private :
    sf::RenderWindow window;
    sf::Event ev;

    // Créer un pointer
    // Pour le joueur que l'on va créer dans le constructeur joueur
    Player* player;

    void initWindow();
    void initPlayer();

public: 
    Game();

    //Functions
    void updatePlayer();
    void update();
    void renderPlayer();
    void render();
    const sf::RenderWindow& getWindow() const;
};