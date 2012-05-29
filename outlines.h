void outlines()
{
	int i, j;
	for(i=0;i<23;i++)
	{
		move(1+i,1);
		for(j=0;j<70;j++)
		{
			printw(" ");
		}
		move(47-i,1);
		for(j=0;j<70;j++)
		{
			printw(" ");
		}
		rdelay(23);
	}
}
