int shoot(char tab[40][70], int aa, int bb, int aim) //1 right 2 left 3 up 4 down
{
	int y=aa+8, x=bb+1, i, horizontal, vertical;
	int speedx=10, speedy=20;
	int color=6;
	char sparkx='-', sparky='|', spark;
	switch(aim)
	{
		case 1: // right	
			spark=sparkx;	
			vertical=0;
			horizontal=1;
			break;
		case 2: //left
			spark=sparkx;
			vertical=0;
			horizontal=-1;
			break;
		case 3: // up
			spark=sparky;
			horizontal=0;
			vertical=-1;
			break;
		case 4: // down
			spark=sparky;
			horizontal=0;
			vertical=1;
			break;
	}

	for(i=1; i<70-bb;i++)
	{
		attrset(COLOR_PAIR(color));
		if( (tab[aa+i*vertical][bb+i*horizontal]) == 'v') {tab[aa+i*vertical][bb+i*horizontal]=32; explosion(aa+i*vertical,bb+i*horizontal,1); return -1;}
		else if( (tab[aa+i*vertical][bb+i*horizontal]) != 32) {break;}
		attron(A_BOLD);
		mvprintw(y+i*vertical, x+i*horizontal, "%c", spark);
		attroff(A_BOLD);
		mvprintw(y+(i-1)*vertical, x+(i-1)*horizontal, " ");
		X(y,x);
		rdelay(speedx);
	}
	attrset(COLOR_PAIR(1));
	return 0;
}
