#include "game.h"
#include <player.h>
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
    cbreak();
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
int Game:: input()
{
    int a=wgetch(mainWindow);
    if (a==KEY_RIGHT) {
        snake.move(Direction::directionE::RIGHT);
        return 1;
    }if (a==KEY_LEFT) {
        snake.move(Direction::directionE::LEFT);
        return 1;
    }if (a==KEY_UP) {
        snake.move(Direction::directionE::UP);
        return 1;
    }if (a==KEY_DOWN) {
        snake.move(Direction::directionE::DOWN);
        return 1;
    }
    else {

        return 0;
    }

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