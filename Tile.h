#pragma once
class Tile
{
private:
	sf::Sprite sprite;

public:
	Tile(sf::Texture* texture_sheet, sf::IntRect texture_rect);

	const sf::FloatRect getGlobalBounds() const;

	void render(sf::RenderTarget& target);
};