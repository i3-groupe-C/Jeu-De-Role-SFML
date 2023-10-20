#include "../header.h"

sf::Text prepareText(const sf::Font& font, const std::string& message, int fontSize, const sf::Color& textColor, const sf::Vector2f& position) {
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(fontSize);
    text.setFillColor(textColor);
    text.setPosition(position);
    return text;
}