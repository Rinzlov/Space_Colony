void inlines()
{
	WINDOW *lin;
	int i, j, u;
	lin=newwin(49,72,0,0);
	overwrite(stdscr, lin);
	for(i=24;i>0;i--)
	{
		overwrite(lin, stdscr);
		for(u=0; u<i; u++)
		{
			move(1+u,1);
			for(j=0;j<70;j++)
			{
				printw(" ");
			}
			move(47-u,1);
			for(j=0;j<70;j++)
			{
				printw(" ");
			}
		}
		rdelay(23);
		refresh();
	}
	overwrite(lin, stdscr);
	delwin(lin);
}
