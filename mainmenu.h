#ifndef MAINMENU_H
#define MAINMENU_H
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 2


class MainMenu
{
    public:
     MainMenu(float width, float height);
	~MainMenu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

    protected:

    private:
    int selectedItemIndex;
	sf::Font font;
	sf::Texture texture;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text text;
    sf::Text text1;
    sf::Sprite imageSprite;
};

#endif // MAINMENU_H

