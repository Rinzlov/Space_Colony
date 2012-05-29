float Pojemnosc(float poj, float pojmax, float ilosc)
{
      float dodaj;
      if((pojmax-poj)>=ilosc && (pojmax-poj)>=0)
      {
                             return ilosc;
      }
      else if((pojmax-poj)<ilosc && (pojmax-poj)>=0)
      {
           komputer();
           info("Ladownia jest przepelniona!\n");
           dodaj=(pojmax-poj);
           return dodaj;
      }
      else
      error();

}
