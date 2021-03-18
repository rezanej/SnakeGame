//
// Created by rezan on 3/18/2021.
//

#include "player.h"

using std::vector;
vector<Point> Player::getBody() const {
    return body;
}
void Player::move(Direction::directionE direction)
{
    if (direction==Direction::directionE::RIGHT) {
        body.push_back(Point(body[body.size() - 1].getRow(), body[body.size() - 1].getColumn() + 1));
        body.erase(body.begin());
    }
    if (direction==Direction::directionE::UP)
        {
            body.push_back(Point(body[body.size()-1].getRow()-1,body[body.size()-1].getColumn()));
            body.erase(body.begin());
        }
    if (direction==Direction::directionE::LEFT)
    {
        body.push_back(Point(body[body.size()-1].getRow(),body[body.size()-1].getColumn()-1));
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
    if (direction==Direction::directionE::RIGHT ||direction==Direction::directionE::LEFT)
        Sleep(100);
    else
        Sleep(200);
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
    body.push_back(Point(body[body.size()-1].getRow(),body[body.size()-1].getColumn()+1));
    if (direction==Direction::directionE::LEFT)
    body.push_back(Point(body[body.size()-1].getRow(),body[body.size()-1].getColumn()-1));
}