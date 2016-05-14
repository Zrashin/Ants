// Ants.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VisibleObject.h"
#include <list>
#include <iostream>
#include <random>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600,32), "ANTS");
	
	std::list<VisibleObject*> objectList;

	srand(time(NULL));

	while (window.isOpen())
	{	

		sf::Event event;

		while (window.pollEvent(event)) 
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:

				objectList.push_back(new VisibleObject("images/ant.png", event.mouseButton.x, event.mouseButton.y));

				break;

			default:
				break;
			}
		}

		window.clear(sf::Color(0,0,0));

		std::list<VisibleObject*>::iterator iterator;
		for (iterator = objectList.begin(); iterator != objectList.end(); ++iterator) 
		{
			(*iterator)->randomMove('x',(rand()%3)-1);
			(*iterator)->randomMove('y', (rand() % 3) - 1);
			window.draw((*iterator)->getSprite());

		}

		window.display();
	}
    return 0;
}

