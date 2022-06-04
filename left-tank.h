#pragma once
#include "tank.h"
#include "const.h"
#include "game.h"

class LeftTank :public Tank {
public:
    LeftTank() {
        texture.loadFromFile("texture.png");
        sprite.setTexture(texture);
        const int starty = WINDOW_HEIGHT / 2 + sprite.getGlobalBounds().height / 2;
        const int startx = 50;
        sprite.setPosition(startx, starty);
    }
    void move(float x, float y) { sprite.move(x, y); }
    void update() {
        if (moveRight) {
            sprite.move(speed, 0);
            if (sprite.getPosition().x > WINDOW_WIDTH - getHitBox().width)
            {
                sprite.setPosition(WINDOW_WIDTH - getHitBox().width, sprite.getPosition().y);
            }
        }
        if (moveLeft) {
            sprite.move(-speed, 0);
            if (sprite.getPosition().x < 0)
            {
                sprite.setPosition(0, sprite.getPosition().y);
            }
        }
        if (moveUp) {
            sprite.move(0, -speed);
            if (sprite.getPosition().y < 0)
            {
                sprite.setPosition(sprite.getPosition().x, 0);
            }
        }
        if (moveDown) {
            sprite.move(0, speed);
            if (sprite.getPosition().y > WINDOW_HEIGHT - getHitBox().height)
            {
                sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - getHitBox().height);
            }
        }
    }
    void draw(sf::RenderWindow& window) { window.draw(sprite); }
    sf::FloatRect getHitBox() {
        return sprite.getGlobalBounds();
    }
    void hide() {
        sprite.setPosition(99999999, 999999999);
    }
};