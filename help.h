int help()
{
	char poz0[]="Klawiszologia", poz1[]="Oznaczenia", poz2[]="Surowce", poz3[]="Fabula", poz4[]="Wyjscie";
	int pos=0;
	int choice, p=24;
	WINDOW *help;
	help=newwin(49,93,0,0);
	wattrset(help, COLOR_PAIR(1));
	while(choice!=KEY_ENTER)
	{
		werase(help);
		wborder(help, '|', '|', '=', '=', '+', '+', '+', '+');
		
		if(pos==0) mvwprintw(help, 2, 2, "[[ %s ]]", poz0);
		else mvwprintw(help, 2, 2, "   %s   ", poz0);
		
		if(pos==1) mvwprintw(help, 4, 2, "[[ %s ]]", poz1);
		else mvwprintw(help, 4, 2, "   %s   ", poz1);
		
		if(pos==2) mvwprintw(help, 6, 2, "[[ %s ]]", poz2);
		else mvwprintw(help, 6, 2, "   %s   ", poz2);
		
		if(pos==3) mvwprintw(help, 8, 2, "[[ %s ]]", poz3);
		else mvwprintw(help, 8, 2, "   %s   ", poz3);
		
		if(pos==4) mvwprintw(help, 10, 2, "[[ %s ]]", poz4);
		else mvwprintw(help, 10, 2, "   %s   ", poz4);
		
		//if(pos==5) mvwprintw(help, 12, 2, "[[ %s ]]", poz5);
		//else mvwprintw(help, 12, 2, "   %s   ", poz5);
		
		//if(pos==6) mvwprintw(help, 14, 2, "[[ %s ]]", poz6);
		//else mvwprintw(help, 14, 2, "   %s   ", poz6);
		
		if(pos==0) //kalwisze
		{
			mvwprintw(help, 2, p, "Poruszanie sie po planszy - strzalki.");
			mvwprintw(help, 3, p, "Uzycie broni - W S A D");
			mvwprintw(help, 5, p, "B - budowanie (w widoku surowcow (F) budynki wydobywcze).");
			mvwprintw(help, 6, p, "F - pokazuje obraz radarowy zloz surowcow pod ziemia.");
			mvwprintw(help, 7, p, "O - wlacza oslone.");

		}
		if(pos==1) // oznaczenia
		{
			mvwprintw(help, 2, p, "W Hangarze:");
			mvwprintw(help, 3, p, "G - stacja ladowania energii z generatora.");
			mvwprintw(help, 4, p, "[ ] - stacja naprawcza, odnawia pancerz robota.");
			mvwprintw(help, 5, p, "H - huta stali, przetapia zlom przyniesiony przez robota.");
			mvwprintw(help, 6, p, "M - magazyn, przenosi surowce z ladowni robota do hangaru.");
			mvwprintw(help, 7, p, "F - fabryka, ulepszenia robota.");
			mvwprintw(help, 8, p, "W - ulepszenia systemow uzbrojenia.");
			
			mvwprintw(help, 10, p, "Na planszy:");
			mvwprintw(help, 11, p, "Z, z - duza i mala kupa zlomu, pozostalosc po innej cywilizacji.");
			mvwprintw(help, 12, p, "# - bryla krzemu");
			mvwprintw(help, 14, p, "Na minimapie:");
			mvwprintw(help, 15, p, "X - poloznie robota.");
			mvwprintw(help, 16, p, "H - hangar.");
			mvwprintw(help, 17, p, "0 - nieodwiedzona istniejaca plansza.");
			mvwprintw(help, 18, p, "# - odwiedzona plansza.");
		}
		if(pos==2) // surowce
		{
			mvwprintw(help, 2, p, "Na kazdej mapie (oprocz hangaru) pod ziemia moga kryc sie zloza");
			mvwprintw(help, 3, p, "surowcow. Radar widoczny w prawym panelu pokazuje sume zloz na");
			mvwprintw(help, 4, p, "danej planszy, wcisniecie [F] pokazuje dokladne ulozenie zloz na");
			mvwprintw(help, 5, p, "duzej mapie. Wcisniecie w tym momencie [B] wyswietla liste");
			mvwprintw(help, 6, p, "budynkow wydobywczych.");
			mvwprintw(help, 8, p, "Zasobnosc zloz surowcow okreslona jest przez cyfry od 1 do 9.");
			mvwprintw(help, 9, p, "Budynki wydobywcze nalezy umiejscawiac tak aby objely jak");
			mvwprintw(help, 10, p, "najwieksza sume cyfr. Po zbudowaniu kopalni w panelu po prawej");
			mvwprintw(help, 11, p, "stronie zwieksza sie informacja o sumie surowcow objetych");
			mvwprintw(help, 12, p, "kopalniami. Pojawia sie tez timer pokazujacy interwal po ktorym");
			mvwprintw(help, 13, p, "kolejny transport surowcow dotrze do hangaru.");
			mvwprintw(help, 15, p, "Surowce sa potrzebne do ulepszania robota w fabryce, produkcji");
			mvwprintw(help, 16, p, "uzbrojenia, tworzenia maszyn konstrukcyjnych oraz budowania");
			mvwprintw(help, 17, p, "systemu baz potrzebnych do skolonizowania planety czyli ");
			mvwprintw(help, 18, p, "osiagniecia celu gry.");
		}
		if(pos==3)
		{
			mvwprintw(help, 2, p, "");
			mvwprintw(help, 2, p, "");
			mvwprintw(help, 2, p, "");
			mvwprintw(help, 2, p, "");
			mvwprintw(help, 2, p, "");
			mvwprintw(help, 2, p, "");
		}
		
		wrefresh(help);

		choice=getch();
		if(choice==KEY_DOWN)
		{
			pos++;
			if(pos>4) pos=0;
		}
		else if(choice==KEY_UP)
		{
			pos--;
			if(pos<0) pos=4;
		}
		else
		{
			delwin(help);
			return 0;
		}
	}
	
}

