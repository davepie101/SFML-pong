#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game {

	public:
		static void Start();  //static functions can only call and access static class data members. Using it for global interface

	private:
		static bool isExiting();
		static void GameLoop();

		enum Gamestate { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting }; //state driven

		static GameState _gameState; 
		static sf::RenderWindow _mainWindow;

}