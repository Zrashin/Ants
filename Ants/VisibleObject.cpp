#include "StdAfx.h"
#include "VisibleObject.h"


VisibleObject::VisibleObject()
{
	_isLoaded = false;
}


VisibleObject::~VisibleObject()
{
}

void VisibleObject::Load(std::string filename)
{
	if (_texture.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
	_boundingBox = _sprite.getGlobalBounds();
}

void VisibleObject::Draw(sf::RenderWindow & renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}