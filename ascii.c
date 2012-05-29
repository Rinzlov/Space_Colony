#include <ncurses/ncurses.h>
int main()
{
    int menu=1, choice, i, far=5, choice2=0, choice3;
    initscr();




    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attrset(COLOR_PAIR(1));
    keypad(stdscr, TRUE);
    cbreak();
    noecho();

	for(i=0;i<300;i++)
	{
		printw("%i %c    ",i,i);
		if(i%9==0) printw("\n");
	}

 
    getch();
    endwin();
    exit(1);
}
