int zapiszmape(char tab[40][70], int map_y, int map_x, int profil)
{
	char nazwa_mapy[100];
	int i,j;
	FILE *mapa;
	char tablica[100]; //tablica przechywytuj¹ca kolejne linijki w pliku aby przekazaæ je do tablicy g³ównej
	strcpy(nazwa_mapy, "save/1/map_000000.map");
	zmien_nazwe_mapy(nazwa_mapy, map_x, map_y);
	nazwa_mapy[5]='1'; //wybór jednego z piêciu katalogów profili
	
	
	if ((mapa=fopen(nazwa_mapy, "w"))==NULL)
	{
		warn("Blad zapisy mapy.");
		return 0;
	}
	else
	{
		for(i= 0; i < 40; ++i)
		{
			for(j=0; j<70; j++)
			{
				//tablica[j]=tab[i][j];
				fputc(tab[i][j], mapa);
			}
			fputc('\n', mapa);
			//fputs(tablica, mapa);
		}
	}    
	fclose(mapa);
	
	strcpy(nazwa_mapy, "save/1/map_oooooo.map");
	if ((mapa=fopen(nazwa_mapy, "w"))==NULL)
	{
		warn("Blad zapisy zmiennych.");
		return 0;
	}
	else
	{
		fprintf(mapa, "%f %f", rob.hp, surH.stal);
		fclose(mapa);
	}
	/*											 
	// zapis zmiennych
	strcpy(zapis, nazwa_mapy);
	zapis[11]='v';
	zapis[12]='a';
	zapis[13]='l';
	zapis[14]='u';
	zapis[15]='e';
	zapis[16]='s';
	Zapis=fopen(zapis, "w");
	fprintf(Zapis, "%i %i %i %i ", aa, bb, aaa, bbb);
	fprintf(Zapis, "%i %i %i %i ", map_x, map_y, map_x2, map_y2);
	fprintf(Zapis, "%f ", poziom);
	fprintf(Zapis, "%f %f %f %f %f %f %f %f ", woda, stal, zlom, wegiel, krzem, krzem2, helium, technet);
	fclose(Zapis);
	*/
	return 1;
}

