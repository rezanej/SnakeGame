#include "game.h"
Game::Game()
{
    cursesInitialization();
    windowInitialization();
    initColors();
    snake.setPosition();
    while (true)
    {

        switch (input()) {

            case 2: {
                while (true) {
                    nodelay(mainWindow, false);
                    mvwprintw(mainWindow, 5, 4, "PAUSE");
                    mvwprintw(mainWindow, 6, 4, "PRESS P  FOR RESUME");
                    mvwprintw(mainWindow, 7, 4, "PRESS Q  FOR QUIT");
                    mvwprintw(mainWindow, 8, 4, "PRESS R  FOR RESTART");
                    wrefresh(mainWindow);
                    refresh();
                    int a = wgetch(mainWindow);
                    nodelay(mainWindow,true);
                    if (a == int('p'))
                        break;
                    if (a == int('r'))
                        Game();
                    if (a == int('q'))
                        exit(0);

                }
            }
        }
        if (GameOver::checkGameover(snake,windowHeight,windowWidth))
            break;

        wclear(mainWindow);
        box(mainWindow,0,1);
        snake.autoMove();
        showPlayer();
        showGoal();
        score.checkAddScore(goal,snake,canLevelUp);

        showScore();
        levelUp();
        wrefresh(mainWindow);
        refresh();
    }
    mvwprintw(mainWindow, 5, 4, "GAME OVER");
    mvwprintw(mainWindow, 6, 4, "PRESS R FOR RESTART");
    mvwprintw(mainWindow, 7, 4, "PRESS Q FOR QUIT");
    wrefresh(mainWindow);
    while (true) {
        int a = getch();
        if (a == int('r'))
            Game();
        else if (a == int('q'))
            exit(0);
    }
    endwin();
}

void Game::cursesInitialization()
{
    initscr();
    noecho();
    curs_set(0);
    clear();

}
void Game::windowInitialization()
{
    mainWindow=newwin(windowHeight,windowWidth,windowStartRow,windowStartColumn);
    keypad(mainWindow,true);
    box(mainWindow,0,1);
    refresh();
    wrefresh(mainWindow);
    nodelay(mainWindow,true);
}
int Game:: input()
{

    int a=wgetch(mainWindow);
    if (a==KEY_RIGHT&&snake.getDirection()!=Direction::directionE::LEFT) {
        snake.changeDirection(Direction::directionE::RIGHT);
        return 1;
    }else if (a==KEY_LEFT&&snake.getDirection()!=Direction::directionE::RIGHT) {
        snake.changeDirection(Direction::directionE::LEFT);
        return 1;
    }else if (a==KEY_UP&&snake.getDirection()!=Direction::directionE::DOWN) {
        snake.changeDirection(Direction::directionE::UP);
        return 1;
    }else if (a==KEY_DOWN&&snake.getDirection()!=Direction::directionE::UP) {
        snake.changeDirection(Direction::directionE::DOWN);
        return 1;
    }
    else if(a=='q') {
        exit(0);
    }
    else if (a=='p')return 2;
    else if(a=='r')
        Game();
    return 8;
}
void Game::showPlayer()
{

    for(int i=0;i<snake.getBody().size()-1;i++)
    {
        wattron(mainWindow,COLOR_PAIR(1));
        mvwprintw(mainWindow, snake.getBody()[i].getRow(), snake.getBody()[i].getColumn(), "O");
        wattroff(mainWindow,COLOR_PAIR(1));
    }
    wattron(mainWindow,COLOR_PAIR(2));
    mvwprintw(mainWindow, snake.getBody()[snake.getBody().size()-1].getRow(), snake.getBody()[snake.getBody().size()-1].getColumn(), "Q");
    wattroff(mainWindow,COLOR_PAIR(2));
    wrefresh(mainWindow);
    refresh();

}
void Game::showGoal()
{
    wattron(mainWindow,COLOR_PAIR(3));

    mvwprintw(mainWindow,goal.getRow(),goal.getColumn(),"#");

    wattroff(mainWindow,COLOR_PAIR(3));
}
void Game::showScore() {
    mvwprintw(stdscr,1,33,"LEVEL : %d",level);
    mvwprintw(stdscr,2,33,"SCORE: %d",score.getScore());
    mvwprintw(stdscr,3,33,"PRESS Q FOR QUIT");
    mvwprintw(stdscr,4,33,"PRESS P FOR PAUSE");
    mvwprintw(stdscr,5,33,"PRESS R FOR RESTART");

    wrefresh(stdscr);
}
void Game::levelUp() {
    if (score.getScore()%levelupRate==0 &&score.getScore()!=0 &&canLevelUp) {
        snake.levelUp();
        level++;
        canLevelUp= false;
    }
}
void Game::initColors() {
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(3,COLOR_GREEN,COLOR_BLACK);
}