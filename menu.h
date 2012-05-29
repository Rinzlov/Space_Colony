int menu(int resume)
{
	curs_set(0);
	char tab[40][70], tab2[40][70];
	int menu=1, choice, i, ii, far=20, choice2=0, choice3, koniecmenu=5, ENTER=10, wys=11, resume2=1;
	if(resume==1){koniecmenu=6; wys-=2;}
	WINDOW *undermenu;
	raw();
	clear();
	wczytajmape(tab, 771, 777, 1);
	wczytajmape(tab2, 772, 777, 1);
	if(resume!=1)
	{
		for(ii=0;ii<12;ii++)
		{
			clear();
			wypiszCmape(tab,17-ii);
			wypiszCmape(tab2,24+ii);
			attrset(COLOR_PAIR(5));
			wborder(stdscr, '|', '|', '=', '=', '+', '+', '+', '+');
			attrset(COLOR_PAIR(1));
			rdelay(55);
		}
	}
	while(choice!=KEY_END) // main while
	{
		clear();
		wypiszCmape(tab,5);
		wypiszCmape(tab2,36);
		move(wys+4,18);
		//printw("--==Space Colony==--");
		move(wys+7,far);
		if(menu==1) printw("[[New Game]]");
		else printw("  New Game  ");
		move(wys+10,far);
		if(menu==2) printw("[[Load]]");
		else printw("  Load  ");
		move(wys+13,far);
		if(menu==3) printw("[[Save]]");
		else printw("  Save  ");
		move(wys+16,far);
		if(menu==4) printw("[[Credits]]");
		else printw("  Credits  ");
		move(wys+19,far);
		if(menu==5) printw("[[Exit]]");
		else printw("  Exit  \n");
		if(resume==1)
		{
			move(wys+22,far);
			if(menu==6) printw("[[Resume]]");
			else printw("  Resume  \n");
		}
		attrset(COLOR_PAIR(5));
		wborder(stdscr, '|', '|', '=', '=', '+', '+', '+', '+');
		attrset(COLOR_PAIR(1));
		if(resume==1 && resume2==1) {inlines(); resume2=0;}
		refresh();
		choice=getch();
		if(choice==KEY_RIGHT || choice==ENTER) choice=KEY_ENTER;
		switch(choice)
		{
			case KEY_UP:
			menu-=1;
			if(menu<1){menu=koniecmenu;}
			break;
			case KEY_DOWN:
			menu+=1;
			if(menu>koniecmenu){menu=1;}
			break;
			case KEY_ENTER:
			switch(menu)
			{
				case 1: // NEW GAME
					move(wys+7,far+10);
					printw("]>---<]");
					undermenu=newwin(11,15,wys+7,far+16);
					wattrset(undermenu,COLOR_PAIR(1));
					wborder(undermenu, '|', '|', '-', '-', '.', '.', '*', '*');
					choice2=10;
					while(choice3!=KEY_END)
					{
						wmove(undermenu, 1,2);
						if(choice2==10) wprintw(undermenu, "[[Save 1.]]");
						else wprintw(undermenu, "  Save 1.  ");
						//opcja("Save 1.",choice2,20,"undermenu",1,2);
						wmove(undermenu, 3,2);
						if(choice2==11) wprintw(undermenu,"[[Save 2.]]");
						else  wprintw(undermenu,"  Save 2.  ");
						
						wmove(undermenu, 5, 2);
						if(choice2==12) wprintw(undermenu,"[[Save 3.]]");
						else wprintw(undermenu, "  Save 3.  ");

						wmove(undermenu, 7,2);
						if(choice2==13) wprintw(undermenu,"[[Save 4.]]");
						else  wprintw(undermenu,"  Save 4.  ");

						wmove(undermenu,9,2);
						if(choice2==14) wprintw(undermenu,"[[Save 5.]]");
						else wprintw(undermenu,"  Save 5.  ");
						wrefresh(undermenu);
						choice3=getch();
						if(choice3==KEY_RIGHT || choice3==ENTER) choice3=KEY_ENTER;
						switch(choice3)
						{
							case KEY_UP:
								choice2-=1;
								if(choice2<10){choice2=14;}
								break;
							case KEY_DOWN:
								choice2+=1;
								if(choice2>14){choice2=10;}
								break;
							case KEY_LEFT:
								delwin(undermenu);
								goto powrot;
								break;
							case KEY_ENTER:
								delwin(undermenu);
								if(warn("Profil zostanie zresetowany!")==0)
								{outlines(); return(choice2);}
								else
								{goto powrot;}
								break;
						}
						wrefresh(undermenu);
						refresh();
					}
					break;
				case 2: // LOAD
					move(wys+10,far+6);
					printw("]>-------<]");
					undermenu=newwin(11,15,wys+10,far+16);
					wattrset(undermenu,COLOR_PAIR(1));
					wborder(undermenu, '|', '|', '-', '-', '.', '.', '*', '*');
					choice2=20;
					while(choice3!=KEY_END)
					{
						wmove(undermenu, 1,2);
						if(choice2==20) wprintw(undermenu, "[[Save 1.]]");
						else wprintw(undermenu, "  Save 1.  ");

						wmove(undermenu, 3,2);
						if(choice2==21) wprintw(undermenu,"[[Save 2.]]");
						else  wprintw(undermenu,"  Save 2.  ");

						wmove(undermenu, 5, 2);
						if(choice2==22) wprintw(undermenu,"[[Save 3.]]");
						else wprintw(undermenu, "  Save 3.  ");

						wmove(undermenu, 7,2);
						if(choice2==23) wprintw(undermenu,"[[Save 4.]]");
						else  wprintw(undermenu,"  Save 4.  ");

						wmove(undermenu,9,2);
						if(choice2==24) wprintw(undermenu,"[[Save 5.]]");
						else wprintw(undermenu,"  Save 5.  ");
						wrefresh(undermenu);
						choice3=getch();
						if(choice3==KEY_RIGHT || choice3==ENTER) choice3=KEY_ENTER;
						switch(choice3)
						{
							case KEY_UP:
								choice2-=1;
								if(choice2<20){choice2=24;}
								break;
							case KEY_DOWN:
								choice2+=1;
								if(choice2>24){choice2=20;}
								break;
							case KEY_LEFT:
								delwin(undermenu);
								goto powrot;
								break;
							case KEY_ENTER:
								delwin(undermenu);
								return(choice2);
								break;
						}
						wrefresh(undermenu);
						refresh();
					}
					break;
				case 3: // SAVE
					move(wys+13,far);
					if(resume==1) printw("Game saved.");
					else printw("No game to save."); 
					refresh();
					getch();
					break;
				case 4: // CREDITS
					move(wys+16,far+10);
					printw("]>---<");
					undermenu=newwin(5,24,wys+12,far+16);
					wattrset(undermenu,COLOR_PAIR(1));
					wborder(undermenu, '|', '|', '-', '-', '.', '.', ']', '*');
					wmove(undermenu, 1,6);
					wprintw(undermenu, "Space Colony");
					wmove(undermenu, 2,11);
					wprintw(undermenu, "by");
					wmove(undermenu, 3,4);
					wprintw(undermenu, "Adam Gryszkiewicz");
					wrefresh(undermenu);
					getch();
					delwin(undermenu);
					break;
				case 5: // EXIT
					if(warn("Niezapisane zmiany zostana porzucone!")==0)
					{
					outlines();
					endwin();
					exit(1);}
					else
					{goto powrot;}
	    		    		break;
				case 6: // Resume
					outlines();
					return menu;
			}
			break;
		} //main switch end
		powrot:
		clear();
    } // main while end
    getch();
    endwin();
    exit(1);
}

