int generator()
{ //16 19
	int y=rob.aa, x=rob.bb;
	int i, op=15;
	mvprintw(y+8,x+2, "]");
	mvprintw(y+8,x, "[");
	rdelay(250);
	mvprintw(y+7,x+3, "/");
	mvprintw(y+9,x+3, "\\");
	rdelay(250);
	mvprintw(y+8,x+3, "<");
	rdelay(200);
	mvprintw(y+8,x+4, "|");
	rdelay(160);
	mvprintw(y+8,x+5, "|");
	rdelay(160);
	mvprintw(y+8,x+6, "|");
	rdelay(160);
	mvprintw(y+8,x+7, "|");
	refresh();

	attrset(COLOR_PAIR(4));
	mvprintw(y+7,x+3, "/");
	mvprintw(y+9,x+3, "\\");
	rdelay(450);
	for(i=0;i<12;i++)
	{
		attrset(COLOR_PAIR(5));
		mvprintw(y+7,x+7, "|");
		mvprintw(y+9,x+7, "|");
		rdelay(op);
		mvprintw(y+7,x+6, "|");
		mvprintw(y+9,x+6, "|");
		rdelay(op);
		mvprintw(y+7,x+5, "|");
		mvprintw(y+9,x+5, "|");
		rdelay(op);
		mvprintw(y+7,x+4, "|");
		mvprintw(y+9,x+4, "|");
		rdelay(op);
		mvprintw(y+7,x+3, "/");
		mvprintw(y+9,x+3, "\\");
		rdelay(op);
		mvprintw(y+8,x+2, "]");
		mvprintw(y+8,x, "[");
		attrset(COLOR_PAIR(6));
		mvprintw(y+7,x+7, "|");
		mvprintw(y+9,x+7, "|");
		rdelay(op);
		mvprintw(y+7,x+6, "|");
		mvprintw(y+9,x+6, "|");
		rdelay(op);
		mvprintw(y+7,x+5, "|");
		mvprintw(y+9,x+5, "|");
		rdelay(op);
		mvprintw(y+7,x+4, "|");
		mvprintw(y+9,x+4, "|");
		rdelay(op);
		mvprintw(y+7,x+3, "/");
		mvprintw(y+9,x+3, "\\");
		rdelay(op);

		attrset(COLOR_PAIR(5));
		mvprintw(y+8,x+7, "|");
		rdelay(op);
		mvprintw(y+8,x+6, "|");
		rdelay(op);
		mvprintw(y+8,x+5, "|");
		rdelay(op);
		mvprintw(y+8,x+4, "|");
		rdelay(op);
		mvprintw(y+8,x+3, "<");
		rdelay(op);
		attrset(COLOR_PAIR(6));
		mvprintw(y+8,x+7, "|");
		rdelay(op);
		mvprintw(y+8,x+6, "|");
		rdelay(op);
		mvprintw(y+8,x+5, "|");
		rdelay(op);
		mvprintw(y+8,x+4, "|");
		rdelay(op);
		mvprintw(y+8,x+3, "<");
		rdelay(op);
	}
	attrset(COLOR_PAIR(1));
		mvprintw(y+7,x+7, "|");
		mvprintw(y+9,x+7, "|");
		rdelay(op);
		mvprintw(y+7,x+6, "|");
		mvprintw(y+9,x+6, "|");
		rdelay(op);
		mvprintw(y+7,x+5, "|");
		mvprintw(y+9,x+5, "|");
		rdelay(op);
		mvprintw(y+7,x+4, "|");
		mvprintw(y+9,x+4, "|");
		rdelay(op);
	mvprintw(y+7,x+3, "-");
	mvprintw(y+9,x+3, "-");
	mvprintw(y+8,x+7, " ");
	rdelay(110);
	mvprintw(y+8,x+6, " ");
	rdelay(110);
	mvprintw(y+8,x+5, " ");
	rdelay(110);
	mvprintw(y+8,x+4, " ");
	rdelay(140);
	mvprintw(y+8,x+3, " ");
	rdelay(310);
	mvprintw(y+8,x+2, " ");
	refresh();
	rob.energia=ogniwoX.pojemnosc;
}

