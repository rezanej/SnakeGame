#include <curses.h>
class Game{
public:
    Game(){
        cursesInitialization();
        windowInitialization();
    }
    ~Game()
    {
        endwin();
    }

private:
    //
    int windowHeight{20},windowWidth{30},windowStartRow{0},windowStartColumn{0};
    //
    void cursesInitialization()
    {
        initscr();
        noecho();
        curs_set(0);
    }
    //
    void windowInitialization()
    {
        WINDOW *mainWindow=newwin(windowHeight,windowWidth,windowStartRow,windowStartColumn);
        keypad(mainWindow,true);
        box(mainWindow,0,0);
    }
    //

};

int main()
{


    return 0;
}