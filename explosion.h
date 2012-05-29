int explosion(int aa, int bb, int type)
{
	int y=aa+8, x=bb+1, color=2;
	
	attrset(COLOR_PAIR(color));
	//mvprintw(y,x,"#");
	rdelay(20);
	mvprintw(y+1,x+1,"\\");
	mvprintw(y+1,x-1,"/");
	mvprintw(y-1,x+1,"/");
	mvprintw(y-1,x-1,"\\");
	rdelay(50);
	mvprintw(y+1,x,"v");
	mvprintw(y-1,x,"^");
	mvprintw(y,x+1,")");
	mvprintw(y,x-1,"(");
	rdelay(30);
	attrset(COLOR_PAIR(color));
	mvprintw(y+1,x+1," ");
	mvprintw(y+1,x-1," ");
	mvprintw(y-1,x+1," ");
	mvprintw(y-1,x-1," ");
	mvprintw(y+2,x+2,"\\");
	mvprintw(y+2,x-2,"/");
	mvprintw(y-2,x+2,"/");
	mvprintw(y-2,x-2,"\\");
	mvprintw(y+1,x," ");
	mvprintw(y-1,x," ");
	mvprintw(y,x+1," ");
	mvprintw(y,x-1," ");
	mvprintw(y+2,x,"v");
	mvprintw(y-2,x,"^");
	mvprintw(y,x+2,")");
	mvprintw(y,x-2,"(");	
	rdelay(30);
	attrset(COLOR_PAIR(1));
	mvprintw(y+2,x," ");
	mvprintw(y-2,x," ");
	mvprintw(y,x+2," ");
	mvprintw(y,x-2," ");	
	mvprintw(y+2,x+2," ");
	mvprintw(y+2,x-2," ");
	mvprintw(y-2,x+2," ");
	mvprintw(y-2,x-2," ");
	mvprintw(y+1,x," ");
	mvprintw(y-1,x," ");
	mvprintw(y,x+1," ");
	mvprintw(y,x-1," ");	
	refresh();
	return 0;
}

