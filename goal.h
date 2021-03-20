//
// Created by rezan on 3/18/2021.
//

#ifndef PDCURSES_GOAL_H
#define PDCURSES_GOAL_H
#include "point.h"
#include "player.h"
class Goal
{
public:
    Goal(Player&);
    int getRow();
    int getColumn();
    void setPoint();
private:
    Point point=Point(0,0);
    void checkOk(Player &);

};


#endif //PDCURSES_GOAL_H
