#include "game.h"
#include "const.h"

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE)
{
	window.setVerticalSyncEnabled(true);
	for (size_t i = 0; i < 20; i++) {
		Bombas* bomba = new Bombas();
		bombas.push_back(bomba);
	}
}

void Game::play() {
	while (window.isOpen()) {
		check_events();
		check_colisions();
		update();
		draw();
	}
}

void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		//klavisha ne nazata
		if (event.type == sf::Event::KeyReleased)
		{
			//pravy tank
			if (event.key.code == sf::Keyboard::Down) {
				righttank.setMoveDown(false);
			}
			if (event.key.code == sf::Keyboard::Left) {
				righttank.setMoveLeft(false);
			}
			if (event.key.code == sf::Keyboard::Right) {
				righttank.setMoveRight(false);
			}
			if (event.key.code == sf::Keyboard::Up) {
				righttank.setMoveUp(false);
			}
			//levy tank
			if (event.key.code == sf::Keyboard::X) {
				lefttank.setMoveDown(false);
			}
			if (event.key.code == sf::Keyboard::A) {
				lefttank.setMoveLeft(false);
			}
			if (event.key.code == sf::Keyboard::D) {
				lefttank.setMoveRight(false);
			}
			if (event.key.code == sf::Keyboard::W) {
				lefttank.setMoveUp(false);
			}
		}
		//klavisha nazata
		if (event.type == sf::Event::KeyPressed) {
			//pravy tank
			//puli dla pravogo tanka
			if (game_state == PLAY && event.key.code == sf::Keyboard::Space) {
				sf::Time now = clock.getElapsedTime();
				if (now.asMilliseconds() < fire_delay) {
					clock.restart();
					RightBullet* new_rghtbull = new RightBullet(
						righttank.getPosition().x + righttank.getHitBox().width/2,
						righttank.getPosition().y + righttank.getHitBox().height / 2
					);
					rghtbull.push_back(new_rghtbull);
				}
			}
			//
			if (event.key.code == sf::Keyboard::Left) {
					righttank.setMoveLeft(true);
			}
			if (event.key.code == sf::Keyboard::Right) {
					righttank.setMoveRight(true);
			}
			if (event.key.code == sf::Keyboard::Up) {
					righttank.setMoveUp(true);
			}
			if (event.key.code == sf::Keyboard::Down) {
				righttank.setMoveDown(true);
			}
			//levy tank
			if (event.key.code == sf::Keyboard::A)
			{
				lefttank.setMoveLeft(true);
			}
			if (event.key.code == sf::Keyboard::D)
			{
				lefttank.setMoveRight(true);
			}
			if (event.key.code == sf::Keyboard::W)
			{
				lefttank.setMoveUp(true);
			}
			if (event.key.code == sf::Keyboard::X)
			{
				lefttank.setMoveDown(true);
			}
		}
	}
}

void Game::check_colisions() {
	//pravy tank stalkivaetsa s labirintom
	while ((righttank.getHitBox().intersects(l1.getHitBox())|| righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox()))
		&& righttank.getMoveRight()) {
		righttank.setMoveRight(false);
		righttank.move(-5,0);
	}
	while ((righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox()))
		&& righttank.getMoveLeft()) {
		righttank.setMoveLeft(false);
		righttank.move(5, 0);
	}
	while ((righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox()))
		&& righttank.getMoveUp()) {
		righttank.setMoveUp(false);
		righttank.move(0,5);
	}
	while ((righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox()))
		&& righttank.getMoveDown()) {
		righttank.setMoveDown(false);
		righttank.move(0, -5);
	}
	//levy tank stalkivaetsa s labirintom
	while ((lefttank.getHitBox().intersects(l1.getHitBox()) || lefttank.getHitBox().intersects(l2.getHitBox()) ||
		lefttank.getHitBox().intersects(l3.getHitBox()) || lefttank.getHitBox().intersects(l4.getHitBox()))
		&& lefttank.getMoveRight()) {
		lefttank.setMoveRight(false);
		lefttank.move(-5, 0);
	}
	while ((lefttank.getHitBox().intersects(l1.getHitBox()) || lefttank.getHitBox().intersects(l2.getHitBox()) ||
		lefttank.getHitBox().intersects(l3.getHitBox()) ||lefttank.getHitBox().intersects(l4.getHitBox()))
		&& lefttank.getMoveLeft()) {
		lefttank.setMoveLeft(false);
		lefttank.move(5, 0);
	}
	while ((lefttank.getHitBox().intersects(l1.getHitBox()) || lefttank.getHitBox().intersects(l2.getHitBox()) ||
		lefttank.getHitBox().intersects(l3.getHitBox()) || lefttank.getHitBox().intersects(l4.getHitBox()))
		&& lefttank.getMoveUp()) {
		lefttank.setMoveUp(false);
		lefttank.move(0, 5);
	}
	while ((lefttank.getHitBox().intersects(l1.getHitBox()) || lefttank.getHitBox().intersects(l2.getHitBox()) ||
		lefttank.getHitBox().intersects(l3.getHitBox()) || lefttank.getHitBox().intersects(l4.getHitBox()))
		&& lefttank.getMoveDown()) {
		lefttank.setMoveDown(false);
		lefttank.move(0, -5);
	}
	//pravy tank stolknylsa s bombami
	for (auto iter = bombas.begin(); iter != bombas.end(); iter++) 
	{
		if (righttank.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->spawn();
			righttank.hide();
		}
	}
	//levy tank stolknylsa s bombami
	for (auto iter = bombas.begin(); iter != bombas.end(); iter++)
	{
		if (lefttank.getHitBox().intersects((*iter)->getHitBox())) {
			(*iter)->spawn();
			lefttank.hide();
		}
	}
}

void Game::update() {
	righttank.update();
	lefttank.update();
	for (auto iter = rghtbull.begin(); iter != rghtbull.end(); iter++) {
		(*iter)->update(righttank.getPosition().y);
	}
	rghtbull.remove_if([](RightBullet* bull) {return bull->getHitBox().intersects(lefttank.getHitBox()/*getPosition().y < -50*/; });
}

void Game::draw() {
	window.clear(sf::Color::Black);
	righttank.draw(window);
	lefttank.draw(window);
	for (size_t i = 0; i < 20; i++) {
		bombas[i]->draw(window);
	}
	l1.draw(window);
	l2.draw(window);
	l3.draw(window);
	l4.draw(window);
	window.display();
}