#include "game.h"
#include <player.h>
#include <windows.h>
#include "direction.h"
Game::Game()
{

    cursesInitialization();
    windowInitialization();
    showPlayer(snake);
    while (true)
    {
        if (input()==0)
            break;
        wclear(mainWindow);
        box(mainWindow,0,0);
        snake.autoMove();
        showPlayer(snake);

        wrefresh(mainWindow);
        refresh();
    }
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
    nodelay(mainWindow,true);
}
int Game:: input()
{

    int a=wgetch(mainWindow);
    if (a==KEY_RIGHT) {
        snake.changeDirection(Direction::directionE::RIGHT);
        return 1;
    }else if (a==KEY_LEFT) {
        snake.changeDirection(Direction::directionE::LEFT);
        return 1;
    }else if (a==KEY_UP) {
        snake.changeDirection(Direction::directionE::UP);
        return 1;
    }else if (a==KEY_DOWN) {
        snake.changeDirection(Direction::directionE::DOWN);
        return 1;
    }
    else if(a=='q') {

        return 0;
    }
    else return 5;

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
