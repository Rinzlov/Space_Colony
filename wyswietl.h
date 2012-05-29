int wyswietl(char tab[40][70])
{
    int i, j;
    for(i=0; i<40; i++) 
              {
                       for(j=0; j<70; j++)
                       {
                                 printf("%c", tab[i][j]);                               
                       }
                       printf("\n");
              }
              return 0;
}
