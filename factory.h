int factory(WINDOW *mapa)
{
	int aa=rob.aa, bb=rob.bb;
	int wys=3, i, next, next2, next3, next4;
	wattrset(mapa, COLOR_PAIR(4));
	switch(rob.map_y)
	{
		case 55:
			/* wyświetlenie informacji o surówcach w każdym slocie */
			for(i=0; i<4; i++)
			{
				wmove(mapa, 2+i*8,50);
				wK(mapa, surH.stal, "");
				wmove(mapa, 3+i*8,50);
				wK(mapa, surH.krzem, "");
				wmove(mapa, 4+i*8,50);
				wK(mapa, surH.helium, "");
				wmove(mapa, 5+i*8,50);
				wK(mapa, surH.technet, "");
			}
			
			/* koszt następnego ogniwa */
			wmove(mapa, 2,44);
			next=ogniwoX.nr+1;
			if(next<=100)
			{
				wK(mapa, ogniwoq[next].stal, "");
				wmove(mapa, 3,44);
				wK(mapa, ogniwoq[next].krzem, "");
				wmove(mapa, 4,44);
				wK(mapa, ogniwoq[next].helium, "");
				wmove(mapa, 5,44);
				wK(mapa, ogniwoq[next].technet, "");
				
				/* dane ogniw */
				wmove(mapa, 2,37);
				wK(mapa, ogniwoq[next].nr, "");
				wmove(mapa, 3,37);
				wK(mapa, ogniwoq[next].waga, "");
				wmove(mapa, 4,37);
				wK(mapa, ogniwoq[next].pojemnosc, "");
			}
			wmove(mapa, 2,29);
			wK(mapa, ogniwoX.nr, "");
			wmove(mapa, 3,29);
			wK(mapa, ogniwoX.waga, "");
			wmove(mapa, 4,29);
			wK(mapa, ogniwoX.pojemnosc, "");
			
			

			/* koszt następnej ładowni */
			wmove(mapa, 2+8,44);
			next2=ladowniaX.nr+1;
			if(next2<=100)
			{
				wK(mapa, ladowniaq[next2].stal, "");
				wmove(mapa, 3+8,44);
				wK(mapa, ladowniaq[next2].krzem, "");
				wmove(mapa, 4+8,44);
				wK(mapa, ladowniaq[next2].helium, "");
				wmove(mapa, 5+8,44);
				wK(mapa, ladowniaq[next2].technet, "");
				/* dane ładowni */
				
				wmove(mapa, 2+8,37);
				wK(mapa, ladowniaq[next2].nr, "");
				wmove(mapa, 3+8,37);
				wK(mapa, ladowniaq[next2].waga, "");
				wmove(mapa, 4+8,37);
				wK(mapa, ladowniaq[next2].pojemnosc, "");
			}
			wmove(mapa, 2+8,29);
			wK(mapa, ladowniaX.nr, "");
			wmove(mapa, 3+8,29);
			wK(mapa, ladowniaX.waga, "");
			wmove(mapa, 4+8,29);
			wK(mapa, ladowniaX.pojemnosc, "");
			
			/* koszt następnego silnika */
			wmove(mapa, 2+16,44);
			next3=silnikX.nr+1;
			if(next3<=100)
			{
				wK(mapa, silnikq[next3].stal, "");
				wmove(mapa, 3+16,44);
				wK(mapa, silnikq[next3].krzem, "");
				wmove(mapa, 4+16,44);
				wK(mapa, silnikq[next3].helium, "");
				wmove(mapa, 5+16,44);
				wK(mapa, silnikq[next3].technet, "");
				/* dane silnika */
				
				wmove(mapa, 2+16,37);
				wK(mapa, silnikq[next3].nr, "");
				
				wmove(mapa, 3+16,37);
				wK(mapa, silnikq[next3].moc, "");
			}
			wmove(mapa, 2+16,29);
			wK(mapa, silnikX.nr, "");
			wmove(mapa, 3+16,29);
			wK(mapa, silnikX.moc, "");
			
			/* koszt następnego pancerza */
			wmove(mapa, 2+24,44);
			next4=pancerzX.nr+1;
			if(next4<=100)
			{
				wK(mapa, pancerzq[next4].stal, "");
				wmove(mapa, 3+24,44);
				wK(mapa, pancerzq[next4].krzem, "");
				wmove(mapa, 4+24,44);
				wK(mapa, pancerzq[next4].helium, "");
				wmove(mapa, 5+24,44);
				wK(mapa, pancerzq[next4].technet, "");
				/* dane pancerza */
				
				wmove(mapa, 2+24,37);
				wK(mapa, pancerzq[next4].nr, "");
				
				wmove(mapa, 3+24,37);
				wK(mapa, pancerzq[next4].waga, "");
				
				wmove(mapa, 4+24,37);
				wK(mapa, pancerzq[next4].wytrzymalosc, "");
			}
			wmove(mapa, 2+24,29);
			wK(mapa, pancerzX.nr, "");
			wmove(mapa, 3+24,29);
			wK(mapa, pancerzX.waga, "");
			wmove(mapa, 4+24,29);
			wK(mapa, pancerzX.wytrzymalosc, "");
			
			if(bb==14)
			{
				switch(aa)
				{
					case 3: // OGNIWA
						if(next<=100 && surH.stal>=ogniwoq[next].stal && surH.krzem>=ogniwoq[next].krzem && surH.helium>=ogniwoq[next].helium && surH.technet>=ogniwoq[next].technet)
						{
							info("Ogniwa zostaly ulepszone!");
							ogniwoX=ogniwoq[next];
							rob.energia=ogniwoX.pojemnosc;
							surH.stal-=ogniwoq[next].stal;
							surH.krzem-=ogniwoq[next].krzem;
							surH.helium-=ogniwoq[next].helium;
							surH.technet-=ogniwoq[next].technet;
						}
						else
						{info("Nie masz wystarczajacej ilosci surowcow.");}
						rob.aa+=1;
						return 3;
						break;
					case 11: // LADOWNIE
						if(next2<=100 && surH.stal>=ladowniaq[next2].stal && surH.krzem>=ladowniaq[next2].krzem && surH.helium>=ladowniaq[next2].helium && surH.technet>=ladowniaq[next2].technet)
						{ info("Ladownia zostala ulepszone!"); ladowniaX=ladowniaq[next2];
						surH.stal-=ladowniaq[next2].stal; surH.krzem-=ladowniaq[next2].krzem; surH.helium-=ladowniaq[next2].helium; surH.technet-=ladowniaq[next2].technet;}
						else
						{info("Nie masz wystarczajacej ilosci surowcow.");}
						rob.aa+=1;
						return 3;
						break;
					case 19: // SILNIK
						if(next3<=100 && surH.stal>=silnikq[next3].stal && surH.krzem>=silnikq[next3].krzem && surH.helium>=silnikq[next3].helium && surH.technet>=silnikq[next3].technet)
						{ info("Nowy silnik zostal zamontowany!"); silnikX=silnikq[next3];
						surH.stal-=silnikq[next3].stal; surH.krzem-=silnikq[next3].krzem; surH.helium-=silnikq[next3].helium; surH.technet-=silnikq[next3].technet;}
						else
						{info("Nie masz wystarczajacej ilosci surowcow.");}
						rob.aa+=1;
						return 3;
						break;
					case 27: // PANCERZ
						if(next4<=100 && surH.stal>=pancerzq[next4].stal && surH.krzem>=pancerzq[next4].krzem && surH.helium>=pancerzq[next4].helium && surH.technet>=pancerzq[next4].technet)
						{ info("Pancerz zostal ulepszony!"); pancerzX=pancerzq[next4];
						surH.stal-=pancerzq[next4].stal; surH.krzem-=pancerzq[next4].krzem; surH.helium-=pancerzq[next4].helium; surH.technet-=pancerzq[next4].technet; rob.hp=pancerzX.wytrzymalosc;}
						else
						{info("Nie masz wystarczajacej ilosci surowcow.");}
						rob.aa+=1;
						return 3;
						break;
				}
			}
			break;
		case 54:
			for(i=0; i<5; i++)
			{
				wmove(mapa, 10+i*8,52);
				wK(mapa, surH.stal, "");
				wmove(mapa, 11+i*8,52);
				wK(mapa, surH.krzem, "");
				wmove(mapa, 12+i*8,52);
				wK(mapa, surH.helium, "");
				wmove(mapa, 13+i*8,52);
				wK(mapa, surH.technet, "");
			}
			if(bb==14)
			{
				switch(aa)
				{
					case 3: //  
						break;
					case 11: //  
						break;
					case 19: // REAKTORY TELEPORTACJI
						break;
					case 27: // GENERATORY PRADU
						break;
					case 35: // SILNIKI
						break;
				}
			}
			break;
		case 53:
			for(i=0; i<5; i++)
			{
				wmove(mapa, 10+i*8,52);
				wK(mapa, surH.stal, "");
				wmove(mapa, 11+i*8,52);
				wK(mapa, surH.krzem, "");
				wmove(mapa, 12+i*8,52);
				wK(mapa, surH.helium, "");
				wmove(mapa, 13+i*8,52);
				wK(mapa, surH.technet, "");
			}
			if(bb==14)
			{
				switch(aa)
				{
					case 3: //  
						break;
					case 11: //  
						break;
					case 19: //  
						break;
					case 27: //  
						break;
					case 35: //  
						break;
				}
			}
			break;
	}
	wattrset(mapa, COLOR_PAIR(1));
	return 0;
}

