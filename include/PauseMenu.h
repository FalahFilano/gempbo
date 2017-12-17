#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 2


class PauseMenu
{
    public:
        PauseMenu(float Width, float Height);
        ~PauseMenu();

        void draw1(sf::RenderWindow &window);
        void MoveUp1();
        void MoveUp2();
        int GetPressedItem1() { return setPressedItem1;}

    protected:

    private:
    int setPressedItem1;
	sf::Font font;
	sf::Texture texture;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text text;
    sf::Text text1;
    sf::Sprite imageSprite;
};

#endif // PAUSEMENU_H
