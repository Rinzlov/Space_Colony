int wypelnijTablice(char tab[40][70], char znak)
{
    int i, j, w=40, d=70;
    for(i=0; i<w; i++) 
              {
                       for(j=0; j<d; j++)
                       {
                                tab[i][j]=znak;                          
                       }
                       printf("\n");
              } 
    return 0;
}
