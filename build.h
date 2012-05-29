int bField(char tab[40][70], int aa, int bb, int ry, int rx)
{
	int i,j;
	for(i=0; i<ry; i++)
	{
		for(j=0; j<rx; j++)
		{
			attrset(COLOR_PAIR(3)); 
			mvprintw(aa+8-i,bb+1+j, "|");
			attrset(COLOR_PAIR(1)); 
			rdelay(35);
			if(tab[aa-i][bb+j]!=' ') {return 0;}
		}
	}
	return 1;

}

int bAim(WINDOW *aim, PANEL *pan, int ry, int rx, int *aa, int *bb)
{
	int ee, y=*aa, x=*bb, i;
	WINDOW *map;
	map=newwin(40,70,8,1);
	overwrite(aim, map);
	while(1<2)
	{
		overwrite(map,aim);
		wattrset(aim, COLOR_PAIR(4)); 
		for(i=0;i<rx;i++)
		{
			mvwprintw(aim, y,x+i, "-");
			mvwprintw(aim, y-(ry-1),x+i, "-");
		}
		for(i=0;i<ry;i++)
		{
			mvwprintw(aim, y-i,x, "|");
			mvwprintw(aim, y-i,x+(rx-1), "|");
		}
		mvwprintw(aim, y,x,"*");
		mvwprintw(aim, y-(ry-1),x+(rx-1),"*");
		mvwprintw(aim, y,x+(rx-1),"*");
		mvwprintw(aim, y-(ry-1),x,"*");
		wattrset(aim, COLOR_PAIR(1)); 
		show_panel(pan);
		top_panel(pan);
		update_panels();
		refresh();
		ee=getch();
		if(ee==10) ee=KEY_ENTER;
		switch(ee)
		{
			case KEY_UP:
				y--;
				if(y<1+(ry-1)) y=1+(ry-1);
				break;
			case KEY_DOWN:
				y++;
				if(y>38) y=38;
				break;
			case KEY_RIGHT:
				x++;
				if(x>68-(rx-1)) x=68-(rx-1);
				break;
			case KEY_LEFT:
				x--;
				if(x<1) x=1;
				break;
			case KEY_ENTER:
				if(/*warn("Czy na pewno chcesz zbudowac ten budynek?")*/0==0)
				{
					*aa=y;
					*bb=x;
					overwrite(map,aim);
					delwin(map);
					return 1;
				}
				overwrite(map,aim);
				delwin(map);
				return 0;
				break;
		}
	}
	return 0;
}

int bSurowce(int type)
{
	return 1;
	/*switch(type)
	{
		case 1:
			if(surowce>=wymagania) return 1;
			else return 0;
			break;
	}
	return 0;*/
}

void bAnimation(type, aa, bb)
{
	int y=aa+8, c=bb+1;
	switch(type)
	{	
		case 1:

			break;
	}
		
}

int bWybierztyp()
{
	WINDOW *undermenu, *win2;
	int choice2=1, choice3;
	attrset(COLOR_PAIR(4)); 
	win2=newwin(49,72,0,0);
	overwrite(stdscr, win2);
	undermenu=newwin(13,24,18,24);
	wattrset(undermenu,COLOR_PAIR(1));
	while(1<2)
	{
		mvwprintw(undermenu, 2, 4, "Wybierz budynek.");
		wborder(undermenu, '|', '|', '-', '-', '.', '.', '*', '*');
		wmove(undermenu, 4, 2);
		if(choice2==0) wprintw(undermenu,"[[Anuluj.]]");
		else wprintw(undermenu, "  Anuluj.  ");

		wmove(undermenu, 6, 2);
		if(choice2==1) wprintw(undermenu, "[[Teleporter.]]");
		else wprintw(undermenu, "  Teleporter.  ");

		wmove(undermenu, 8, 2);
		if(choice2==2) wprintw(undermenu,"[[Generator.]]");
		else  wprintw(undermenu,"  Generator.  ");
						
		wmove(undermenu, 10, 2);
		if(choice2==3) wprintw(undermenu,"[[Panel sloneczny.]]");
		else wprintw(undermenu, "  Panel sloneczny.  ");

		wrefresh(undermenu);
		choice3=getch();
		if(choice3==KEY_RIGHT || choice3==10) choice3=KEY_ENTER;
		switch(choice3)
		{
		case KEY_UP:
			choice2-=1;
			if(choice2<0){choice2=3;}
			break;
		case KEY_DOWN:
			choice2+=1;
			if(choice2>3){choice2=0;}
			break;
		case KEY_ENTER:
			delwin(undermenu);
			overwrite(win2,stdscr);
			delwin(win2);
			redrawwin(stdscr);
			refresh();
			attrset(COLOR_PAIR(1)); 
			return choice2;
			break;
		}
		wrefresh(undermenu);
		refresh();
	}
}

