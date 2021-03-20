//
// Created by rezan on 3/18/2021.
//

#include "score.h"

int Score::getScore() const {
    return score;
}
void Score::checkAddScore(Goal &goal,Player &snake,bool &canlevelUP) {
    if (goal.getRow()==snake.getBody()[snake.getBody().size()-1].getRow()
    && goal.getColumn()==snake.getBody()[snake.getBody().size()-1].getColumn()) {
        score++;
        canlevelUP= true;
        snake.addBody();
        goal.setPoint();
    }

}