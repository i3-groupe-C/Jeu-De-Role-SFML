// gcc main2.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
// export DISPLAY=:0
// ./main
#include "./include/Game.h"


int main(int argc, char* argv[]) {
    
    srand(time(static_cast<unsigned>(0)));

    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();
        game.render();        
    }
    
    
    return 0;
}