int bWybierztypRes()
{
	WINDOW *undermenu, *win2;
	int choice2=1, choice3;
	attrset(COLOR_PAIR(4)); 
	win2=newwin(49,72,0,0);
	overwrite(stdscr, win2);
	undermenu=newwin(13,24,18,24);
	wattrset(undermenu,COLOR_PAIR(1));
	while(1<2)
	{
		mvwprintw(undermenu, 2, 4, "Wybierz budynek.");
		wborder(undermenu, '|', '|', '-', '-', '.', '.', '*', '*');
		wmove(undermenu, 4, 2);
		if(choice2==0) wprintw(undermenu,"[[Anuluj.]]");
		else wprintw(undermenu, "  Anuluj.  ");

		wmove(undermenu, 6, 2);
		if(choice2==1) wprintw(undermenu, "[[Mala kopalnia.]]");
		else wprintw(undermenu, "  Mala kopalnia.  ");

		wmove(undermenu, 8, 2);
		if(choice2==2) wprintw(undermenu,"[[Duza kopalnia.]]");
		else  wprintw(undermenu,"  Duza kopalnia.  ");
						
		wmove(undermenu, 10, 2);
		if(choice2==3) wprintw(undermenu,"[[Wieza wiertnicza.]]");
		else wprintw(undermenu, "  Wieza wiertnicza.  ");

		wrefresh(undermenu);
		choice3=getch();
		if(choice3==KEY_RIGHT || choice3==10) choice3=KEY_ENTER;
		switch(choice3)
		{
		case KEY_UP:
			choice2-=1;
			if(choice2<0){choice2=3;}
			break;
		case KEY_DOWN:
			choice2+=1;
			if(choice2>3){choice2=0;}
			break;
		case KEY_ENTER:
			delwin(undermenu);
			overwrite(win2,stdscr);
			delwin(win2);
			redrawwin(stdscr);
			refresh();
			attrset(COLOR_PAIR(1)); 
			return choice2;
			break;
		}
		wrefresh(undermenu);
		refresh();
	}
}

int build(WINDOW *mapa, PANEL *pan, char tab[40][70], int typ, int resources[40][70])
{
	int y=rob.aa, x=rob.bb, rx=7, ry=3, i, j, type, mine=0;
	FILE *budynek;
	char nazwa[50], wyglad[42][72], a, buff[100];
	if(typ==1)
	{
		type=bWybierztyp(); // 1-teleport 2-generator 3-panel sloneczny
	}
	else if(typ==2)
	{
		type=bWybierztypRes()+30; // 1-kopalnia mala 2- kopalnia duza 3-wieza wiertnicza
	}
	if(bSurowce(type)==1) // sprawdzenie czy iloœæ surowców jest wystarczaj¹ca
	{
		switch(type) // wybór pliku w którym jest budynek
		{	
			case 0:
				return 0;
				break;
			case 30:
				return 0;
				break;
			case 1:
				strcpy(nazwa, "buildings/teleport.bld");
				break;
			case 2:
				strcpy(nazwa, "buildings/generator.bld");
				break;
			case 3:
				strcpy(nazwa, "buildings/solarpanel.bld");
				break;
			case 31:
				strcpy(nazwa, "buildings/minesmall.bld");
				mine=1;
				break;
			case 32:
				strcpy(nazwa, "buildings/minehuge.bld");
				mine=1;
				break;
			case 33:
				strcpy(nazwa, "buildings/drillingtower.bld");
				break;
				
		}
		if( (budynek=fopen(nazwa, "r")) ==NULL) {info("Brak pliku z budynkiem w katalogu buildings. Katalog ten powinien sie."); return 0;}
		fscanf(budynek, "%i %i", &ry, &rx); // wczytanie wysokoœci i szerokoœci budynku
		for(i=0;i<ry;i++) // wczytywanie wygl¹du budynku do 
		{
			fscanf(budynek, "%s", buff);
			for(j=0;j<rx;j++)
			{
				if(buff[j]=='`') wyglad[i][j]=' '; // poniewa¿ fscans nie przechwytuje z pliku spacji wiêc zastêpujê je ` a potem w tym miejscy zamieniam na spacje
				else wyglad[i][j]=buff[j];
			}
		}
		fclose(budynek);
		if(bAim(mapa, pan, ry, rx, &y, &x)==0) return 0;
		if(bField(tab, y, x, ry, rx)==1)
		{
			//bAnimation(type, y, x);
			for(i=0;i<ry;i++) // wpisywanie budynku w tablice
			{
				for(j=0;j<rx;j++)
				{
					tab[(y-ry)+i+1][x+j]=wyglad[i][j];
				}
			}
			if(mine==1)
			{
				for(i=0;i<ry;i++)
				{
					for(j=0;j<rx;j++)
					{	
						if(resources[y-i][x+j]>20)
						{
							hang.sumTech+=resources[y-i][x+j]-20;
							mvprintw(y+8-i,x+1+j, "%i", resources[y-i][x+j]-20);
						}
						else if(resources[y-i][x+j]>10)
						{
							hang.sumKrysz+=resources[y-i][x+j]-10;
							mvprintw(y+8-i,x+1+j, "%i", resources[y-i][x+j]-10);
						}
						else if(resources[y-i][x+j]>0)
						{
							hang.sumZel+=resources[y-i][x+j];
							mvprintw(y+8-i,x+1+j, "%i", resources[y-i][x+j]);
						}
						rdelay(65);
					}
				}
			}
		}
		else info("Wybierz wlasciwe miejsce na budynek");
		
	}
	else info("Niewystarczajaca ilosc surowcow.");
}
