//
// Created by rezan on 3/18/2021.
//

#include "player.h"
#include <random>
#include <ctime>
using std::vector;
vector<Point> Player::getBody() const {
    return body;
}
void Player::move(Direction::directionE direction)
{
    if (direction==Direction::directionE::RIGHT) {
        body.push_back(Point(body[body.size() - 1].getRow(), body[body.size() - 1].getColumn() + 2));
        body.erase(body.begin());
    }
    if (direction==Direction::directionE::UP)
        {
            body.push_back(Point(body[body.size()-1].getRow()-1,body[body.size()-1].getColumn()));
            body.erase(body.begin());
        }
    if (direction==Direction::directionE::LEFT )
    {
        body.push_back(Point(body[body.size()-1].getRow(),body[body.size()-1].getColumn()-2));
        body.erase(body.begin());
    }
    if (direction==Direction::directionE::DOWN)
    {
        body.push_back(Point(body[body.size()-1].getRow()+1,body[body.size()-1].getColumn()));
        body.erase(body.begin());
    }
}
void Player::autoMove()
{
        Sleep(sleepTime);
    move(this->direction);
}
void Player::changeDirection(Direction::directionE direction)
{
    this->direction=direction;
}
void Player::addBody() {
    if (direction==Direction::directionE::DOWN)
    body.push_back(Point(body[body.size()-1].getRow()+1,body[body.size()-1].getColumn()));
    if (direction==Direction::directionE::UP)
    body.push_back(Point(body[body.size()-1].getRow()-1,body[body.size()-1].getColumn()));
    if (direction==Direction::directionE::RIGHT)
    body.push_back(Point(body[body.size()-1].getRow(),body[body.size()-1].getColumn()+2));
    if (direction==Direction::directionE::LEFT)
    body.push_back(Point(body[body.size()-1].getRow(),body[body.size()-1].getColumn()-2));
}
Direction::directionE Player::getDirection() {return direction;}
void Player::setPosition() {
    int row,column;
    srand(time(0));
    row=3+rand()%10;
    column=3+rand()%10;
    if (row%2!=1)
        row++;
    if(column%2!=1)
        column++;
    body.clear();
    for (int i = 0; i <7 ; i+=2) {
        body.push_back(Point(row,column+i));
    }
}
void Player::levelUp() {
    if (sleepTime>150)
        sleepTime-=levelUpRate;
}