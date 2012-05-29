int enemysmove(char tab[40][70])
{
    int i, j, w=40, d=70, direction=1;
	char tab2[40][70];
    for(i=0; i<w; i++) 
              {
                       for(j=0; j<d; j++)
                       {
                                tab2[i][j]=tab[i][j];                       
                       }
              } 

	for(i=0; i<w; i++) 
              {
                       for(j=0; j<d; j++)
                       {
                                switch(tab2[i][j])
								{
									case 'v':
										if(rob.aa==i || rob.bb==j)
										{
											if(rob.aa==i)
											{
												if(rob.bb>j) direction=1;
												if(rob.bb<j) direction=2;
											}
											if(rob.bb==j)
											{
												if(rob.aa>i) direction=4;
												if(rob.aa<i) direction=3;
											}
											enemysshoot(tab, i,j,direction,1);
										}
										else if(abs(rob.aa-i)<=abs(rob.bb-j))
										{
											if(rob.aa>i)
											{
												tab[i][j]=' ';
												tab[i+1][j]='v';
											}
											else
											{
												tab[i][j]=' ';
												tab[i-1][j]='v';
											}
										}
										else if(abs(rob.aa-i)>abs(rob.bb-j))
										{
											if(rob.bb>j)
											{
												tab[i][j]=' ';
												tab[i][j+1]='v';
											}
											else
											{
												tab[i][j]=' ';
												tab[i][j-1]='v';
											}
										}
										else warn("Blad w ruchu przeciwnikow.");
										break;
								}
                       }
              } 
}

