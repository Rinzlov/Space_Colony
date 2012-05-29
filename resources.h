int reslosuj(int los, int tab[40][70], int min, int n)
{
	// 1-9 krzem, 11-19 technet
	int a=0, b=0, i, rar;
	srand((3*rob.map_x)%8+2*(rob.map_y%3)+los);
	for(i=0;i<n;i++)
	{
		a=rand()%80;
		b=rand()%140;
		if(a<40 && a>0 && b<70 && b>0)
		{
			tab[a][b]=rand()%6+2+min;
		}
	}
}

int poszerzRes(int tab[40][70])
{
	int i, j, w=40, d=70, l;
	for(l=9;l>1;l--)
	{
		for(i=0; i<w; i++) 
		{
			for(j=0; j<d; j++)
			{
				if((tab[i][j]%10)==l)
				{
					if((i+1)<39 && tab[i+1][j]==0)
					{
						tab[i+1][j]=tab[i][j]-1;
					}
					if((i-1)>0 && tab[i-1][j]==0)
					{
						tab[i-1][j]=tab[i][j]-1;
					}
					if((j+1)<69 && tab[i][j+1]==0)
					{
						tab[i][j+1]=tab[i][j]-1;
					}
					if((j-1)>0 && tab[i][j-1]==0)
					{
						tab[i][j-1]=tab[i][j]-1;
					}
					
				}
			}
		}
	}
}

int przeliczdlaradaru(int tab[40][70])
{
	int i, j, w=40, d=70;
	for(i=0; i<w; i++) 
	{
		for(j=0; j<d; j++)
		{
			if(tab[i][j]<10) rob.zelazonamapie+=tab[i][j];
			else if(tab[i][j]<20) rob.krzemnamapie+=(tab[i][j]-10);
			else if(tab[i][j]<30) rob.technetnamapie+=(tab[i][j]-20);
		}
	}
}

int tResources(int tab[40][70])
{
	rob.zelazonamapie=0;
	rob.krzemnamapie=0;
	rob.technetnamapie=0;
	if((rob.map_x!=35 ||rob.map_y!=20) && rob.map_x!=55)
	{
		reslosuj(13, tab, 1, 10); // zelazo
		reslosuj(58, tab, 11, 6); // krzem
		reslosuj(2, tab, 21, 1); // technet
		
		poszerzRes(tab);
		przeliczdlaradaru(tab);
	}
}

