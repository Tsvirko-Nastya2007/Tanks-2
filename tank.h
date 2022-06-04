#pragma once
#include "SFML/Graphics.hpp"

class Tank {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	bool moveRight = false;
	bool moveLeft = false;
	bool moveUp = false;
	bool moveDown = false;
	float width;
	float height;
public:
	Tank() {};
	Tank(float startx, float starty) {
		sprite.setPosition(startx, starty);
		sprite.setTexture(texture);
		sf::FloatRect g_bounds = sprite.getGlobalBounds();
		width = g_bounds.width;
		height = g_bounds.height;
	}
	void update() {
		sf::Vector2f position = sprite.getPosition();
	}
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
	void setMoveRight(bool state) { moveRight = state; }
	void setMoveLeft(bool state) { moveLeft = state; }
	void setMoveUp(bool state) { moveUp = state; }
	void setMoveDown(bool state) { moveDown = state; }
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	bool getMoveRight(){return moveRight;}
	bool getMoveLeft(){return moveLeft;}
	bool getMoveUp(){return moveUp;}
	bool getMoveDown(){return moveDown;}
	float getWidth() { return width; }
	float getHeight() { return height; }
};
