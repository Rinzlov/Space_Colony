int enemysshoot(char tab[40][70], int aa, int bb, int aim, int weapon)
{
	int y=aa+8, x=bb+1, i;
	int speedx=10, speedy=20;
	int color=6;
	int damage=5;
	char sparkx='-', sparky='|';
	switch(aim)
	{
		case 1: // right
			for(i=1; i<70-bb;i++)
			{
				attrset(COLOR_PAIR(2));
				attron(A_BOLD);
				mvprintw(y,x,"v");
				attroff(A_BOLD);
				attrset(COLOR_PAIR(color));
				if( (tab[aa][bb+i]) == 'X') {explosion(aa,bb+i,1); rob.hp-=damage; break;}
				else if( (tab[aa][bb+i]) != 32) {break;}
				attron(A_BOLD);
				mvprintw(y, x+i, "%c", sparkx);
				attroff(A_BOLD);
				mvprintw(y, x+i-1, " ");
				//X(y,x);
				rdelay(speedx);
			}
			mvprintw(y, x+i, " ");
			attrset(COLOR_PAIR(1));
			break;
		case 2: // left
			for(i=1; i<=bb;i++)
			{
				attrset(COLOR_PAIR(2));
				attron(A_BOLD);
				mvprintw(y,x,"v");
				attroff(A_BOLD);
				attrset(COLOR_PAIR(color));
				if( (tab[aa][bb-i]) == 'X') {explosion(aa,bb-i,1); rob.hp-=damage; break;}
				else if( (tab[aa][bb-i]) != 32) {break;}
				attron(A_BOLD);
				mvprintw(y, x-i, "%c",  sparkx);
				attroff(A_BOLD);
				mvprintw(y, x-i+1, " ");
				//X(y,x);
				rdelay(speedx);
			}
			mvprintw(y, x-i, " ");
			attrset(COLOR_PAIR(1));
			break;
		case 3: // up
			for(i=1; i<=aa;i++)
			{
				attrset(COLOR_PAIR(2));
				attron(A_BOLD);
				mvprintw(y,x,"v");
				attroff(A_BOLD);
				attrset(COLOR_PAIR(color));
				if( (tab[aa-i][bb]) == 'X') {explosion(aa-i,bb,1); rob.hp-=damage; break;}
				else if( (tab[aa-i][bb]) != 32) {break;}
				attron(A_BOLD);
				mvprintw(y-i, x, "%c",  sparky);
				attroff(A_BOLD);
				mvprintw(y-i+1, x, " ");
				rdelay(speedy);
			}
			mvprintw(y-i, x, " ");
			attrset(COLOR_PAIR(1));
			break;
		case 4: // down
			for(i=1; i<40-aa;i++)
			{
				attrset(COLOR_PAIR(2));
				attron(A_BOLD);
				mvprintw(y,x,"v");
				attroff(A_BOLD);
				attrset(COLOR_PAIR(color));
				if( (tab[aa+i][bb]) == 'X') {explosion(aa+i,bb,1); rob.hp-=damage; break;}
				else if( (tab[aa+i][bb]) != 32) {break;}
				attron(A_BOLD);
				mvprintw(y+i, x, "%c",  sparky);
				attroff(A_BOLD);
				mvprintw(y+i-1, x, " ");
				//X(y,x);
				rdelay(speedy);
			}
			mvprintw(y+i-1, x, " ");
			attrset(COLOR_PAIR(1));
			break;
	}
	return 0;
}

