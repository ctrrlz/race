#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
class Road {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.f, 9.f);
public:
	Road() {
		texture.loadFromFile("rd.jpg");
		sprite.setTexture(texture);
	}
	void init(float startx, float starty) {
		sprite.setPosition(startx, starty);
	}
	sf::Sprite getSprite() { return sprite; }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(0.f, -WINDOW_HEIGHT);
		}
	}
};