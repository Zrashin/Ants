#pragma once
#include "stdafx.h"

class VisibleObject
{
public:
	VisibleObject();
	virtual ~VisibleObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);

	virtual void SetPosition(float x, float y);

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _filename;
	bool _isLoaded;
	sf::FloatRect _boundingBox;
};