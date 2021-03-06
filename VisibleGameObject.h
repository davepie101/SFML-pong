#pragma once
class VisibleGameObject {

public:
	VisibleGameObject();
	virtual ~VisibleGameObject(); //Virtual functions - runtime polymorphism base function is overridden

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow& window);

	virtual void SetPosition(float x, float y);


private:
	sf::Sprite _sprite;
	sf::Texture _image;

	std::string _filename;
	bool _isLoaded;
};