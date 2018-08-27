#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cmath>

void drawer(short x, short obj[], short ile, short kier, short wielkosc, short wielx);

int main()
{
    short wielx, wiely;
    short kierunek=0;
    bool sprawdz=0;
    short ile;
    short posc=1;
    char klaw;
    std::cout << "Kontrolki: \nWASD - Poruszanie sie\nE - kladzenie bloku \nZ - wyczyszczenie planszy\n";
    std::cout << "Podaj limit blokow ktore mozesz uzyc \n> ";
    std::cin >> ile;
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Podaj wielkosc planszy w plaszczyznie x\n> ";
    std::cin >> wielx;
    std::cout << "Podaj wielkosc planszy w plaszczyznie y\n> ";
    std::cin >> wiely;
    short wielkosc= wielx * wiely;
    short *obj;
    obj=new short[ile];
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
        drawer(posc, obj, ileblok, kierunek, wielkosc, wielx);
        std::cout << "Koordynat X: " << posc << "\n";
        std::cout << "Polozone bloki:  " << ileblok << "\n";
        std::cout << "Koordynat wskaznika:  " << kierunek << "\n";
        std::cin >> klaw;
        switch(int(klaw))
        {
        case 113:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==kierunek) obj[i]=-1;
            }
            break;
        case 122:
            goto purger;
            break;
        case 119:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc-wielx) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc-wielx<wielkosc+1) && (posc-wielx>0))
            {
                posc=posc-wielx;
                kierunek=posc-wielx;
            }
            break;
        case 97:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc-1) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc-1<wielkosc) && (posc-1>0))
            {
                posc=posc-1;
                kierunek=posc-1;
            }
            break;
        case 115:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc+wielx) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc+wielx<wielkosc+1) && (posc+wielx>0))
            {
                posc=posc+wielx;
                kierunek=posc+wielx;
            }
            break;
        case 100:
            for(int i=0; i<ileblok; i++)
            {
                if(obj[i]==posc+1) sprawdz=sprawdz+1;
            }
            if ((sprawdz==false) && (posc+1<wielkosc+1) && (posc+1>0))
            {
                posc=posc+1;
                kierunek=posc+1;
            }
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
                        if(kierunek==obj[i]) checking=checking+1;
                    }
                    if(checking==false)
                    {
                        obj[i]=kierunek;
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

void drawer(short x, short obj[], short ileblok, short kier, short wielkosc, short wx)
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
        for(int i=0; i<ileblok; i++)
        {
            if(obj[i]==buffer) sprawdzz++;
        }
        if (sprawdzz>0) std::cout << "D ";
        else if (buffer==x) std::cout << "x ";
        else if (buffer==kier) std::cout <<"* ";
        else std::cout << "__";
    }
    std::cout << "\n";
}
