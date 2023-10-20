#ifndef HEADER_FILE
#define HEADER_FILE

#define HAUTEUR 600
#define LARGEUR 800

#include <SFML/Graphics.hpp>
#include <iostream>

// Les composents
sf::Text prepareText(const sf::Font& font, const std::string& message, int fontSize, const sf::Color& textColor, const sf::Vector2f& position);

sf::Text menu();
int main(int argc, char* argv[]);

#endif