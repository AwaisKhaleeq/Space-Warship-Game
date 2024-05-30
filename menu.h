

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
using namespace std;
using namespace sf;

class Menu {
public:
    Texture tex;
    Sprite shape;
    int index;
    int click;
    Text menu[3];
    Font font;

    // Add menu attributes here
    Menu() {
        index = 3; // initialize index to the number of menu options
        click = 0; // initialize click to the first menu option

        if (!font.loadFromFile("tirto.ttf")) {
            // error handling here
            cout << "Error: Font not found!" << endl;
        }

        // set font for all menu options
        for (int i = 0; i < index; i++) {
            menu[i].setFont(font);
        }

        menu[0].setFillColor(Color::Red);
        menu[0].setString("Play");
        menu[0].setPosition(200, 100);

        menu[1].setFillColor(Color::White);
        menu[1].setString("Instructions");
        menu[1].setPosition(200, 200);

        menu[2].setFillColor(Color::White);
        menu[2].setString("Exit");
        menu[2].setPosition(200, 300);
    }

    void moveUp() {
        if (click - 1 >= 0) {
            menu[click].setFillColor(Color::White);
            click--;
            menu[click].setFillColor(Color::Blue);
        }
    }

    void moveDown() {
        if (click + 1 < index) {
            menu[click].setFillColor(Color::White);
            click++;
            menu[click].setFillColor(Color::Blue);
        }
    }

    int getSelected() {
        return click;
    }

    void displayMenu() {
        RenderWindow window(VideoMode(500, 500), "Menu");

        while (window.isOpen()) {
            Event e;
            while (window.pollEvent(e)) {
                if (e.type == Event::Closed) {
                    window.close();
                }

                switch (e.type) {
                case Event::KeyReleased:
                    switch (e.key.code) {
                    case Keyboard::Up:
                        moveUp();
                        break;

                    case Keyboard::Down:
                        moveDown();
                        break;

                    case Keyboard::Return:
                        switch (getSelected()) {
                        case 0:
                            cout << "Play button is pressed" << endl;
                            // Call your play logic here
                            break;

                        case 1:
                            cout << "Instructions button is pressed" << endl;
                            // Display instructions logic
                            break;

                        case 2:
                            cout << "Exit button is pressed" << endl;
                            window.close();
                            break;
                        }
                        break;
                    }
                    break;
                }
            }

            window.clear(Color::Black);

            // Draw all menu options on the window
            for (int i = 0; i < index; i++) {
                window.draw(menu[i]);
            }

            // Display the window
            window.display();
        }
    }
};

    
    /*
    Menu()
    {
        index = 3; // initialize index to the number of menu options
        click = 0; // initialize click to the first menu option
        menu[index];
        if(!font.loadFromFile("tirto.ttf"))
        {
            // error handling here
            cout << "Error: Font not found!" << endl;
        }
        
        // set font for all menu options
        for (int i = 0; i < index; i++) {
            menu[i].setFont(font);
        }
        
        menu[0].setColor(Color::Red);
        menu[0].setString("Play");
        menu[0].setPosition(200,100);

        menu[1].setColor(Color::White);
        menu[1].setString("Instructions");
        menu[1].setPosition(200, 200);

        menu[2].setColor(Color::White);
        menu[2].setString("Exit");
        menu[2].setPosition(200, 300);
        
        //constructors body
    }

    void moveup()
    {
        if(click-1 >= 0)
        {
            menu[click].setColor(Color::White);
            click--;
            menu[click].setColor(Color::Blue);
        }
    }

    void movedown()
    {
        if(click+1 < index)
        {
            menu[click].setColor(Color::White);
            click++;
            menu[click].setColor(Color::Blue);
        }
    }

    int selected()
    {
        return click;
    }

    void display_menu()
    {
        Game g;
        RenderWindow window(VideoMode(440,440), "MENU");
        
        while (window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game 

                switch (e.type)
                {
                    case Event::KeyReleased:
                        switch(e.key.code)
                        {
                            case Keyboard::Up: 
                                moveup();
                                break;

                            case Keyboard::Down: 
                                movedown();
                                break;

                            case Keyboard::Return: 
                                switch (selected())
                                {
                                    case 0:
                                        cout << "Play button is pressed\n";
                                         window.close();
                                        g.start_game();
                                       
                                        break;

                                    case 1:
                                        cout << "Instructions button is pressed\n";
                                        cout << "Press up key to move forward\n";
                                        cout << "Press down key to move backward\n";
                                        cout << "Press right key to move right\n";
                                        cout << "Press left key to move left\n";
                                        break;

                                    case 2:
                                        cout << "Exit button is pressed\n";
                                        window.close();
                                        break;
                                }
                                break;
                        }
                        break;
                }
            }
            
            // Clear the window
            window.clear(Color::Black);
            
            // Draw all menu options on the window
            for (int i = 0; i < index; i++) {
                window.draw(menu[i]);
            }

            // Display the window
            window.display();
        }
    }
};

*/

/*
class Menu {
public:
    Texture tex;
    Sprite shape;
    int index;
    int click;
    Text menu[3];
    Font font;
    Text instructions;

    Menu() {
        index = 3; // initialize index to the number of menu options
        click = 0; // initialize click to the first menu option
        menu[index];
        if (!font.loadFromFile("tirto.ttf")) {
            // error handling here
            cout << "Error: Font not found!" << endl;
        }

        // set font for all menu options
        for (int i = 0; i < index; i++) {
            menu[i].setFont(font);
        }

        menu[0].setColor(Color::Red);
        menu[0].setString("Play");
        menu[0].setPosition(200, 100);

        menu[1].setColor(Color::White);
        menu[1].setString("Instructions");
        menu[1].setPosition(200, 200);

        menu[2].setColor(Color::White);
        menu[2].setString("Exit");
        menu[2].setPosition(200, 300);

        instructions.setFont(font);
        instructions.setColor(Color::White);
        instructions.setString("Press up key to move forward\nPress down key to move backward\nPress right key to move right\nPress left key to move left");
        instructions.setPosition(200, 400);
    }

    void moveup() {
        if (click - 1 >= 0) {
            menu[click].setColor(Color::White);
            click--;
            menu[click].setColor(Color::Blue);
        }
    }

    void movedown() {
        if (click + 1 < index) {
            menu[click].setColor(Color::White);
            click++;
            menu[click].setColor(Color::Blue);
        }
    }

    int selected() {
        return click;
    }

    void display_menu() {
        Game g;
        RenderWindow window(VideoMode(440, 600), "MENU");

        while (window.isOpen()) {
            Event e;
            while (window.pollEvent(e)) {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game 

                switch (e.type) {
                case Event::KeyReleased:
                    switch (e.key.code) {
                    case Keyboard::Up:
                        moveup();
                        break;

                    case Keyboard::Down:
                        movedown();
                        break;

                    case Keyboard::Return:
                        switch (selected()) {
                        case 0:
                            cout << "Play button is pressed\n";
                            window.close();
                            g.start_game();

                            break;

                        case 1:
                            cout << "Instructions button is pressed\n";
                            break;

                        case 2:
                            cout << "Exit button is pressed\n";
                            window.close();
                            break;
                        }
                        break;
                    }
                    break;
                }
            }

            // Clear the window
            window.clear(Color::Black);

            // Draw all menu options on the window
            for (int i = 0; i < index; i++) {
                window.draw(menu[i]);
            }

            if (selected() == 1) {
                window.draw(instructions);
            }

            // Display the window
            window.display();
        }
    }
};



*/

