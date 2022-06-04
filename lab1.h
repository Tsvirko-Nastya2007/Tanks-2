#pragma once
#include "SFML/Graphics.hpp"

class Labyrinth1 {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Labyrinth1() {
		texture.loadFromFile("labyrinth01.png");
		sprite.setTexture(texture);
		sprite.setPosition(200, 0);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
};