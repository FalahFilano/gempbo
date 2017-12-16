#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

#include "mainmenu.h"
using namespace sf;
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");
	MainMenu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
                        cout << "Play has been pressed" << endl;
						break;
					case 1:
						window.close();
						break;
					}

					break;
				}

				break;
                case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
		menu.draw(window);
		window.display();
	}
}
