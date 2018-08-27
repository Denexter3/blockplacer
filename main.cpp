#include <iostream>
#include <stdio.h>
#include <unistd.h>

void drawer(int x, int obj[], int ile);

int main()
{
    bool sprawdz=0;
    int ile;
    int posc=1;
    char klaw;
    std::cout << "Kontrolki: \nWASD - Poruszanie sie\nE - kladzenie bloku \nZ - wyczyszczenie planszy\n";
    std::cout << "Podaj limit blokow ktore mozesz uzyc \nCala plansza ma tylko 200 blokow, nie bierz wiecej\n> ";
    std::cin >> ile;
    std::cout << "\033[2J\033[1;1H";
    int *obj;
    obj=new int[ile];
purger:
    {
        for(int i=0; i<ile; i++)
        {
            obj[i]=-1;
        }
        std::cout << "\033[2J\033[1;1H";
    }
    while(klaw!='9')
    {
        int ileblok=0;
        for(int h=0; h<ile; h++)
        {
            if(obj[h]>0)
            {
                ileblok++;
            }
        }
        sprawdz=0;
        drawer(posc, obj, ileblok);
        std::cout << "Koordynat X: " << posc << "\n";
        std::cout << "Polozone bloki:  " << ileblok << "\n";
        std::cin >> klaw;
        switch(int(klaw))
        {

        case 122:
            goto purger;
            break;
        case 119:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc-20) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc-20<201) && (posc-20>0)) posc=posc-20;
            break;
        case 97:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc-1) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc-1<201) && (posc-1>0)) posc=posc-1;
            break;
        case 115:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc+20) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc+20<201) && (posc+20>0)) posc=posc+20;
            break;
        case 100:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc+1) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc+1<201) && (posc+1>0)) posc=posc+1;
            break;
        case 101:
            int g=1;
            bool checking=0;
            for(int i=0; g<2; i++)
            {
                if(obj[i]>=0);
                else if(i>ile) g++;
                else
                {
                    for(int i=0; i<ileblok; i++)
                    {
                        if(posc+1==obj[i]) checking=checking+1;
                    }
                    if(checking==false){
                    obj[i]=posc+1;
                    g++;
                    }
                    else g++;
                }
            }
            break;
        }
        std::cout << "\033[2J\033[1;1H";
    }
}

void drawer(int x, int obj[], int ileblok)
{
    int sprawdzz=0;
    int endy=20;
    for(int buffer=1; buffer<201; buffer++)
    {
        sprawdzz=0;
        if (buffer==endy+1)
        {
            std::cout << "\n";
            endy=endy+20;
        }
        for(int i=0; i<ileblok; i++)
        {
            if(obj[i]==buffer) sprawdzz++;
        }
        if (sprawdzz>0) std::cout << "D ";
        else if (buffer==x) std::cout << "x ";
        else std::cout << "__";
    }
    std::cout << "\n";
}
