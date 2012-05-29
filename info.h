int info(char tab[1000])
{
	int choice=0, ee, dl, w=7, d=20, dlu, y, x, i, j=0;
	dl=strlen(tab)+2;
	WINDOW *info;

	if(dl<40)
	{
		d=dl+2;
	}
	else if(dl<80)
	{
		d=42;
		w=8;
	}
	else
	{
		d=60;
		w+=modd(dl,d)+1;
	}
	dlu=modd(d,2);

	y=modd(49-w,2);
	x=modd(72-d,2);
	info=newwin(w,d,y,x);
	wattrset(info,COLOR_PAIR(1));
	wborder(info, '|', '|', '-', '-', '.', '.', '*', '*');

	for(i=0; i<=dl-2;i++)
	{	
		if((i)%(d-4)==0) {j++; wmove(info, 1+j, 2);}
		wprintw(info, "%c", tab[i]);
	}


	wmove(info, w-3, dlu-3);
	wprintw(info,"[[OK]]");	
	while(1<2)
	{
		wnoutrefresh(info);
		doupdate();
		ee=getch();
		if(ee==KEY_ENTER || ee==KEY_RIGHT || ee==10) 
		{
			delwin(info);
			return 0;
		}
	}

	return 0;
}

int infon(char tab[1000])
{
	int choice=0, ee, dl, w=7, d=20, dlu, y, x, i, j=0;
	dl=strlen(tab)+2;
	WINDOW *info;

	if(dl<40)
	{
		d=dl+2;
	}
	else if(dl<80)
	{
		d=42;
		w=8;
	}
	else
	{
		d=60;
		w+=modd(dl,d)+1;
	}
	dlu=modd(d,2);

	y=modd(49-w,2);
	x=modd(72-d,2);
	info=newwin(w,d,y,x);
	wattrset(info,COLOR_PAIR(1));
	wborder(info, '|', '|', '-', '-', '.', '.', '*', '*');

	for(i=0; i<=dl-2;i++)
	{	
		if((i)%(d-4)==0) {j++; wmove(info, 1+j, 2);}
		wprintw(info, "%c", tab[i]);
	}


	wmove(info, w-3, dlu-3);
	wprintw(info,"[[OK]]");	

	return 0;
}


