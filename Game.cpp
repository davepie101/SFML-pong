#include "stdafx.h"
#include "Game.h"

void Game::Start(void) {  //only public method, call this to get the game started
	if (_gameState != Uninitialized) return;  //To ensure that Game::Start is only called once

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pong!"); //Creating the main window at a resolution of 1024x768 at 32bpp color with the title "Pong!"
	_gameState = Game::Playing; //Switch to Playing state

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
	sf::Event currentEvent;
	while(_mainWindow.pollEvent(currentEvent)) {
		switch(_gameState) {
			case Game::Playing: {
				_mainWindow.clear(sf::Color(255,0,0));
				_mainWindow.display();

				if (currentEvent.type == sf::Event::Closed) {
					_gameState = Game::Exiting;
				}
				break;
			}
		}
	}
}

Game::GameState Game::_gameState = Uninitialized; //initializing GameState and assigning it a default value of Unitialized
sf::RenderWindow Game::_mainWindow;