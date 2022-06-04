#pragma once
#include "SFML/Graphics.hpp"

class Labyrinth2 {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Labyrinth2() {
		texture.loadFromFile("labyrinth01.png");
		sprite.setTexture(texture);
		sprite.setPosition(600, 400);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
};
