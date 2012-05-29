int warn(char tab[1000])
{
	int choice=0, ee=KEY_UP, dl, w=9, d=20, dlu, y, x, i, j=0;
	dl=strlen(tab)+2;
	WINDOW *warn;

	if(dl<40)
	{
		d=dl+2;
	}
	else if(dl<80)
	{
		d=42;
		w=10;
	}
	else
	{
		d=60;
		w+=modd(dl,d)+1;
	}
	dlu=modd(d,2);

	y=modd(49-w,2);
	x=modd(72-d,2);
	warn=newwin(w,d,y,x);
	wattrset(warn,COLOR_PAIR(2));
	wborder(warn, '|', '|', '-', '-', '.', '.', '*', '*');

	for(i=0; i<=dl-2;i++)
	{	
		if((i)%(d-4)==0) {j++; wmove(warn, 1+j, 2);}
		wprintw(warn, "%c", tab[i]);
	}

	//wprintw(warn, "%s", tab);

	while(1<2)
	{
		wmove(warn, w-5, dlu-3);
		if(ee==KEY_UP) {choice=0; wprintw(warn,"[[OK]]"); mvwprintw(warn, w-3, dlu-5, "  Anuluj  ");}
		if(ee==KEY_DOWN) {choice=1; wprintw(warn,"  OK  "); mvwprintw(warn, w-3, dlu-5, "[[Anuluj]]");}
		if(ee==KEY_ENTER || ee==10)
		{
			delwin(warn);
			refresh();
			return choice;
		}
		refresh();
		wrefresh(warn);
		ee=getch();
		if(ee==KEY_RIGHT) {ee=KEY_ENTER;}
	}
	return 0;
}


