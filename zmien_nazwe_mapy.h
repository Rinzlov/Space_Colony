void zmien_nazwe_mapy(char nazwa_mapy[100], int map_x, int map_y)
{
      char liczba[100];
      sprintf(liczba,"%d",map_x);
                           if(map_x<10)
                           {
                                        
                                       nazwa_mapy[11]='0';
                                       nazwa_mapy[12]='0';
                                       nazwa_mapy[13]=liczba[0];
                           }
                           else if(map_x<100)
                           {
                                       nazwa_mapy[11]='0';
                                       nazwa_mapy[12]=liczba[0];
                                       nazwa_mapy[13]=liczba[1];
                           }
                           else if(map_x<1000)
                           {
                                       nazwa_mapy[11]=liczba[0];
                                       nazwa_mapy[12]=liczba[1];
                                       nazwa_mapy[13]=liczba[2];
                           }
                           
                           
                           sprintf(liczba,"%d",map_y);
                           if(map_y<10)
                           {
                                        
                                       nazwa_mapy[14]='0';
                                       nazwa_mapy[15]='0';
                                       nazwa_mapy[16]=liczba[0];
                           }
                           else if(map_y<100)
                           {
                                       nazwa_mapy[14]='0';
                                       nazwa_mapy[15]=liczba[0];
                                       nazwa_mapy[16]=liczba[1];
                           }
                           else if(map_y<1000)
                           {
                                       nazwa_mapy[14]=liczba[0];
                                       nazwa_mapy[15]=liczba[1];
                                       nazwa_mapy[16]=liczba[2];
                           }
}
