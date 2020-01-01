#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager() {
}

GameObjectManager::~GameObjectManager() {
	std::for_each(_gameObjects.begin(),_gameObjects.end(), GameObjectDeallocator()); //Starts at the first iterator, ends at the second. Calls the function for each.
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject) {
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name) {
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end()) {
		delete results->second;
		_gameObjects.erase(results);
	}
}

VisibleGameObject* GameObjectManager::Get(std::string name) const {
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end()) { //Checks if results is pointing to end of file. If it is, it means it's not pointing to anything, thus return NULL
		return NULL;
	}
	return results->second; //Returns the VisibileGameObject* we're looking for
}

int GameObjectManager::GetObjectCount() const {
	return _gameObjects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow) {
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end()) {
		itr->second->Draw(renderWindow);
		itr++;
	}
}