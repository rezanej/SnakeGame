//
// Created by rezan on 3/17/2021.
//

#ifndef PDCURSES_GAME_H
#define PDCURSES_GAME_H
class Game{
public:
    Game();

    ~Game();
    //
private:
    int windowHeight{20},windowWidth{30},windowStartRow{0},windowStartColumn{0};

    void cursesInitialization();

    void windowInitialization();


};
#endif //PDCURSES_GAME_H
