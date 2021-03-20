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

    //
private:

    int windowHeight{21},windowWidth{31},windowStartRow{0},windowStartColumn{1};
    int level{1};
    int levelupRate{5};
    bool canLevelUp= true;
    WINDOW *mainWindow;
    Player snake;
    Score score;
    Goal goal=Goal(snake);

    void cursesInitialization();

    void windowInitialization();
    int input();
    void showPlayer();
    void showGoal();
    void showScore();
    void levelUp();
    void initColors();
};
#endif //PDCURSES_GAME_H
