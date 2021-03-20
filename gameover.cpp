//
// Created by rezan on 3/18/2021.
//

#include "gameover.h"

bool GameOver::checkGameover(Player snake, int height, int width)
{
    for(int i=0;i<snake.getBody().size();i++)
    {
    for (int j = 0; j <snake.getBody().size()  ; ++j) {
        if (i !=j)
            if ((snake.getBody()[i].getRow()==snake.getBody()[j].getRow()
            && snake.getBody()[i].getColumn()==snake.getBody()[j].getColumn())
            || snake.getBody()[j].getRow()<1 ||snake.getBody()[j].getRow()>height-2
               || snake.getBody()[j].getColumn()>width-2
               ||snake.getBody()[j].getColumn()<0
               )
                return true;
    }
    }
    return false;
}