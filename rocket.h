int rocket(int aa, int bb)
{
	int ee, y=aa+8, x=bb+1;
	WINDOW* win;
	WINDOW* win2;
	win2=newwin(49,72,0,0);
	overwrite(stdscr, win2);
	while(ee!=KEY_ENTER)
	{
		overwrite(win2, stdscr);
		attrset(COLOR_PAIR(2));
		mvprintw(y,x+2,"-");
		mvprintw(y,x-2,"-");
		mvprintw(y+1,x,"|");
		mvprintw(y-1,x,"|");
		mvprintw(y,x+10,"-");
		mvprintw(y,x-10,"-");
		mvprintw(y-3,x+6,"\\");
		mvprintw(y-3,x-6,"/");
		mvprintw(y+3,x-6,"\\");
		mvprintw(y+3,x+6,"/");
		refresh();
		ee=getch();
		if(ee==10) ee=KEY_ENTER;
		switch(ee)
		{
			case KEY_UP:
				y--;
				if(y<9) y=9;
				break;
			case KEY_DOWN:
				y++;
				if(y>47) y=47;
				break;
			case KEY_RIGHT:
				x++;
				if(x>70) x=70;
				break;
			case KEY_LEFT:
				x--;
				if(x<2) x=2;
				break;
			case KEY_ENTER:
				overwrite(win2, stdscr);
				refresh();
				mvprintw(y,x+2,"-");
				mvprintw(y,x-2,"-");
				mvprintw(y+1,x,"|");
				mvprintw(y-1,x,"|");
				refresh();
				delay(350);
				overwrite(win2, stdscr);
				refresh();
				mvprintw(y,x+4,"-");
				mvprintw(y,x-4,"-");
				mvprintw(y+2,x,"|");
				mvprintw(y-2,x,"|");
				refresh();
				delay(350);
				overwrite(win2, stdscr);
				refresh();
				mvprintw(y,x+6,"-");
				mvprintw(y,x-6,"-");
				mvprintw(y+3,x,"|");
				mvprintw(y-3,x,"|");
				refresh();
				delay(350);
				overwrite(win2, stdscr);
				refresh();
				delwin(win2);
				//explosion(y-8,x-1,1);
				flash();
				attrset(COLOR_PAIR(1));
				return 0;
				break;
		}
	}
	attrset(COLOR_PAIR(1));
	delwin(win2);
	return 0;
}

