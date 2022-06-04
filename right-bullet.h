#pragma once
#include "const.h"
#include "SFML/Graphics.hpp"

class RightBullet {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	bool del = false;
	bool move = false;
public:
	RightBullet(float x, float y) {
		texture.loadFromFile("bullet.png");
		sprite.setTexture(texture);
		sprite.setPosition(x - sprite.getGlobalBounds().width / 2, y - sprite.getGlobalBounds().height / 2);
	}
	void update(/*float x, */float y) {
		if (move)
		{
			sprite.move(-6, y);
		}
	};
	void draw(sf::RenderWindow& window) { window.draw(sprite); };
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); };
	sf::Vector2f getPosition() { return sprite.getPosition(); };
	void setDel(bool a) { del = a; };
	bool getDel() { return del; };
	void setMove(bool state) { move = state; }
	bool getMove() { return move; }
};