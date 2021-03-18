//
// Created by rezan on 3/17/2021.
//

#ifndef PDCURSES_GAME_H
#define PDCURSES_GAME_H
#include <curses.h>
#include "player.h"
#include "goal.h"
#include "score.h"
#include "gameover.h"
class Game{
public:
    Game();

    ~Game();
    //
private:

    int windowHeight{20},windowWidth{30},windowStartRow{0},windowStartColumn{0};
    WINDOW *mainWindow;
    Player snake;
    Score score;
    Goal goal;
    void cursesInitialization();

    void windowInitialization();
    int input();
    void showPlayer();
    void showGoal();
    void showScore();

};
#endif //PDCURSES_GAME_H
