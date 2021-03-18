#include "game.h"
#include <player.h>
Game::Game()
{
    Player snake;
    cursesInitialization();
    windowInitialization();
    showPlayer(snake);
    refresh();
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
void Game::showPlayer( Player snake)
{
    for(int i=0;i<snake.getBody().size()-1;i++)
    {
        mvwprintw(mainWindow, snake.getBody()[i].getRow(), snake.getBody()[i].getColumn(), "o");
    }
        mvwprintw(mainWindow, snake.getBody()[snake.getBody().size()-1].getRow(), snake.getBody()[snake.getBody().size()-1].getColumn(), "O");

    wrefresh(mainWindow);
    refresh();

}