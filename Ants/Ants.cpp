// Ants.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VisibleObject.h"
#include <list>

int main()
{
	sf::Window window(sf::VideoMode(800,600), "ANTS");
	
	std::list<VisibleObject> objectList;


	while (window.isOpen())
	{	

		sf::Event event;
		
		while (window.pollEvent(event)) 
		{
			VisibleObject ant;
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:

				ant.Load("images/ant.png");
				ant.SetPosition(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
				objectList.push_back(ant);

				break;

			default:
				break;
			}
		}
	}
    return 0;
}

