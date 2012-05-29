void X(int y, int x)
{
	attrset(COLOR_PAIR(3));
	attron(A_BOLD);
	mvprintw(y,x,"X");
	attroff(A_BOLD);
	attrset(COLOR_PAIR(1));
}

void wyswietljezeliwolne(char tab[40][70], WINDOW *mapa, int y, int x, char tekst[10])
{
	if(tab[y][x]==' ') mvwprintw(mapa, y, x,"%c", tekst[0]);
}

void wyswietliumiescwtablicy(char tab[40][70], WINDOW *mapa, int y, int x, char tekst[10])
{
	tab[y][x]=tekst[0];
	mvwprintw(mapa, y, x,"%c", tekst[0]);
}


