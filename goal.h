//
// Created by rezan on 3/18/2021.
//

#ifndef PDCURSES_GOAL_H
#define PDCURSES_GOAL_H
#include "point.h"

class Goal
{
public:
    Goal();
    int getRow();
    int getColumn();
    void setPoint();
private:
    Point point=Point(0,0);

};


#endif //PDCURSES_GOAL_H
