// Copyright [2022] <Shafaat Osmani>
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Sokoban : public sf::Drawable {
 public:
    Sokoban();
    void movePlayer(char direction);
    friend std::istream& operator >>(std::ifstream& inFile,  Sokoban& sok);
    friend std::ostream& operator <<(std::ostream& os,  Sokoban& sok);

    double getWidth();
    double getHeight();

    bool isWon() const;
    void reset();

 private:
    std::vector<std::string> vecmap;
    std::vector<std::string> origvec;
    double width, height;
    sf::Texture wall;
    sf::Texture ground;
    sf::Texture ground_target;
    sf::Texture crate;
    int pX;
    int pY;
    int boxinplace;
    int boxes;
    int holes;
    sf::Texture player_front;
    sf::Texture player_left;
    sf::Texture player_right;
    sf::Texture player_back;
    sf::Font font;
    sf::Text text;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        sf::Sprite draw_me;
        for (int i = 0; i < width; i ++) {
            for (int j = 0; j < height; j++) {
            if (vecmap[i][j] == '#') {
                draw_me.setTexture(wall);
            } else if (vecmap[i][j] == 'O') {
                draw_me.setTexture(ground);
            } else if (vecmap[i][j] == '.') {
                draw_me.setTexture(ground);
            } else if (vecmap[i][j] == '*') {
                draw_me.setTexture(ground_target);
            } else if (vecmap[i][j] == '@') {
                draw_me.setTexture(ground);
            } else if (vecmap[i][j] == '\n') {
                continue;
            }

            if (height != width) {
                draw_me.setPosition(i*64, j*64);
            } else {
                draw_me.setPosition(j*64, i*64);
            }

            target.draw(draw_me);

            if (vecmap[i][j] == '@') {
                draw_me.setTexture(player_front);
                target.draw(draw_me);
            }
            if (vecmap[i][j] == 'O') {
                draw_me.setTexture(crate);
                target.draw(draw_me);
            }
            }
            if (isWon()) {
                target.draw(text);
            }
        }
    }
};
