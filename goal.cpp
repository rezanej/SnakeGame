//
// Created by rezan on 3/18/2021.
//

#include "goal.h"
#include <random>
#include <ctime>
void Goal::setPoint()
{

    srand(time(0));
    int row,column;
    row=1+rand()%19;
    column=1+rand()%29;
    point.setRow(row);
    point.setColumn(column);
}
int Goal::getRow()
{
    return this->point.getRow();
}
int Goal::getColumn()
{
    return this->point.getColumn();
}
Goal::Goal() {
    setPoint();
}