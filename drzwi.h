void drzwi(int y, int x, int aa, int bb, char tab[40][70], WINDOW *mapa, int *licznikdrzwi)
{
				wattrset(mapa, COLOR_PAIR(3));
				if((aa==y+1 || aa==y || aa==y-1 || aa==y-2) && (bb>(x-1) && bb<(x+4))) // trzecie drzwi
				{
					switch(*licznikdrzwi)
					{
						case 1:
							wyswietliumiescwtablicy(tab, mapa, y, x, "-");
							wyswietliumiescwtablicy(tab, mapa, y, x+1, "-");
							wyswietliumiescwtablicy(tab, mapa, y, x+2, "-");
							wyswietliumiescwtablicy(tab, mapa, y, x+3, "-");
							break;
						case 6:
							wyswietliumiescwtablicy(tab, mapa, y, x, " ");
							wyswietliumiescwtablicy(tab, mapa, y, x+1, " ");
							wyswietliumiescwtablicy(tab, mapa, y, x+2, " ");
							wyswietliumiescwtablicy(tab, mapa, y, x+3, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+1, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+2, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+3, "_");
							break;
						case 16: //11
							wyswietliumiescwtablicy(tab, mapa, y-1, x-1, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+1, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+2, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+3, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+4, "_");
							break;
						case 26://21
							wyswietliumiescwtablicy(tab, mapa, y-1, x-2, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x-1, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+3, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+4, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+5, "_");
							break;
					}
					*licznikdrzwi+=1;
					if(*licznikdrzwi>30) *licznikdrzwi=30;
				}
				else
				{
					switch(*licznikdrzwi)
					{
						case 26:// 21
							wyswietliumiescwtablicy(tab, mapa, y-1, x-2, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x-1, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+3, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+4, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+5, " ");
							break;
						case 16: //11
							wyswietliumiescwtablicy(tab, mapa, y-1, x-1, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+1, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+2, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+3, "_");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+4, " ");
							break;
						case 6:
							wyswietliumiescwtablicy(tab, mapa, y, x, "-");
							wyswietliumiescwtablicy(tab, mapa, y, x+1, "-");
							wyswietliumiescwtablicy(tab, mapa, y, x+2, "-");
							wyswietliumiescwtablicy(tab, mapa, y, x+3, "-");
							wyswietliumiescwtablicy(tab, mapa, y-1, x, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+1, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+2, " ");
							wyswietliumiescwtablicy(tab, mapa, y-1, x+3, " ");
							break;
						case 1:
							wyswietliumiescwtablicy(tab, mapa, y, x, "_");
							wyswietliumiescwtablicy(tab, mapa, y, x+1, "_");
							wyswietliumiescwtablicy(tab, mapa, y, x+2, "_");
							wyswietliumiescwtablicy(tab, mapa, y, x+3, "_");
							break;
					}
					*licznikdrzwi-=1;
					if(*licznikdrzwi<1) *licznikdrzwi=1;
				}
}

