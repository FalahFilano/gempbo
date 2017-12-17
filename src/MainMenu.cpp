#include "MainMenu.h"

MainMenu::~MainMenu()
{
    //dtor
}
MainMenu::MainMenu(float width, float height)
{
    if (!font.loadFromFile("Geforce Bold.ttf"))
	{
		// handle error
	}

    imageSprite.setTexture(texture);

	/*text.setFont(font);
	text.setColor(sf::Color::Cyan);
	text.setString(" ");
    text1.setFont(font);
    text1.setCharacterSize(15);
	text1.setColor(sf::Color::White);
	text1.setPosition(420,650);*/

    menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Exit To Desktop");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

void MainMenu::draw(sf::RenderWindow& window)
{
    window.draw(text);
    window.draw(text1);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
        menu[i].setCharacterSize(20);
		window.draw(menu[i]);
	}
}

void MainMenu::MoveUp()
{
    	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void MainMenu::MoveDown()
{
    	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}
