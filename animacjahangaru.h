void reaktor(WINDOW *mapa, int ca1)
{
	int i, j;
	char znak;
	int color, nrznaku;

	srand(rob.aa+ca1);
	for(i=23; i<=26; i++)
	{
		for(j=20; j<=27; j++)
		{
			nrznaku=rand()%10;
			color=rand()%7+10;
			switch(nrznaku)
			{
				case 0:
					znak='\'';
					break;
				case 1:
					znak='"';
					break;
				case 2:
					znak=',';
					break;
				case 3:
					znak='.';
					break;
				case 4:
					znak='`';
					break;
				case 5:
					znak='~';
					break;
				case 6:
					znak='*';
					break;
				case 7:
					znak='.';
					break;
				case 8:
					znak='\'';
					break;
				case 9:
					znak=',';
					break;
			}
			wattrset(mapa, COLOR_PAIR(color));
			mvwprintw(mapa, i,j,"%c", znak);
		}
	}
}

void animacjahangaru(WINDOW *mapa, int anim, int ca1)
{
	int animcolor2=5, animcolor=6;
	reaktor(mapa, ca1);
	switch(anim)
				{
					case 0: // wattrset(mapa, COLOR_PAIR(animcolor2))
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 26,19,"|");
						break;
					case 1:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 25,19,"|");
						break;
					case 2:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 24,19,"|");
						break;
					case 3:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 23,19,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 26,19,"|");
						break;
					case 4:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 22,19,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 25,19,"|");
						break;
					case 5:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 21,19,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 24,19,"|");
						break;
					case 6:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 20,19,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 23,19,"|");
						break;
					case 7:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 19,19,"|");
						
						mvwprintw(mapa, 19,20,"_");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 22,19,"|");
						break;
					case 8:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 18,19,"|");
						
						mvwprintw(mapa, 19,21,"/");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 21,19,"|");
						break;
					case 9:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 17,19,"|");
						
						mvwprintw(mapa, 18,21,"%%");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 20,19,"|");
						break;
					case 10:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 16,19,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 19,19,"|");
						mvwprintw(mapa, 19,20,"_");
						break;
					case 11:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 15,19,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 18,19,"|");
						mvwprintw(mapa, 19,21,"/");
						break;
					case 12:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 14,19,"|");
						mvwprintw(mapa, 14,21,"%%");
						mvwprintw(mapa, 14,20,"/");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 17,19,"|");
						mvwprintw(mapa, 18,21,"%%");
						break;
					case 13:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 13,19,"|");
						mvwprintw(mapa, 13,20,"|");
						
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 16,19,"|");
						break;
					case 14:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 12,19,"|");
						mvwprintw(mapa, 12,20,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 15,19,"|");
						break;
					case 15:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 11,19,"|");
						mvwprintw(mapa, 11,20,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 14,19,"|");
						mvwprintw(mapa, 14,20,"/");
						mvwprintw(mapa, 14,21,"%%");
						break;
					case 16:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 10,19,"|");
						mvwprintw(mapa, 10,20,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 13,19,"|");
						mvwprintw(mapa, 13,20,"|");
						break;
					case 17:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 9,19,"|");
						mvwprintw(mapa, 9,20,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 12,19,"|");
						mvwprintw(mapa, 12,20,"|");
						break;
					case 18:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,19,"/");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 11,19,"|");
						mvwprintw(mapa, 11,20,"|");
						break;
					case 19:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,20,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 10,19,"|");
						mvwprintw(mapa, 10,20,"|");
						break;
					case 20:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,21,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 9,19,"|");
						mvwprintw(mapa, 9,20,"|");
						break;
					case 21:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,22,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,19,"/");
						break;
					case 22:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,23,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,20,"=");
						break;
					case 23:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,24,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,21,"=");
						break;
					case 24:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,25,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,22,"=");
						break;
					case 25:	
						wattrset(mapa, COLOR_PAIR(animcolor));
						//mvwprintw(mapa, 8,26,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,23,"=");
						break;
					case 26:	
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,27,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,24,"=");
						break;
					case 27:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,28,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,25,"=");
						break;
					case 28:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,29,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						//mvwprintw(mapa, 8,26,"|");
						break;
					case 29:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,30,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,27,"=");
						break;
					case 30:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,31,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,28,"=");
						break;
					case 31:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,32,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,29,"=");
						break;
					case 32:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,33,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,30,"=");
						break;
					case 33:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,34,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,31,"=");
					case 34:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,35,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,32,"=");
						break;
					case 35:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,36,"=");
						//mvwprintw(mapa, 8,37,"|");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,33,"=");
						break;
					case 36:
						wattrset(mapa, COLOR_PAIR(animcolor));
						
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,34,"=");
						break;
					case 38:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,38,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,35,"=");
						break;
					case 39:
						wattrset(mapa, COLOR_PAIR(animcolor));
						mvwprintw(mapa, 8,39,"=");
						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,36,"=");
						//mvwprintw(mapa, 8,37,"|");
						break;
					case 40:

						wattrset(mapa, COLOR_PAIR(animcolor2));
						
						break;
					case 41:

						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,38,"=");
						break;
					case 42:

						wattrset(mapa, COLOR_PAIR(animcolor2));
						mvwprintw(mapa, 8,39,"=");
						break;
				}
}

