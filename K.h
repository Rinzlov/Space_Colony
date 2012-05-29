int K(float ilosc, char name[100])
{
	printw("%s", name);
	if(ilosc>=10000000) printw("%0.0fM", ilosc/1000000);
	else if(ilosc>=1000000) printw("%0.1fM", ilosc/1000000);
	else if(ilosc>=10000) printw("%0.0fK", ilosc/1000);
	else if(ilosc>=1000) printw("%0.1fK", ilosc/1000);
	else printw("%0.0f", ilosc);
}

int wK(WINDOW *win, float ilosc, char name[100])
{
	wprintw(win, "%s", name);
		// if(ilosc>=10000000000) wprintw(win, " %0.1f", ilosc/1000000000);
		if(ilosc>=1000000000) wprintw(win, "%0.0fM", ilosc/1000000);
	else if(ilosc>=100000000) wprintw(win, "% 0.0fM", ilosc/1000000);
	else if(ilosc>=10000000) wprintw(win, "%0.1fM", ilosc/1000000);
	else if(ilosc>=1000000) wprintw(win, "%0.0fK", ilosc/1000);
	else if(ilosc>=100000) wprintw(win, " %0.0fK", ilosc/1000);
	else if(ilosc>=10000) wprintw(win, "%0.1fK", ilosc/1000);
	else if(ilosc>=1000) wprintw(win, "%0.0f", ilosc);
	else if(ilosc>=100) wprintw(win, " %0.0f", ilosc);
	else if(ilosc>=10) wprintw(win, "  %0.0f", ilosc);
	else if(ilosc>=0) wprintw(win, "   %0.0f", ilosc);
}
	
/*if(ilosc>=10000000)
	{
		if(ilosc>99999999) wprintw(win, "%0.0fM", ilosc/1000000);
		else wprintw(win, " %0.0fM", ilosc/1000000);
	}
	else if(ilosc>=1000000) wprintw(win, "%0.1fM", ilosc/1000000); // 1 000 000 - 9 999 999
	else if(ilosc>=999) // 999-999 999
	{
		if(ilosc>99999)  wprintw(win, " %0.0fK", ilosc/1000);
		else if(ilosc>9999)  wprintw(win, "  %0.0fK", ilosc/1000);
		else  wprintw(win, "  %0.0fK", ilosc/1000);
	}
	else if(ilosc>=1000) wprintw(win, "%  0.1fK", ilosc/1000); // 1000-9999
	else
	{
		if(ilosc>99) wprintw(win, " %0.0f", ilosc);
		else if(ilosc>10) wprintw(win, "  %0.0f", ilosc);
		else wprintw(win, "   %0.0f", ilosc);
	}*/
	
