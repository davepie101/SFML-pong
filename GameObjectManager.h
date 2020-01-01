#pragma once
#include "VisibleGameObject.h"

class GameObjectManager{

public:
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, VisibleGameObject* gameObject); //Adds a gameObject to our collection
	void Remove(std::string name); //Removes the pointer object we're looking for
	int GetObjectCount() const; //Returns the number of objects in our collection
	VisibleGameObject* Get(std::string name) const; //name is the identifier for our map. Obtain the pointer object we're looking for

	void DrawAll(sf::RenderWindow& renderWindow); //Draws all the VisibleGameObjects in our collection

private:
	std::map<std::string, VisibleGameObject*> _gameObjects; //Collection of VisibileGameObject pointers, the string is the identifier for our map

	struct GameObjectDeallocator { 
		void operator()(const std::pair<std::string, VisibleGameObject*> &p) const { //Functor. Created by overloading the () operator. 
			delete p.second;
		}
	};
};