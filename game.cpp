#include "game.h"
#include <curses.h>
Game::Game()
{
    cursesInitialization();
    windowInitialization();

    getch();
}
Game::~Game()
{
    endwin();
}
void Game::cursesInitialization()
{
    initscr();
    noecho();
    curs_set(0);
}
void Game::windowInitialization()
{
    mainWindow=newwin(windowHeight,windowWidth,windowStartRow,windowStartColumn);
    keypad(mainWindow,true);
    box(mainWindow,0,0);
    refresh();
    wrefresh(mainWindow);
}
void Game:: input()
{
}