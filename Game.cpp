#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"

void Game::Start(void) {  //only public method, call this to get the game started
	if (_gameState != Uninitialized) return;  //To ensure that Game::Start is only called once

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pong!"); //Creating the main window at a resolution of 1024x768 at 32bpp color with the title "Pong!"
	_gameState = Game::ShowingSplash; //Switch to ShowingSplash state

	while(!IsExiting()) { 
		GameLoop();
	}

	_mainWindow.close(); //Close window after game exits

}

bool Game::IsExiting() { //Exiting state function
	if(_gameState == Game::Exiting) {
		return true;
	}
	else {
		return false;
	}
}

void Game::GameLoop() {
	switch(_gameState) {
		case Game::ShowingMenu: {
			ShowMenu();
			break;
		}
		case Game::ShowingSplash: {
			ShowSplashScreen();
			break;
		}
		case Game::Playing: {
			sf::Event currentEvent;
			while(_mainWindow.pollEvent(currentEvent)) {
				_mainWindow.clear(sf::Color(0,0,0));
				_mainWindow.display();
				
				if(currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting; //Closed requested event and exit game.

				if(currentEvent.type == sf::Event::KeyPressed) { //If escape key is pressed, return to menu
					if(currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
				}
			}
			break;
		}
	}
}

void Game::ShowSplashScreen() { //Calls SplashScreen's Show function to render splashscreen
	SplashScreen splashScreen; 
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu() { //Renders menu
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result) { //Alters gamestate depending on where button is pressed
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}

Game::GameState Game::_gameState = Uninitialized; //initializing GameState and assigning it a default value of Unitialized
sf::RenderWindow Game::_mainWindow;