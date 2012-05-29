int loadgame()
{
	char nazwa_mapy[100];
	int i,j;
	FILE *mapa;
	strcpy(nazwa_mapy, "save/1/map_oooooo.map");
	if ((mapa=fopen(nazwa_mapy, "r"))==NULL)
	{info("ERR"); return 0;}
	fscanf(mapa, "%f %f", &rob.hp, &surH.stal);
	fclose(mapa);

}

