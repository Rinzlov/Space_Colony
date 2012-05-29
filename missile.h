int newmissile(int aa, int bb, int dir, int type)
{
	int i;
	if(missileQ.count<299)
	{
		for(i=1;i<299;i++)
		{
			if(missileQ.numbers[i]==0)
			{
				missileQ.numbers[i]=i;
				missileQ.count++;
				missile[i].aa=aa;
				missile[i].bb=bb;
				missile[i].dir=dir;
				missile[i].type=type;
				return 0;
			}
		}
	}
	else warn("Za pociskow na mapie!");
}


int fmissile(WINDOW *map, char tab[40][70])
{
	wattrset(map, COLOR_PAIR(3));
	int i, dmg=20, del=0, ex=0;
	for(i=0;i<299;i++)
	{
		if(missileQ.numbers[i]!=0)
		{
			del=0; ex=0;
			switch(missile[i].dir)
			{
				case 1: // right	
					if(missile[i].aa>=40 || missile[i].aa<=0 || missile[i].bb>=70 || missile[i].bb<=0)
					{
						del=1;
					}
					else if(missile[i].aa==rob.aa && missile[i].bb==rob.bb)
					{
						rob.hp-=dmg;
						del=1;
						ex=1;
					}
					else if(tab[missile[i].aa][missile[i].bb]==' ')
					{
						mvwprintw(map, missile[i].aa, missile[i].bb-2, ">-+");
						missile[i].bb++;
					}
					else if(tab[missile[i].aa][missile[i].bb]!=' ')
					{
						del=1;
						ex=1;
					}
					
					if(del==1)
					{
						missileQ.numbers[i]=0; 
						missileQ.count--;
					}
					if(ex==1)
					{explosion(missile[i].aa, missile[i].bb,2);}
					break;
				case 2: //left
					
					break;
				case 3: // up
					
					break;
				case 4: // down
					
					break;
			}
		}
	}
}


