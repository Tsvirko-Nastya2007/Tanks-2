#pragma once
#include "SFML/Graphics.hpp"

class Labyrinth3 {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Labyrinth3() {
		texture.loadFromFile("labyrinth01.png");
		sprite.setTexture(texture);
		sprite.setPosition(1000, 0);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
};
