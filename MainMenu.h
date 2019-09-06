#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

class MainMenu {

public:
	enum MenuResult {Nothing, Exit, Play}; //Possible values that the menu could return

	struct MenuItem { //Putting MenuItem and MenuResult nested under MainMenu since they're only used here

	public:
		sf::Rect<int> rect; //dimensions of the MenuItem
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window); //Show() function returns a MenuResult enum type

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;  //list of MenuItems

};