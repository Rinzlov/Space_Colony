int wczytajmape(char tab[40][70], int map_y, int map_x, int map_y2, int map_x2, int profil, char minimap[40][70])
{
int s_lewa=0, s_prawa=0, s_gorna=0, s_dolna=0; // œciany na granicach planszy
FILE *mapa, *mapa1, *mapa2, *mapa3, *mapa4, *Zapis;
char nazwa_mapy[100], nazwa_mapy_l[100], nazwa_mapy_r[100], nazwa_mapy_g[100], nazwa_mapy_d[100], nazwa_mapy2[100]; // nazwy map do wczytania
//===========WCZYTYWANIE MAPY=========================
	// x 11 12 13  y 14 15 16   .txt 17 18 19 20
	char tablica[100];
	int i,j;

	/* mapa z katalogu save */
	strcpy(nazwa_mapy2, "save/1/map_000000.map");
	zmien_nazwe_mapy(nazwa_mapy2, map_x, map_y);

	/* jeœli jej nie ma to z katalogu maps */
	strcpy(nazwa_mapy, "maps/1/map_000000.map");
	zmien_nazwe_mapy(nazwa_mapy, map_x, map_y);
	//warn(nazwa_mapy2);
	//warn(nazwa_mapy);
	/* otwieranie */
	if ((mapa=fopen(nazwa_mapy2, "r"))==NULL)
	{
		if ((mapa=fopen(nazwa_mapy, "r"))==NULL) 
		{ warn("Brak mapy."); return 0;}
	}
	 // W PRZYPADKU OTWARCIA PLIKU Z MAP¥
		
		// nazwy map dooko³a do sprawdzenia czy istniej¹
		strcpy(nazwa_mapy_l, nazwa_mapy);
		strcpy(nazwa_mapy_r, nazwa_mapy);
		strcpy(nazwa_mapy_d, nazwa_mapy);
		strcpy(nazwa_mapy_g, nazwa_mapy);
		// Modu³ sprawdzaj¹cy czy istniej¹ plansze przyleg³e do danej
		zmien_nazwe_mapy(nazwa_mapy_l, map_x -1, map_y);
		zmien_nazwe_mapy(nazwa_mapy_r, map_x +1, map_y);
		zmien_nazwe_mapy(nazwa_mapy_g, map_x, map_y -1);
		zmien_nazwe_mapy(nazwa_mapy_d, map_x, map_y +1);

		//printw("%s\n%s\n%s\n%s\n", nazwa_mapy_l, nazwa_mapy_r, nazwa_mapy_g, nazwa_mapy_d);
		s_lewa=0;
		s_prawa=0;
		s_dolna=0;
		s_gorna=0;

		if( (mapa1=fopen(nazwa_mapy_l, "r")) ==NULL)
		{
			//printw("Nie ma mapy z lewej.\n");
			s_lewa=1;
		}
		else
		{
			fclose(mapa1);
			if(minimap[map_y][map_x-1]==' ')
			{minimap[map_y][map_x-1]='0';}
		}

		if( (mapa2=fopen(nazwa_mapy_r, "r")) ==NULL)
		{
			//printw("Nie ma mapy z prawej.\n");
			s_prawa=1;
		}
		else
		{
			fclose(mapa2);
			if(minimap[map_y][map_x +1]==' ')
			{minimap[map_y][map_x +1]='0';}
		}

		if( (mapa3=fopen(nazwa_mapy_d, "r")) ==NULL)
		{
			//printw("Nie ma mapy z dolu.\n");
			s_dolna=1;
		}
		else
		{
			fclose(mapa3);
			if(minimap[map_y +1][map_x]==' ')
			{minimap[map_y +1][map_x]='0';}
		}

		if( (mapa4=fopen(nazwa_mapy_g, "r")) ==NULL)
		{
			//printw("Nie ma mapy z gory.\n");
			s_gorna=1;
		}
		else
		{
			fclose(mapa4);
			if(minimap[map_y -1][map_x]==' ')
			{minimap[map_y -1][map_x]='0';}
		}

		//koniec modu³u
		// WCZYTYWANIE MAPY Z PLIKU
		for(i=0;i<40;++i)
		{
			fgets(tablica, 100, mapa);
			for(j=0; j<70; j++)
			{
				tab[i][j]=tablica[j];
				//modu³ dodaj¹cy œciany
				if(i==0 || j==0 || i==39 || j==69) // najpierw czyœci brzegi
				{tab[i][j]=' ';}
				if(j==0 && s_lewa==1)
				{tab[i][j]='|';}
				if(j==69 && s_prawa==1)
				{tab[i][j]='|';}
				if(i==0 && s_gorna==1)
				{tab[i][j]='-';}
				if(i==39 && s_dolna==1)
				{tab[i][j]='-';}
			} 
		} 
		// przypisanie wartoœci minimapy
		minimap[map_y2][map_x2]='#';
		minimap[20][35]='H';
		//minimap[map_y][map_x]='X';

		fclose(mapa);
		return 1;
}

