#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window) {

	//Load menu pixels from png file
	sf::Texture image;
	image.loadFromFile("mainmenu.png");
	sf::Sprite sprite(image);

	//Setting up clickable regions

	//Play menu coordinates
	MenuItem playButton;
	playButton.rect.Top = 145;
	playButton.rect.height = 380;
	playButton.rect.Left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	//Exit menu coordinates
	MenuItem exitButton;
	exitButton.rect.Top = 383;
	exitButton.rect.height = 560;
	exitButton.rect.Left = 0;
	exitButton.rect.width = 1023;
	exitButton.ation = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y) {

	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		sf::Rect<int> menuItemRect = (*it).rect;
		if( x > menuItemRect.left
    		&& x < menuItemRect.left + menuItemRect.width
    		&& y > menuItemRect.top  
    		&& y < menuItemRect.height + menuItemRect.top) 
		{
			return (*it).action;
		}

	}
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window) {
	sf::Event menuEvent;

	while(true) {
		while(window.pollEvent(menuEvent)) {
			if(menuEvent.type == sf::Event::MouseButtonPressed) {
				return HandleClick(menuEvent.MouseButton.X, menuEvent.MouseButton.Y);
			}
			if(menuEvent.type == sf::Event::Closed) {
				return Exit;
			} 
		}
	}
}

