#include "header.h"

sf::Text menu(){
    sf::Text text;

    sf::Font font;
    if (!font.loadFromFile("src/fonts/Sixty.ttf")) {
        std::cerr << "Erreur lors de l'initialisation de la font : " << std::endl;
        return text;
    }

    text.setFont(font);
    text.setString("Bonjour, SFML !");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(100, 100);  

    return text;
}