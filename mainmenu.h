#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 2

class mainmenu
{
    public:
        mainmenu(float width, float weight);
        virtual ~mainmenu();

        void layout(sf::RenderWindow &window);
        void gerakatas();
        void gerakbawah();
        void GetSelectedItem ( return SelectedItemIndex);
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
