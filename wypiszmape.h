int wypiszCmape(char tab[40][70], int y)
{
    int i, j, w=40, d=70, a=y;
    for(i=0; i<w; i++) 
              {
			  move(a,1);
                       for(j=0; j<d; j++)
                       {
				    if(tab[i][j]=='v') 
				    {
					attrset(COLOR_PAIR(2));
					attron(A_BOLD);
					printw("v");
					attroff(A_BOLD);
					attrset(COLOR_PAIR(1));
				    }
				    else
                                printw("%c", tab[i][j]);                             
                       }
                       a++;
              } 
}

int wypiszImape(int tab[40][70])
{
    int i, j, w=40, d=70;
    for(i=0; i<w; i++) 
              {
                       for(j=0; j<d; j++)
                       {
                                printf("%i", tab[i][j]);   
                                 //putchar(tab[i][j]);                            
                       }
                       printf("\n");
              } 
}

int zeruj(int tab[40][70])
{
    int i, j, w=40, d=70;
    for(i=0; i<w; i++) 
              {
                       for(j=0; j<d; j++)
                       {
							tab[i][j]=0;                      
                       }
              } 
}

int showmap(WINDOW *map, char tab[40][70])
{
    int i, j, w=40, d=70, a=0;
    wattrset(map, COLOR_PAIR(1));
    for(i=0; i<w; i++) 
              {
			  wmove(map, a,0);
                       for(j=0; j<d; j++)
                       {
				    if(tab[i][j]=='v') 
				    {
					wattrset(map, COLOR_PAIR(2));
					wattron(map, A_BOLD);
					wprintw(map, "v");
					wattroff(map, A_BOLD);
					wattrset(map, COLOR_PAIR(1));
				    }
				    else
                                wprintw(map, "%c", tab[i][j]);                             
                       }
                       a++;
              } 
}

int showresources(WINDOW *map, int tab[40][70])
{
    int i, j, w=40, d=70, a=0;
    for(i=0; i<w; i++) 
    {
		wattrset(map, COLOR_PAIR(3));
		wmove(map, a,0);
        for(j=0; j<d; j++)
        {
			if(tab[i][j]==0)
			{
				wprintw(map, " ");
			}
			else if(tab[i][j]<10) 
			{
				wattrset(map, COLOR_PAIR(5));
				wprintw(map, "%i", tab[i][j]);
				wattrset(map, COLOR_PAIR(3));
			}
			else if(tab[i][j]<20) 
			{
				wattrset(map, COLOR_PAIR(6));
				wprintw(map, "%i", tab[i][j]-10);
				wattrset(map, COLOR_PAIR(3));
			}
			else if(tab[i][j]<30) 
			{
				wattrset(map, COLOR_PAIR(7));
				wprintw(map, "%i", tab[i][j]-20);
				wattrset(map, COLOR_PAIR(3));
			}                         
        }
        a++;
    } 
}
