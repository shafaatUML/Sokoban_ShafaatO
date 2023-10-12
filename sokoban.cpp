// Copyright [2022] <Shafaat Osmani>
#include "sokoban.hpp"

Sokoban::Sokoban() {
    boxinplace = 0;
    holes = 0;
    boxes = 0;
    if (!wall.loadFromFile("block_06.png")) {
        std::cout << "ERROR";
    }
    if (!ground.loadFromFile("ground_01.png")) {
        std::cout << "ERROR";
    }
    if (!ground_target.loadFromFile("ground_04.png")) {
        std::cout << "ERROR";
    }
    if (!crate.loadFromFile("crate_03.png")) {
       std::cout << "ERROR";
    }
    if (!player_back.loadFromFile("player_08.png")) {
        std::cout << "ERROR";
    }
    if (!player_front.loadFromFile("player_05.png")) {
        std::cout << "ERROR";
    }
    if (!player_left.loadFromFile("player_20.png")) {
        std::cout << "ERROR";
    }
    if (!player_right.loadFromFile("player_17.png")) {
        std::cout << "ERROR";
    }
    if (!font.loadFromFile("PoorStory-Regular.ttf")) {
        std::cout << "ERROR";
    }
    text.setFont(font);
    text.setString("You Won");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
}
double Sokoban::getWidth() {
    return 64 * width;
}
double Sokoban::getHeight() {
    return 64 * height;
}
std::istream& operator >>(std::ifstream& inFile,  Sokoban& sok) {
        int c;
        std::string line;
        inFile >> c;
        sok.width = c;
        inFile >> c;
        sok.height = c;
        std::getline(inFile, line);
        while (std::getline(inFile, line)) {
            sok.vecmap.push_back(line);
        }
        std::for_each(sok.vecmap.begin(), sok.vecmap.end(), [](auto x) {
                    std::cout << x << std::endl;
                });
        for (int i = 0; i < sok.width; i ++) {
            for (int j = 0; j < sok.height; j++) {
                if (sok.vecmap[i][j] == '@') {
                    sok.pX = static_cast<int>(i);
                    sok.pY = static_cast<int>(j);
                } else if (sok.vecmap[i][j] == 'O') {
                    sok.boxes++;
                } else if (sok.vecmap[i][j] == '*') {
                    sok.holes++;
                }
            }
        }
    std::copy(sok.vecmap.begin(), sok.vecmap.end(),
    std::back_inserter(sok.origvec));
    return inFile;
}

std::ostream& operator <<(std::ostream& os,  Sokoban& sok) {
    for (int i = 0; i < sok.width; i ++) {
        for (int j = 0; j < sok.height; j++) {
            os << sok.vecmap[i][j];
        }
        os << std::endl;
    }
    return os;
}

void Sokoban::movePlayer(char direction) {
    int positive;
    if (direction == 'W') {
        if (vecmap[pX-1][pY] != '#') {
            if (vecmap[pX-1][pY] == 'O' &&
            (vecmap[pX - 2][pY] == '#' || vecmap[pX - 2][pY] == 'O')) {
                positive = 0;
            } else if (vecmap[pX - 1][pY] == 'O' && vecmap[pX - 2][pY] == '*') {
                boxinplace++;
                vecmap[pX-2][pY] = 'O';
                positive = 1;
            } else if (vecmap[pX-1][pY] == 'O' && vecmap[pX - 2][pY] != '#') {
                vecmap[pX-2][pY] = 'O';
                positive = 1;
            }
            if (positive) {
                if (origvec[pX][pY] == '*') {
                    vecmap[pX - 1][pY] = '@';
                    vecmap[pX][pY] = '*';
                    pX = pX - 1;
                } else {
                    vecmap[pX - 1][pY] = '@';
                    vecmap[pX][pY] = '.';
                    pX = pX - 1;
                }
            }
        }
    }
    if (direction == 'A') {
        if (vecmap[pX][pY - 1] != '#') {
            if (vecmap[pX][pY - 1] == 'O' &&
            (vecmap[pX][pY - 2] == '#' || vecmap[pX][pY - 2] == 'O')) {
                positive = 0;
            } else if (vecmap[pX][pY - 1] == 'O' && vecmap[pX][pY - 2] == '*') {
                boxinplace++;
                vecmap[pX][pY-2] = 'O';
                positive = 1;
            } else if (vecmap[pX][pY - 1] == 'O' &&
            (vecmap[pX][pY - 2] != '#' || vecmap[pX][pY - 2] != 'O')) {
                vecmap[pX][pY - 2] = 'O';
                positive = 1;
            }
            if (positive) {
                if (origvec[pX][pY] == '*') {
                    vecmap[pX][pY-1] = '@';
                    vecmap[pX][pY] = '*';
                    pY = pY - 1;
                } else {
                    vecmap[pX][pY-1] = '@';
                    vecmap[pX][pY] = '.';
                    pY = pY - 1;
                }
            }
        }
    }
    if (direction == 'S') {
        if (vecmap[pX + 1][pY] != '#') {
            if (vecmap[pX+1][pY] == 'O' &&
            (vecmap[pX+2][pY] == '#' || vecmap[pX+2][pY] == 'O')) {
                positive = 0;
            } else if (vecmap[pX + 1][pY] == 'O' && vecmap[pX + 2][pY] == '*') {
                boxinplace++;
                vecmap[pX + 2][pY] = 'O';
                positive = 1;
            } else if (vecmap[pX + 1][pY] == 'O' &&
            (vecmap[pX + 2][pY] != '#' || vecmap[pX + 2][pY] != 'O')) {
                vecmap[pX + 2][pY] = 'O';
                positive = 1;
            }
            if (positive) {
                if (origvec[pX][pY] == '*') {
                    vecmap[pX + 1][pY] = '@';
                    vecmap[pX][pY] = '*';
                    pX = pX + 1;
                } else {
                    vecmap[pX + 1][pY] = '@';
                    vecmap[pX][pY] = '.';
                    pX = pX + 1;
                }
            }
        }
    }
    if (direction == 'D') {
        if (vecmap[pX][pY + 1] != '#') {
            if (vecmap[pX][pY+1] == 'O' &&
            (vecmap[pX][pY+2] == '#' || vecmap[pX][pY+2] == 'O')) {
                positive = 0;
            } else if (vecmap[pX][pY + 1] == 'O' && vecmap[pX][pY + 2] == '*') {
                boxinplace++;
                vecmap[pX][pY + 2] = 'O';
                positive = 1;
            } else if (vecmap[pX][pY + 1] == 'O' &&
            (vecmap[pX][pY + 2] != '#' || vecmap[pX][pY + 2] == 'O')) {
                vecmap[pX][pY + 2] = 'O';
                positive = 1;
            }
            if (positive) {
                if (origvec[pX][pY] == '*') {
                    vecmap[pX][pY + 1] = '@';
                    vecmap[pX][pY] = '*';
                    pY = pY + 1;
                } else {
                    vecmap[pX][pY + 1] = '@';
                    vecmap[pX][pY] = '.';
                    pY = pY + 1;
                }
            }
        }
    }
}

bool Sokoban::isWon() const {
    if (boxes < holes) {
        if (boxinplace == boxes) {
            return true;
        }
    } else {
        if (boxinplace == holes) {
            return true;
        }
    }
    return false;
}

void Sokoban::reset() {
    boxinplace = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            vecmap[i][j] = origvec[i][j];
            if (vecmap[i][j] == '@') {
                pX = static_cast<int>(i);
                pY = static_cast<int>(j);
            }
        }
    }
}
