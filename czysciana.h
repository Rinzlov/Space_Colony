float czysciana(char znak)
{
    if(znak=='-' || znak=='_' || znak=='/' || znak=='\\' || znak=='|' || znak=='[' || znak==']' || znak=='{' || znak=='}' || znak=='=' || znak=='(' || znak==')' || znak=='>' || znak=='<')
    {
                 return 1;
    }
    else
    {
                 return 0;
    }
}
