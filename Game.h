#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game {

	public: //using static for a global
		static void Start();  

	private:
		static bool IsExiting();  
		static void GameLoop();

		enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting }; //state driven

		static GameState _gameState; 
		static sf::RenderWindow _mainWindow;

};