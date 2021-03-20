//
// Created by rezan on 3/18/2021.
//

#ifndef PDCURSES_PLAYER_H
#define PDCURSES_PLAYER_H
#include <vector>
#include "point.h"
#include "direction.h"
#include <windows.h>
using std::vector;
class Player
{
public:

    vector<Point> getBody()const;
    void move(Direction::directionE);
    void autoMove();
    void changeDirection(Direction::directionE direction);
    void addBody();
    Direction::directionE getDirection();
    void setPosition();
    void levelUp();
private:
    vector<Point> body;
    Direction::directionE direction=Direction::directionE::RIGHT;
    int sleepTime{250};
    int levelUpRate{15};


};


#endif //PDCURSES_PLAYER_H
