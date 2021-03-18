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
private:
    vector<Point> body{Point(5,3),Point(5,5),Point(5,7)};
    Direction::directionE direction=Direction::directionE::RIGHT;

};


#endif //PDCURSES_PLAYER_H
