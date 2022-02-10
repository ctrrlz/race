#include "game.h"
#include "const.h"
Game::Game(){
	window.create(
		sf::VideoMode(
			static_cast<size_t>(WINDOW_WIDTH),
			static_cast<size_t>(WINDOW_HEIGHT)
		),
		"Game",
		sf::Style::Titlebar | sf::Style::Close
	);
	window.setFramerateLimit(FPS);
	road1.init(0.f, 0.f);
	//road1 = newRoad
	road2.init(0.f, -WINDOW_HEIGHT);
}
void Game::play(){
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		road1.update(); 
		road2.update();
		car.update();
		window.clear(sf::Color::Black);
		window.draw(road1.getSprite());
		window.draw(road2.getSprite());
		window.draw(car.getSprite());
		window.display();
	}
	
}