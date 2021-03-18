//
// Created by rezan on 3/17/2021.
//

#ifndef PDCURSES_GAME_H
#define PDCURSES_GAME_H
#include <curses.h>
#include "player.h"
class Game{
public:
    Game();

    ~Game();
    //
private:
    int windowHeight{20},windowWidth{30},windowStartRow{0},windowStartColumn{0};
    WINDOW *mainWindow;
    void cursesInitialization();

    void windowInitialization();
    void input();
    void logic();
    void showPlayer(Player);

};
#endif //PDCURSES_GAME_H
