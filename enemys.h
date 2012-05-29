int enemys(char tab[40][70])
{
    int i, j, w=40, d=70, liczbaprzeciwnikow=0;
    for(i=0; i<w; i++) 
              {
                       for(j=0; j<d; j++)
                       {
                                if(tab[i][j]=='v') liczbaprzeciwnikow++;                         
                       }
                       printf("\n");
              } 
    return liczbaprzeciwnikow;
}

