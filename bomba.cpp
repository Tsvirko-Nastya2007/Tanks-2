#include "bomba.h"
#include "const.h"
#include <ctime>

Bombas::Bombas() {
	texture.loadFromFile("bomba.png");
	sprite.setTexture(texture);
	spawn();
}
void Bombas::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Bombas::spawn() {
	float x = rand() % 1000 + 300;
	float y = rand() % 900;
	sprite.setPosition(x, y);
}
sf::FloatRect Bombas::getHitBox() {
	return sprite.getGlobalBounds();
}
sf::Vector2f Bombas::getPossition() {
	return sprite.getPosition();
}