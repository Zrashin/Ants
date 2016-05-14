#include "StdAfx.h"
#include "VisibleObject.h"
#include <iostream>
#include <random>

VisibleObject::VisibleObject(std::string filename, int x, int y)
{
	_isLoaded = false;
	Load(filename);
	SetPosition(x, y);
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

std::string VisibleObject::getFileName()
{
	return _filename;
}

sf::Sprite VisibleObject::getSprite()
{
	return _sprite;
}

void VisibleObject::randomMove(char range, int value)
{

	sf::Vector2f pos = _sprite.getPosition();
	if (range =='x') 
	{
		pos.x += value;
	}
	else 
	{
		pos.y += value;
	}
	_sprite.setPosition(pos);
}