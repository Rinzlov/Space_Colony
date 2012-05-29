void repair()
{
	int i;
	mvprintw(17,42,"=");
	mvprintw(17,41,"\\");
	mvprintw(17,43,"/");
	rdelay(100);
	mvprintw(17,40,"\\");
	mvprintw(17,44,"/");
	rdelay(100);
	mvprintw(18,41,"-");
	mvprintw(18,43,"-");
	rdelay(100);
	mvprintw(18,42,"-");
	rdelay(100);
	for(i=0;i<12;i++)
	{
		attrset(COLOR_PAIR(2));
		mvprintw(16,39,"=");
		mvprintw(16,45,"=");
		rdelay(70);
		mvprintw(16,40,"=");
		mvprintw(16,44,"=");
		rdelay(70);
		mvprintw(16,41,"[");
		mvprintw(16,43,"]");
		attrset(COLOR_PAIR(1));
		rdelay(50);
		mvprintw(16,39,"=");
		mvprintw(16,45,"=");
		rdelay(70);
		attrset(COLOR_PAIR(2));
		mvprintw(16,40,"[");
		mvprintw(16,44,"]");
		rdelay(70);
		mvprintw(16,41," ");
		mvprintw(16,43," ");
		rdelay(70);
	}
	attrset(COLOR_PAIR(1));
	mvprintw(16,39,"=");
	mvprintw(16,45,"=");
	rdelay(70);
	mvprintw(16,40,"=");
	mvprintw(16,44,"=");
	rdelay(70);
	mvprintw(16,41,"[");
	mvprintw(16,43,"]");
	rdelay(100);
	mvprintw(18,42," ");
	rdelay(100);
	mvprintw(18,41," ");
	mvprintw(18,43," ");
	rdelay(100);
	mvprintw(17,40," ");
	mvprintw(17,44," ");
	rdelay(100);
	mvprintw(17,42," ");
	rdelay(100);
	mvprintw(17,41,"/");
	mvprintw(17,43,"\\");
	rob.aa+=1;
	rob.hp=pancerzX.wytrzymalosc;
}

