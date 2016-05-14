#pragma once
#include "stdafx.h"

class VisibleObject
{
public:
	VisibleObject(std::string filename, int x, int y);
	virtual ~VisibleObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);
	virtual std::string getFileName();
	virtual sf::Sprite getSprite();
	virtual void randomMove(char range, int number);

	virtual void SetPosition(float x, float y);

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _filename;
	bool _isLoaded;
	sf::FloatRect _boundingBox;
};