//
// Created by rezan on 3/18/2021.
//

#ifndef PDCURSES_SCORE_H
#define PDCURSES_SCORE_H

#include "goal.h"
#include "player.h"
class Score
{
private:
    int score{0};

public:
    int getScore()const;
    void checkAddScore(Goal&,Player&);
};


#endif //PDCURSES_SCORE_H
