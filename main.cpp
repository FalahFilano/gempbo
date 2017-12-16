#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <cstring>

#include "mainmenu.h"
using namespace sf;
using namespace std;

const int M=20;
const int N=10;

int field[M][N]={0};

struct point{
    int x, y;} a[4],b[4];

int figures[7][4]={
    1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};

void MainMenuFunction()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(W, H), "TRON");
	Menu menu(window.getSize().x, window.getSize().y);

    sf::Texture imageSource;
    if(!imageSource.loadFromFile("title.jpg")) printf("Load Background  Failed\n");
    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);

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
			/*(case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					mainmenu.gerakatas();
					break;

				case sf::Keyboard::Down:
					mainmenu.gerakbawah()
					break;*/
				}
			}

			window.clear();
			mainmenu.layout(window);

			window.display();
		}

}


int main(){

    RenderWindow window(VideoMode(640, 960), "Tetris Kel 3");

    Texture block;
    block.loadFromFile("images/tiles.png");

    Sprite sprite(block);
    sprite.setTextureRect(IntRect(0,0,18,18));

    int dx=0;
    bool rotate=0;
    int colornum=1;

    while(window.isOpen()){
        Event evnt;
        while(window.pollEvent(evnt)){
            if(evnt.type==Event::Closed){
                window.close();
                cout<<"closed"<<endl;
            }
            if(evnt.type==Event::KeyPressed){
                if(evnt.key.code==Keyboard::Up) rotate=true;
                else if(evnt.key.code==Keyboard::Left) dx=-1;
                else if(evnt.key.code==Keyboard::Right) dx=1;
            }
        }

        //move
        for(int i=0;i<4;i++) a[i].x+=dx;

        //rotate
        if(rotate){
            point p=a[1];
            for(int i=0;i<4;i++){
                int x=a[i].y - p.y;
                int y=a[i].x - p.y;
                a[i].x=p.x-x;
                a[i].y=p.y+y;
            }
        }

        int n=3;
        if(a[0].x==0)
            for(int i=0;i<4;i++){
                a[i].x=figures[n][i]%2;
                a[i].y=figures[n][i]/2;
            }

        dx=0;
        rotate=0;

        window.clear(Color::White);
        for(int i=0;i<4;i++){
            sprite.setPosition(a[i].x*18, a[i].y*18);
            window.draw(sprite);
        }

        window.display();
    }

    return 0;
}

int printmenu ()
{
    cout << endl;
    cout << "1. Start The Game" << endl;
    cout << "2. Exit To Desktop" << endl;
}

int mainmenu ()
{
    int choice;
    bool gameOn = true;

    while(gameOn != false)
    {
        cin >> choice;
        if (choice == 1)
        {
            main();
        }

        else if (choice == 2)
        {
            string exit;
            cout << "Are you sure to exit ? (Y/n)" << endl;
            cin >> exit;
            if (exit == 'Y')
            {
                exit(0);
            }
            else if (exit == 'n')
            {
                printmenu();
            }

        }
    }
}
