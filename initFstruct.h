void initFstruct()
{
	int i=1, n=6, j=0;

	missileQ.count=0;
	missileQ.liczbaprzeciwnikow=0;

	hang.sumZel=0;
	hang.sumKrysz=0;
	hang.sumTech=0;

	for(j=0;j<299;j++)
	{
		missileQ.numbers[j]=0;
	}

	for(i=1; i<=100; i++)
	{
		ladowniaq[i].nr=i;
		ladowniaq[i].pojemnosc=200+i;  //200*(i*i);
		ladowniaq[i].waga=i; //i*10;
		ladowniaq[i].stal=i; //100+i*100;
		ladowniaq[i].krzem=i; //0;
		ladowniaq[i].helium=i; //0;
		ladowniaq[i].technet=i; //0;
	}
	for(i=1; i<=100; i++)
	{
		ogniwoq[i].nr=i; //i;
		ogniwoq[i].pojemnosc=800+i; //i; //i*900;
		ogniwoq[i].waga=i; //0;
		ogniwoq[i].stal=i; //i*50;
		ogniwoq[i].krzem=i; //i*23;
		ogniwoq[i].helium=i; //i*13;
		ogniwoq[i].technet=i; //i*72;
	}
	for(i=1; i<=100; i++)
	{
		weaponq[i].nr=i; //i;
		weaponq[i].damage=i; //i*100;
		weaponq[i].waga=i; //0;
		weaponq[i].stal=i; //100*i;
		weaponq[i].krzem=i; //0;
		weaponq[i].helium=i; //0;
		weaponq[i].technet=i; //0;
	}
	for(i=1; i<=100; i++)
	{
		silnikq[i].nr=i; //i;
		silnikq[i].moc=i; //100*i;
		silnikq[i].stal=i; //i*50;
		silnikq[i].krzem=i; //0;
		silnikq[i].helium=i; //0;
		silnikq[i].technet=i; //0;
	}
	for(i=1; i<=100; i++)
	{
		pancerzq[i].nr=i; //i;
		pancerzq[i].wytrzymalosc=i; //i*100;
		pancerzq[i].waga=i; //0;
		pancerzq[i].stal=i; //i*30;
		pancerzq[i].krzem=i; //0;
		pancerzq[i].helium=i; //0;
		pancerzq[i].technet=i; //0;
	}
	for(i=1; i<=100; i++)
	{
		generatorq[i].nr=i; //i;
		generatorq[i].efektywnosc=i; //i*2;
		generatorq[i].stal=i; //i*10;
		generatorq[i].krzem=i; //0;
		generatorq[i].helium=i; //0;
		generatorq[i].technet=i; //0;
	}
	for(i=1; i<=100; i++)
	{
		teleporterq[i].nr=i; //i;
		teleporterq[i].energia=i; //123*i;
		teleporterq[i].stal=i; //i*53;
		teleporterq[i].krzem=i; //i*32;
		teleporterq[i].helium=i; //i*73;
		teleporterq[i].technet=i; //i*13;
	}
	
	ladowniaX=ladowniaq[1];

	ogniwoX=ogniwoq[1];

	weaponX=weaponq[1];

	silnikX=silnikq[1];

	pancerzX=pancerzq[1];

	generatorX=generatorq[1];

	rob.energia=ogniwoX.pojemnosc;
	rob.hp=pancerzX.wytrzymalosc;
}


