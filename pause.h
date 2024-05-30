#ifndef PAUSE_H
#define PAUSE_H

#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

class Pause {
public:
    int index, click;
    sf::Font font;
    sf::Text arr[3];
    std::stringstream ss;
    sf::Sprite background;
    sf::Texture bg_texture;

    Pause() {
        index = 3;
        click = 0;

        if (!font.loadFromFile("Pain Circus.ttf")) {
            std::cout << "Error: Font not found!" << std::endl;
        }

        for (int i = 0; i < index; i++) {
            arr[i].setFont(font);
            arr[i].setCharacterSize(24);
        }

        arr[0].setFillColor(sf::Color::Red);
        arr[0].setString("Resume");
        arr[0].setPosition(200, 100);

        arr[1].setFillColor(sf::Color::White);
        arr[1].setString("Restart");
        arr[1].setPosition(200, 200);

        arr[2].setFillColor(sf::Color::White);
        arr[2].setString("Score: ");
        arr[2].setPosition(200, 300);
    }

    void moveUp() {
        if (click - 1 >= 0) {
            arr[click].setFillColor(sf::Color::White);
            click--;
            arr[click].setFillColor(sf::Color::Blue);
        }
    }

    void moveDown() {
        if (click + 1 < index) {
            arr[click].setFillColor(sf::Color::White);
            click++;
            arr[click].setFillColor(sf::Color::Blue);
        }
    }

    int getSelected() {
        return click;
    }

    void displayPause() {
        sf::RenderWindow window(sf::VideoMode(500, 500), "Pause", sf::Style::Close);

        while (window.isOpen()) {
            sf::Event e;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed)
                    window.close();

                if (e.type == sf::Event::KeyReleased) {
                    switch (e.key.code) {
                    case sf::Keyboard::Up:
                        moveUp();
                        break;

                    case sf::Keyboard::Down:
                        moveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (getSelected()) {
                        case 0:
                            std::cout << "Game Resumed\n";
                            window.close();
                            // Resume game logic
                            break;

                        case 1:
                            std::cout << "Game Restart\n";
                            window.close();
                            // Restart game logic
                            break;

                        case 2:
                            std::cout << "Score: \n";
                            // Display score logic
                            break;
                        }
                        break;
                    }
                }
            }

            window.clear(sf::Color::Black);

            for (int i = 0; i < index; i++) {
                window.draw(arr[i]);
            }

            window.display();
        }
    }
};

#endif
