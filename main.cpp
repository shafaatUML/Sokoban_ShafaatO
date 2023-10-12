// Copyright [2022] <Shafaat Osmani>
#include <iostream>
#include "sokoban.hpp"

int main(int argc, char* argv[]) {
    std::ifstream inFile;
    inFile.open(argv[1]);
    Sokoban sok;
    inFile >> sok;

    sf::RenderWindow window
    (sf::VideoMode(sok.getWidth(), sok.getHeight()), "Sokoban");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                while (!sok.isWon()) {
                if (event.key.code == sf::Keyboard::W) {
                    sok.movePlayer('W');
                    break;
                }
                if (event.key.code == sf::Keyboard::A) {
                    sok.movePlayer('A');
                    break;
                }
                if (event.key.code == sf::Keyboard::S) {
                    sok.movePlayer('S');
                    break;
                }
                if (event.key.code == sf::Keyboard::D) {
                    sok.movePlayer('D');
                    break;
                }
                }
                if (event.key.code == sf::Keyboard::R) {
                    sok.reset();
                    break;
                }
            }
            window.clear();
            window.draw(sok);
            window.display();
        }
    }
}
