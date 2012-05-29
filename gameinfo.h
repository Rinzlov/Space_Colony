int showgameinfo(WINDOW *gameinfo ,int widok)
{

	/* Ustelenie miejsca zajetego przez surowce */
	rob.pojemnosc=surR.zlom+surR.krzem+surR.helium+surR.technet;
	int x=1;
	werase(gameinfo);
	wattrset(gameinfo, COLOR_PAIR(4));
	mvwprintw(gameinfo, 0,x,"Surowce:");
	mvwprintw(gameinfo, 0,40, "P-pomoc");
	mvwprintw(gameinfo, 1,x,"Hangar: ");
	wmove(gameinfo, 1,9);
	wK(gameinfo, surH.stal, "Stal:"); wK(gameinfo, surH.krzem, "  Krzem:"); wK(gameinfo, surH.helium, "  Helium:"); wK(gameinfo, surH.technet, "  Technet:");
	mvwprintw(gameinfo, 2,x,"Robot: ");
	wmove(gameinfo, 2,9);
	wK(gameinfo, surR.zlom, "Zlom:"); wK(gameinfo, surR.krzem, "  Krzem:"); wK(gameinfo, surR.helium, "  Helium:"); wK(gameinfo, surR.technet, "  Technet:");
	mvwprintw(gameinfo, 3,x,"Energia hangaru: %0.0f   ", hang.energia);
	if((rob.energia*0.8)<=(ogniwoX.pojemnosc/2))
	{
		wattrset(gameinfo, COLOR_PAIR(2));
		wprintw(gameinfo, "Energia: %0.1f/%0.0f!", rob.energia, ogniwoX.pojemnosc);
		wattrset(gameinfo, COLOR_PAIR(4));
	}
	else wprintw(gameinfo, "Energia: %0.1f/%0.0f  ", rob.energia, ogniwoX.pojemnosc);
	wmove(gameinfo, 4,x);
	wprintw(gameinfo, "Pojemnosc: %0.0f/%0.0fkg   ", rob.pojemnosc, ladowniaX.pojemnosc);
	wmove(gameinfo, 5,x);
	wprintw(gameinfo, "Pancerz: %0.0f/%0.0f   ", rob.hp, pancerzX.wytrzymalosc);
	wprintw(gameinfo, "Klasa robota: %0.0f   ", rob.klasa);
	if(widok==1) // panel informacji dla programisty
	{
		mvwprintw(gameinfo,0,x, "Y(a):%i X(b):%i      ", rob.aa, rob.bb);
		mvwprintw(gameinfo,1,x, "map_x: %i map_y: %i\n\n    ", rob.map_x, rob.map_y);
		mvwprintw(gameinfo,2,x, "Terminal Y:%i  X:%i", rob.aa+8, rob.bb+1);
		mvwprintw(gameinfo, 3,x, "Liczba przeciwnikow: %i  Liczba rakiet: %i", missileQ.liczbaprzeciwnikow, missileQ.count);
	}
	wrefresh(gameinfo);
	attrset(COLOR_PAIR(1));
}

