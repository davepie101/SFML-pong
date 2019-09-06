#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow &renderWindow) {
	sf::Texture image; //texture loads the pixel data

	if(image.loadFromFile("Splashscreen.png") != true) { //Load splashscreen image and returns if it doesn't exist
		return;
	}

	sf::Sprite sprite(image); //Sprites are responsible for displaying the image on the screen

	renderWindow.draw(sprite); 
	renderWindow.display();

	sf::Event event;

	while(true) {
		while(renderWindow.pollEvent(event)) { //closes splashscreen window if button pressed, moused pressed, or closes the window
			if(event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed) 
			{
				return;
			}
		}
	}
}