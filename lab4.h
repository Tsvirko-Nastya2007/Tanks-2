#pragma once
#include "SFML/Graphics.hpp"

class Labyrinth4 {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Labyrinth4() {
		texture.loadFromFile("labyrinth01.png");
		sprite.setTexture(texture);
		sprite.setPosition(1400, 400);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
};
