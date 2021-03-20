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
    row=2+rand()%18;
    column=2+rand()%27;
    if (column%2!=1)
        column--;
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
Goal::Goal(Player &snake) {
   setPoint();
   checkOk(snake);

}
void Goal::checkOk(Player &snake) {
    bool isOk= true;
    for (int i = 0; i < snake.getBody().size(); ++i) {
        if (snake.getBody()[i].getColumn() == this->getColumn()
            && snake.getBody()[i].getRow() == this->getRow()) {
            isOk = false;
            setPoint();

        }
    }
    if (!isOk)
    {
        setPoint();
        checkOk(snake);
    }

}