#include <iostream>

short kierunek;

void drawer(short x, int obj[], int ile, short kier, short wielkosc, short wx)
{
    short endy=wx;
    short sprawdzz=0;
    int buffer=1;
    for(buffer; buffer<wielkosc+1; buffer++)
    {
        sprawdzz=0;
        if (buffer==endy+1)
        {
            std::cout << "\n";
            endy=endy+wx;
        }
        for(int i=0; i<ile; i++)
        {
            if(obj[i]==buffer) sprawdzz++;
        }
        if (sprawdzz>0) std::cout << "D ";
        else if (buffer==x) std::cout << "x ";
        else if (buffer==kier) std::cout <<"* ";
        else std::cout << "..";

    }
    std::cout << "\n";
}

short licznik(short cx, short x, int obj[], int ile, short wmapy)
{
    bool koliz=false;
    for(short i=0; i<ile; i++)
    {
        if (cx+x==obj[i]) koliz=true;
    }
    if ((koliz==false) && (cx+x<=wmapy) && (cx+x>0))
    {
        kierunek=x+cx+cx;
        return x+cx;
    }
    else
    {
        return x;
    }
}

short gdzkier()
{
    return kierunek;
}
