#include "stdafx.h"
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject() { //constructor
	_isLoaded = false;
}

VisibleGameObject::~VisibleGameObject() {

}

void VisibleGameObject::Load(std::string filename) {  //Load texture from file, if successful we create the sprite to load the image
	if(_image.loadFromFile(filename) != true) {
		_filename = "";
		_isLoaded = false;
	}
	else {
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow& renderWindow) { //Draws the sprite if image is loaded
	if(_isLoaded) {
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::SetPosition(float x, float y) { //Sets sprite position to the values provided
	if(_isLoaded) {
		_sprite.setPosition(x, y);
	}
}