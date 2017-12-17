#include "PauseMenu.h"

PauseMenu::~PauseMenu()
{
    //dtor
}
PauseMenu::PauseMenu(float Width, float Height)
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
    menu[0].setString("Resume");
    menu[0].setPosition(sf::Vector2f(Width / 2, Height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Restart");
    menu[1].setPosition(sf::Vector2f(Width / 2, Height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    setPressedItem1 = 0;
}

void PauseMenu::draw1(sf::RenderWindow& window)
{
    window.draw(text);
    window.draw(text1);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setCharacterSize(20);
        window.draw(menu[i]);
    }
}

void PauseMenu::MoveUp1()
{
        if (setPressedItem1 - 1 >= 0)
    {
        menu[setPressedItem1].setColor(sf::Color::White);
        setPressedItem1--;
        menu[setPressedItem1].setColor(sf::Color::Red);
    }
}

void PauseMenu::MoveUp2()
{
        if (setPressedItem1 + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[setPressedItem1].setColor(sf::Color::White);
        setPressedItem1++;
        menu[setPressedItem1].setColor(sf::Color::Red);
    }
}
