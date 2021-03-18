//
// Created by rezan on 3/18/2021.
//

#ifndef PDCURSES_PLAYER_H
#define PDCURSES_PLAYER_H
#include <vector>
#include "point.h"
using std::vector;
class Player
{
public:
    vector<Point> getBody()const;
private:
    vector<Point> body{Point(5,3),Point(5,4),Point(5,5)};

};


#endif //PDCURSES_PLAYER_H
