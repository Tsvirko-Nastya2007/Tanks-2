#pragma once
#include "SFML/Graphics.hpp"

class Bombas {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Bombas();
	void draw(sf::RenderWindow&);
	void spawn();
	sf::FloatRect getHitBox();
	sf::Vector2f getPossition();
};

