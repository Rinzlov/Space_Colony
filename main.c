#include "biblioteki.h"

int main(float argc, char *argv[])
{

	//=================DEKLARACJA ZMIENNYCH=========================================
	
		
	int i, j; // obs³uga pêtli for
	int menuvariable=1; // wartosc z menu. 1-nowa gra, 10-14-load 20-24-save
	int ee, ey; // wybór gracza
	int dorandom=0, random, rantab[10]={0,}; // random, dorandom- do modu³u losowoœci. rantab-diagnostyka modu³u losowaoœci
	int czas1=0, czas2=0;
	rob.aa=16; rob.bb=34; rob.aaa=16; rob.bbb=34; // rob.aa,rob.bb-wspó³rzêdne postaci na planszy, rob.aaa, rob.bbb-do ustalenia poprzedniego ruchu
	int profil=1;
	int widok=0; // widok -panelu programisty
	int resume=0; // czy gra zostala wstrzymana w menu
	int pominruch=0;
	int returnfrommenu=1;
	int klatki=20;
	int resources[40][70];
	int anim=0, anim2=0; // obs³uga animacji hangaru
	int animcolor=5, animcolor2;
	int oslona=0; // decyduje czy wyœwietlaæ animacjê
	int animoslona=0, animoslona2=0;
	int licznikdrzwi3=1, licznikdrzwi2=1, licznikdrzwi1=1, liczdrzwi[20];
	int ca1=0, dosurowcow=0;
	zeruj(resources);
	
	float w=40, d=70;   // w,d- wysokoœæ, d³ugoœæ planszy
	float kosztenergii=1, czas, przyrostczasu;
	float zmianamapy=0; // dla wartosci 1 Wmapa bedzie zmieniona
	float woda=0, wegiel=0;  // surowce
	
	char tab[40][70], minimap[40][70]; // tab- tablica przechowuj¹ca aktualni¹ planszê, minimap-minimapa
	char zapis[100]; // do zapisu zmienych w profilu
	char zdarzenie[70];

	PANEL *pGameinfo, *pMapa, *pMikromapa, *pResources, *pInfo, *pWeapon;
	WINDOW *Wgameinfo, *Wmapa, *mikromapa, *mResources, *minfo, *mWeapon;
	
	
	wypelnijTablice(minimap, ' ');       
	wypelnijTablice(tab, ' ');
	//===============MENU PROGRAMU==========================================    

	initscr();
	curs_set(0);
	/* Zmiana wielkoœci terminala*/
	resizeterm(49, 93);
	mvprintw(24, 42, "Loading...");
	refresh();

	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	timeout(klatki);
	Wgameinfo=newwin(6,70,1,1);
	
	Wmapa=newwin(40,70,8,1);
	mikromapa=newwin(22,20,26,72);
	minfo=newwin(9,20,1,72);
	mWeapon=newwin(9,20,10,72);
	mResources=newwin(40,70,8,1);
	pGameinfo=new_panel(Wgameinfo);
	pMapa=new_panel(Wmapa);
	pMikromapa=new_panel(mikromapa);
	pResources==new_panel(mResources);
	pInfo=new_panel(minfo);
	pWeapon=new_panel(mWeapon);
	initFstruct();

	start_color();
	/*COLOR_BLACK
	COLOR_RED
	COLOR_GREEN
	COLOR_YELLOW
	COLOR_BLUE
	COLOR_MAGENTA
	COLOR_CYAN
	COLOR_WHITE
	if(can_change_color()==TRUE)
	{mvprintw(10,10,"Mozna zmieniac kolory.");}
	else
	{mvprintw(10,10,"Nie mozna zmienac kolorow.");}
	rdelay(2000); */

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_CYAN);
	init_pair(9, COLOR_RED, COLOR_YELLOW);
	init_pair(10, COLOR_BLUE, COLOR_BLACK);
	init_pair(11, COLOR_CYAN, COLOR_BLACK);
	init_pair(12, COLOR_WHITE, COLOR_BLACK);
	init_pair(13, COLOR_BLACK, COLOR_BLACK);
	init_pair(14, COLOR_BLUE, COLOR_BLACK);
	init_pair(15, COLOR_BLUE, COLOR_BLACK);
	init_pair(16, COLOR_CYAN, COLOR_BLACK);
	
	attrset(COLOR_PAIR(1));
	menu:
	//menuvariable=menu(resume); // Menu i wybor dzialania
	returnfrommenu=1;
	resume=1;

	/* pobieranie pierwszej wartosci czasu do modu³u losowoœci */
	czas1=time(NULL);
	
	//loadgame();

	//===============PÊTLA G£ÓWNA PROGRAMU==========================================         
	while(1<2)
	{
		curs_set(0); // usuwa kursor z ekranu
		resizeterm(49, 93);
		werase(minfo);
		werase(mWeapon);
		werase(mResources);
		werase(mikromapa);
		werase(Wgameinfo);
		//=============ZAPIS GRY=============================
		if(zmianamapy==1 && (rob.map_x2!=35 || rob.map_y2!=20) && rob.map_x2!=55) //je¿eli Wmapa zosta³a zmieniona to zapisz aktualn¹ mapê
		{
			zapis:
			zapiszmape(tab, rob.map_y2, rob.map_x2, profil);
		}
		rob.map_x2=rob.map_x; rob.map_y2=rob.map_y; // zabezpieczenie przed zaladowaniem nieistniejacej mapy
		zmianamapy=0;
		clear();
		
		/* rysowanie ramek */
		attrset(COLOR_PAIR(5));
		wborder(stdscr, '|', '|', '=', '=', '+', '+', '+', '+');
		for(i=1;i<48;i++)
		{mvprintw(i,71,"|");}
		for(i=1;i<71;i++)
		{mvprintw(7,i,"_");}
		attrset(COLOR_PAIR(1));
		

		/* wczytywanie mapy */
		if(wczytajmape(tab, rob.map_y, rob.map_x, rob.map_y2, rob.map_x2, profil, minimap)==0)
		{
			warn("Nie udalo sie wczytac mapy.");
			rob.map_x=rob.map_x2;
			rob.map_y=rob.map_y2;
			rob.aa=rob.aaa;
			rob.bb=rob.bbb;
			wczytajmape(tab, rob.map_y, rob.map_x, rob.map_y2, rob.map_x2, profil, minimap);
		}
		else// je¿eli Wmapa zosta³a za³adowana
		{
			/* przypisywanie danej planszy pok³adów surowców */
			zeruj(resources);
			tResources(resources);
			


			missileQ.count=0;
			missileQ.liczbaprzeciwnikow=enemys(tab);
		
			/* wyœwietlenie minimapy na prawym panelu */
			werase(mikromapa);
			for(i=0;i<9;i++)
			{
				for(j=0;j<18;j++)
				{
					mvwprintw(mikromapa, 12+i,1+j, "%c", minimap[i+rob.map_y-4][j+rob.map_x-8]);
				}
			}
			if(rob.map_x==55)
			{
				werase(mikromapa);
			}
			wborder(mikromapa, '|', '|', '=', '=', '+', '+', '+', '+');
			mvwprintw(mikromapa, 11, 0, "+=====Minimapa=====+");
			mvwprintw(mikromapa, 0, 0, "+======Radar=======+");
			wattrset(mikromapa, COLOR_PAIR(5));
			mvwprintw(mikromapa, 1, 2, "Zelazo: %i", rob.zelazonamapie);
			wattrset(mikromapa, COLOR_PAIR(6));
			mvwprintw(mikromapa, 2, 2, "Krzem: %i", rob.krzemnamapie);
			wattrset(mikromapa, COLOR_PAIR(7));
			mvwprintw(mikromapa, 3, 2, "Technet: %i", rob.technetnamapie);
			wattrset(mikromapa, COLOR_PAIR(4));
			mvwprintw(mikromapa, 16, 9, "X");
			wattrset(mikromapa, COLOR_PAIR(3));
			
			/* wyœwietlanie mapy g³ównej */
			showmap(Wmapa, tab);
		}
		
		//pêtla wewnêtrzna         
		while(zmianamapy==0)
		{
			wattrset(minfo, COLOR_PAIR(3));
			wborder(minfo, '|', '|', '=', '=', '+', '+', '+', '+');
			mvwprintw(minfo, 0, 0, "+=====Kopalnie=====+");
			wattrset(minfo, COLOR_PAIR(4));
			mvwprintw(minfo, 1, 2, "Zelaza: %i", hang.sumZel);
			mvwprintw(minfo, 2, 2, "Krzemu: %i", hang.sumKrysz);
			mvwprintw(minfo, 3, 2, "Technetu: %i", hang.sumTech);
			mvwprintw(minfo, 6, 2, "Dosurowcow: %i", dosurowcow);
			if(hang.sumZel>0 || hang.sumKrysz>0 || hang.sumTech>0) mvwprintw(minfo, 7, 2, "Transfer za: %i ", 60-dosurowcow%60);
			
			

			wattrset(mWeapon, COLOR_PAIR(3));
			wborder(mWeapon, '|', '|', '=', '=', '+', '+', '+', '+');
			mvwprintw(mWeapon, 0, 0, "+====Uzbrojenie====+");
			wattrset(mWeapon, COLOR_PAIR(4));
			mvwprintw(mWeapon, 1, 2, "Aktualna bron:");	
			mvwprintw(mWeapon, 2, 2, "rakiety");
			mvwprintw(mWeapon, 3, 2, "Czas: %i:%i:%i ", (ca1/50)/60, (ca1/50)%60, ca1%50);
			ca1++;
			
			gra:
			/* Ile czasu up³ynê³o od ostatniego ruchu */
			czas2=czas1;
			czas1=time(NULL);
			przyrostczasu=czas1-czas2;
			
			hang.energia+=przyrostczasu*20; //generatorX.efektywnosc;
			dosurowcow+=przyrostczasu;
			if(dosurowcow==60)
			{
				surH.stal+=hang.sumZel;
				surH.krzem+=hang.sumKrysz;
				surH.technet+=hang.sumTech;
				dosurowcow=0;
			}
			
			
			/* Ustalenie zmiennej losowej */
			random=((czas1*6)+dorandom+czas2)%10;
			dorandom+=7; dorandom=dorandom%237;
			
			//==WYŒWIETLANIE ZAWARTOŒCI TABLICY-PLANSZY====================

			attrset(COLOR_PAIR(5));
			wborder(stdscr, '|', '|', '=', '=', '+', '+', '+', '+');
			attrset(COLOR_PAIR(1));
			
			/* je¿eli na mapie s¹ pociski to niech s¹ aktywne*/
			if(missileQ.count>0)
			{
				fmissile(Wmapa, tab);
			}
			
			/* je¿eli na mapie s¹ przeciwnicy to niech dzia³aj¹ */
			if(missileQ.liczbaprzeciwnikow>0)
			{
				enemysmove(tab);
			}
			
			/* je¿eli jesteœ w fabryce to niech dzia³a funkcjonalnoœæ fabryki */
			if(rob.map_x==55)
			{
				attrset(COLOR_PAIR(4)); 
				pominruch=factory(Wmapa);
				attrset(COLOR_PAIR(1));
			}
			
			/* je¿eli powrócono z menu to animacja przejœcia */
			if(returnfrommenu==1) {inlines(); returnfrommenu=0;}
			
			/* animacja drzwi */
			if(rob.map_x==35 && rob.map_y==20) 
			{
				drzwi(27, 32, rob.aa, rob.bb, tab, Wmapa, &licznikdrzwi3);
				drzwi(18, 32, rob.aa, rob.bb, tab, Wmapa, &licznikdrzwi2);
				drzwi(14, 32, rob.aa, rob.bb, tab, Wmapa, &licznikdrzwi1);
			}

			
			if(rob.map_x==35 && rob.map_y==19) 
			{
				drzwi(29, 32, rob.aa, rob.bb, tab, Wmapa, &liczdrzwi[0]);
				drzwi(26, 32, rob.aa, rob.bb, tab, Wmapa, &liczdrzwi[1]);
				drzwi(23, 32, rob.aa, rob.bb, tab, Wmapa, &liczdrzwi[2]);
				drzwi(20, 32, rob.aa, rob.bb, tab, Wmapa, &liczdrzwi[3]);
				drzwi(17, 32, rob.aa, rob.bb, tab, Wmapa, &liczdrzwi[4]);
				drzwi(14, 32, rob.aa, rob.bb, tab, Wmapa, &liczdrzwi[5]);
			}
			
			/* animacja os³ony */
			animcolor2=5;
			animcolor=6;
			if(oslona==1)
			{	
				rob.energia-=0.01;
				/*je¿eli robot siê poruszy³ to zma¿ pozosta³oœci po os³onie*/
				if(rob.aa!=rob.aaa || rob.bb!=rob.bbb)
				{
					wyswietljezeliwolne(tab, Wmapa, rob.aaa+1, rob.bbb," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa-2, rob.bbb," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa+1, rob.bbb-1," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa-2, rob.bbb+1," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa+1, rob.bbb-2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa-1, rob.bbb+2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa, rob.bbb+3," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa, rob.bbb-3," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa+1, rob.bbb+2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa-1, rob.bbb-2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa+1, rob.bbb+1," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aaa-2, rob.bbb-1," ");
						
				}
				animoslona=animoslona2/2;
				wattrset(Wmapa, COLOR_PAIR(6));
				switch(animoslona)
				{
					case 0:
						wattrset(Wmapa, COLOR_PAIR(animcolor));
						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb+3,"|");
						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb-3,"|");
						wattrset(Wmapa, COLOR_PAIR(animcolor2));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-2,"\\");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb+2,"\\");
						
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb," ");
						break;
					case 1:
						wattrset(Wmapa, COLOR_PAIR(animcolor));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+2,"/");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb-2,"/");
						wattrset(Wmapa, COLOR_PAIR(animcolor2));
						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb+3,"|");
						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb-3,"|");
						
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-1," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb+1," ");
						break;
					case 2:
						wattrset(Wmapa, COLOR_PAIR(animcolor));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+1,"_");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb-1,"_");
						wattrset(Wmapa, COLOR_PAIR(animcolor2));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+2,"/");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb-2,"/");
						
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-2," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb+2," ");
						break;
					case 3:
						wattrset(Wmapa, COLOR_PAIR(animcolor));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb,"_");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb,"_");
						wattrset(Wmapa, COLOR_PAIR(animcolor2));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+1,"_");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb-1,"_");

						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb+3," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb-3," ");
						break;
					case 4:
						wattrset(Wmapa, COLOR_PAIR(animcolor));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-1,"_");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb+1,"_");
						wattrset(Wmapa, COLOR_PAIR(animcolor2));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb,"_");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb,"_");
						
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+2," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb-2," ");
						break;
					case 5:
						wattrset(Wmapa, COLOR_PAIR(animcolor));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-2,"\\");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb+2,"\\");
						wattrset(Wmapa, COLOR_PAIR(animcolor2));
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-1,"_");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb+1,"_");
						
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+1," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb-1," ");
						break;
				}
				animoslona2++;
				if(animoslona2>10) animoslona2=0;
			}
			
			
			
			/* animacja hangaru */
			//animcolor=5;
			if(rob.map_x==35 && rob.map_y==20) 
			{
				anim=anim2;
				animacjahangaru(Wmapa, anim, ca1);
			}
			anim2++;
			if(anim2>42) anim2=0;
			
			//======PANEL INFORMACYJNY POSTACI================================
			showgameinfo(Wgameinfo, widok);

			top_panel(pGameinfo);
			top_panel(pMapa);
			
			if(rob.energia>0)
			{
				top_panel(pMikromapa);
				top_panel(pInfo);
				top_panel(pWeapon);
			}
			else
			{
				hide_panel(pMikromapa);
				hide_panel(pInfo);
				hide_panel(pWeapon);	
			}

			update_panels();
			mvprintw(rob.aaa+8,rob.bbb+1," ");
			X(rob.aa+8,rob.bb+1);
			doupdate();
			//======RUCH GRACZA============================================
			if(pominruch==0)
			{
				ee=getch();
				rob.aaa=rob.aa; rob.bbb=rob.bb; //ustalenie poprzedniego ruchu
			}
			else if(pominruch==3){ee=' '; tab[rob.aa-1][rob.bb]=' '; } // po wyjsciu z fabryki
			else ee=' ';
			pominruch=0;
			//======PRZESUNIECIE ROBOTA====================================
			switch(ee)
			{
				case KEY_LEFT: // LEFT
					if(rob.bb>0 && czysciana(tab[rob.aa][rob.bb-1])==0) // sprawdzenie czy robot nie zamierza wejœæ na œcianê lub wyjœæ poza planszê
					{
						tab[rob.aa][rob.bb]=' '; // wyczyszczenie pola które robot opuszcza
						rob.bb-=1; //zmiana wartoœci odpowiedniej wspó³rzêdnej aby przy nastêpnym wyœwietlaniu planszy robot by³ ju¿ na nowym miejscu
						rob.energia-=kosztenergii;
					}
					break;
				case KEY_RIGHT: // RIGHT
					if(rob.bb<(d-1) && czysciana(tab[rob.aa][rob.bb+1])==0)
					{
						tab[rob.aa][rob.bb]=' ';
						rob.bb+=1;
						rob.energia-=kosztenergii;
					}
					break;
				case KEY_UP: // UP
					if(rob.aa>0 && czysciana(tab[rob.aa-1][rob.bb])==0)
					{
						tab[rob.aa][rob.bb]=' ';
						rob.aa-=1;
						rob.energia-=kosztenergii;
					}
					break;
				case KEY_DOWN: // DOWN
					if(rob.aa<(w-1) && czysciana(tab[rob.aa+1][rob.bb])==0)
					{
						tab[rob.aa][rob.bb]=' ';
						rob.aa+=1;
						rob.energia-=kosztenergii;
					}
					break;
				case '0':
					break;
				case 'p': // pomoc
					outlines();
					endwin();
					exit(1);
					goto menu;
					break;
				case '`': // KODY
					timeout(-1);
					ee=getch();
					if(ee==' ')
					{
						ee=getch();
						switch(ee)
						{
							case 'z':
								surH.zlom+=ladowniaX.pojemnosc-rob.pojemnosc;
								break;
							case 'e':
								ogniwoX.pojemnosc+=1000;
								rob.energia=ogniwoX.pojemnosc;
								break;
							case 'p':
								rob.hp+=1000;
								break;
							case 's':
								surH.stal+=1000;
								surH.krzem+=1000;
								surH.helium+=1000;
								surH.technet+=1000;
								break;
							case 'd':
								surH.stal+=100000;
								surH.krzem+=100000;
								surH.helium+=100000;
								surH.technet+=100000;
								break;
							case 'j':
								ladowniaX.pojemnosc+=1000;
								break;
							case 'w':
								rob.energia=10;
								break;
						}
					}
					timeout(klatki);
					break;
				case '}': // prze³¹czenie widoku informacji dla programisty
					if(widok==0)
					widok=1;
					else
					widok=0;
					break;
				case 'k': // kolektory
					if(kolektorX.nr>0)
					{
						if(rob.energia<ogniwoX.pojemnosc)
						{
							//rob.energia=ladowanie(rob.energia, ogniwoX.pojemnosc, kolektorX.szybkosc, 2);
						}           
					}
					else
					{
						info("Nie posiadasz kolektorow slonecznych.\n");
					}
					break;
				case 'm': // minimapa
					move(8,1);
					wypiszCmape(minimap, 8);
					refresh();
					break;
				case 'd':
					if(rob.energia>0)
					{
						newmissile(rob.aa, rob.bb+1, 1, weaponX.nr);
					}
					break;
				case 'a':
					if(rob.energia>0)
					{
						newmissile(rob.aa, rob.bb+1, 2, weaponX.nr);
					}
					break;
				case 'w':
					if(rob.energia>0)
					{
						newmissile(rob.aa, rob.bb+1, 3, weaponX.nr);
					}
					break;
				case 's':
					if(rob.energia>0)
					{
						newmissile(rob.aa, rob.bb+1, 4, weaponX.nr);
					}
					break;
				case 'r':
					rocket(rob.aa,rob.bb);
					armageddon(tab);
					missileQ.liczbaprzeciwnikow=0;
					break;
				case 't':
					armageddon(tab);
					missileQ.liczbaprzeciwnikow=0;
					break;
				case 'b':
					if((rob.map_x!=35 || rob.map_y!=20) && rob.energia>0 && rob.map_x!=55)
					{
						build(Wmapa, pMapa, tab, 1, resources); // 1-budynki ogólne
						showmap(Wmapa, tab);	
					}
					else info("W tym miejscu nie mozna budowac lub masz za malo energii.");
					break;
				case 'f':
					if((rob.map_x!=35 || rob.map_y!=20) && rob.energia>0 && rob.map_x!=55)
					{
						timeout(-1);
						showresources(mResources, resources);
						wattrset(mResources, COLOR_PAIR(3));
						for(i=0;i<40;i++)
						{
							for(j=0;j<70;j++)
							{
								if(tab[i][j]!=' ') mvwprintw(mResources, i, j, "%c", tab[i][j]);
							}
						}
						hide_panel(pMapa);
						//top_panel(pResources);
						show_panel(pResources);
						update_panels();
						refresh();
						ee=getch();
						if(ee=='b')
						{ 
							build(mResources, pResources, tab, 2, resources); // 1-budynki wydobywcze
							showmap(Wmapa, tab);
						}
						top_panel(pMapa);
						update_panels();
						doupdate();
						timeout(klatki);
					}
					else info("W tym miejscu nie mozna wydobywac surowcow lub masz za malo energii.");
					break;
				case 'o': // os³ona
					if(oslona==0 && rob.energia>0) oslona=1;
					else
					{
						oslona=0;
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-1," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb+1," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-2," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb+2," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb+3," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb-3," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+2," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb-2," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+1," ");
						wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb-1," ");
					}
					break;
				case 'l':
					timeout(-1);
					help();
					timeout(klatki);
					break;
			}//koniec swicha
	  
			//=====OBS£UGA PÓL SPECJALNYCH================================================
			switch(tab[rob.aa][rob.bb])
			{
				case 'z':
					tab[rob.aa][rob.bb]=' ';
					showmap(Wmapa, tab);
					//info("Znaleziono %ikg zlomu.\n\n", (random/2)+1);
					surR.zlom+=Pojemnosc(rob.pojemnosc, ladowniaX.pojemnosc, (random/2)+1);             
					break;
				case 'Z':
					tab[rob.aa][rob.bb]=' ';
					showmap(Wmapa, tab);
					//info("Znaleziono %ikg zlomu\n\n", random+6);
					strcpy(zdarzenie,"Znaleziono %ikg zlomu");
					//zdarznie[]
					surR.zlom+=Pojemnosc(rob.pojemnosc, ladowniaX.pojemnosc, (random)+6);
					break;
				case '#':
					tab[rob.aa][rob.bb]=' ';
					showmap(Wmapa, tab);
					//info("Znaleziono %ikg krzemu\n\n", (random/3)+8);
					surR.krzem+=Pojemnosc(rob.pojemnosc, ladowniaX.pojemnosc, (random/3)+8);
					break;	
				case 'H': //=============HUTA=================================================
					rob.aa=rob.aaa; rob.bb=rob.bbb;
					info("Zlom zostal przetopiony na stal.");
					huta();
					break;
				case 'M': // Magazyn
					rob.aa=rob.aaa; rob.bb=rob.bbb;
					info("Surowce zostaly przeniesione do magazynu.");
					magazyn();
					break;
				case 'G': // £ADOWANIE BATERII W GENERATORZE
					rob.aa=rob.aaa; rob.bb=rob.bbb;
					generator();
					break;
			}
			
			//======OBS£UGA ZDARZEÑ DODATKOWYC7H===========================================
			if(rob.hp<=0) // zniszczenie robota
			{
				info("Robot ulegl zniszczeniu. Misje bedzie kontynuowal nowy robot. Wyposarzenie hangaru nie ulega zmianie.\n\n");
				zmianamapy=1;
				rob.map_y=20;
				rob.map_x=35;
				rob.aa=16; rob.bb=30;
				surR.zlom=0;
				ogniwoX=ogniwoq[0];
				ladowniaX=ladowniaq[0];
				silnikX=silnikq[0];
				kolektorX=kolektorq[0];
				pancerzX=pancerzq[0];
				rob.hp=10; //pancerzX.wytrzymalosc;
				rob.energia=ogniwoX.pojemnosc;         
			}

			if(rob.energia>ogniwoX.pojemnosc) // przekroczenie maksymalnej wartosci energii
			{
				rob.energia=ogniwoX.pojemnosc;
			}
			if(rob.energia<0) //rob.energia ponizej 0
			{
				rob.energia=0;
				if(oslona==1)
				{
					oslona=0;
					wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-1," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb+1," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb-2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb+2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb+3," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa, rob.bb-3," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa-1, rob.bb-2," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa+1, rob.bb+1," ");
					wyswietljezeliwolne(tab, Wmapa, rob.aa-2, rob.bb-1," ");
				}
			}

			//======ZMIANA MAPY===========================================================

			//   MAP 1      Hangar
			if(rob.map_x==35 && rob.map_y==20)  // Uwzglêdniæ po³o¿enie hangaru!
			{
				if(rob.aa==8 && rob.bb==41) // NAPRAWA
				{
					X(16,42);
					if(rob.hp<pancerzX.wytrzymalosc) repair();
				}
				if(rob.aa==21 && rob.bb==40) // FABRYKA
				{
					rob.map_x=55;
					rob.map_y=55;
					rob.aa=37;
					rob.bb=7;
					zmianamapy=1;
				}
			
				if(rob.aa==26 && rob.bb==25) // wewn¹trz
				{
					rob.aa=16; rob.bb=43;
				}
				if(rob.aa==15 && rob.bb==43) // wewn¹trz
				{
					rob.aa=26; rob.bb=23;
				}
			}

			// Poruszanie siê miêdzy planszami
			if(rob.map_x==55 && rob.map_y==55 && rob.aa==38 && rob.bb==7) // POWROT DO HANGARU Z FABRYKI
			{
				zmianamapy=1;
				rob.map_y=20;
				rob.map_x=35;
				rob.aa=22;
				rob.bb=40;
			}
			if(rob.aa==0)
			{
				if(rob.map_y>=1)
				{
					zmianamapy=1;
					rob.map_y-=1;
					rob.aa=38;
					rob.aaa=1;
				}
			}
			else if(rob.aa==39)
			{
				if(rob.map_y<999)
				{
					zmianamapy=1;
					rob.map_y+=1;
					rob.aa=1;
					rob.aaa=39;
				}
			}
			else if(rob.bb==0)
			{
				if(rob.map_x>=1)
				{
					rob.map_x-=1;
					rob.bb=68;
					rob.bbb=1;
					zmianamapy=1;
				}
			}
			else if(rob.bb==69)
			{
				if(rob.map_x<999)
				{
					zmianamapy=1;
					rob.map_x+=1;
					rob.bb=1;
					rob.bbb=68;
				}
			}
			// Zabezpieczenie przed wyjœciem poza dodatnie wartoœci plansz
			if(rob.map_x<0)
			{rob.map_x=0;}
			if(rob.map_y<0)
			{rob.map_y=0;}
			if(rob.map_x>999)
			{rob.map_x=999;}
			if(rob.map_y>999)
			{rob.map_y=999;}

				
		} //koniec pêtli wewnêtrznej- miêdzymapowej
	} //=========KONIEC PÊTLI G£ÓWNEJ======================================================================================================
	system("PAUSE");	
	return 0;
} // KONIEC BLOKU MAIN
