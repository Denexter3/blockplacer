#include <iostream>
#include <stdio.h>
#include <unistd.h>

short gdzkier();

void drawer(short x, int obj[], int ile, short kier, short wielkosc, short wielx);

short licznik(short cx, short x, int obj[], int ile, short wmapy);

int main()
{
    short wielx, wiely;
    bool sprawdz=0;
    short kierunek;
    int ile;
    short posc=1;
    char klaw;
    std::cout << "Kontrolki: \nwasd - Poruszanie sie\ne - kladzenie bloku \nz - wyczyszczenie planszy\n";
    std::cout << "q - Usuwanie bloku \nKazdy ruch zatwierdz enterem\n";
    std::cout << "Podaj limit blokow ktore mozesz uzyc \n> ";
    std::cin >> ile;
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Podaj wielkosc planszy w plaszczyznie x\n> ";
    std::cin >> wielx;
    std::cout << "Podaj wielkosc planszy w plaszczyznie y\n> ";
    std::cin >> wiely;
    short wielkosc= wielx * wiely;
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
    int ileblok;
    while(klaw!='9')
    {
        kierunek=gdzkier();
        ileblok=0;
        for(int h=0; h<ile; h++)
        {
            if(obj[h]>0)
            {
                ileblok++;
            }
        }
        sprawdz=0;
        drawer(posc, obj, ile, kierunek, wielkosc, wielx);
        std::cout << "Koordynat X: " << posc << "\n";
        std::cout << "Polozone bloki:  " << ileblok;
        if(ileblok==ile) std::cout << " !LIMIT!";
        std::cout << "\nKoordynat wskaznika:  " << kierunek << "\n";
        std::cin >> klaw;
        switch(int(klaw))
        {
        case 113:
            for(int i=ile; i>=0; i--)
            {
                if(obj[i]==kierunek) obj[i]=-1;
            }
            break;
        case 122:
            goto purger;
            break;
        case 119:
            posc=licznik(-wielx, posc, obj, ile, wielkosc);
            break;
        case 97:
            posc=licznik(-1, posc, obj, ile, wielkosc);
            break;
        case 115:
            posc=licznik(wielx, posc, obj, ile, wielkosc);
            break;
        case 100:
            posc=licznik(1, posc, obj, ile, wielkosc);
            break;
        case 101:
            int g=1;
            bool checking=0;
            for(int i=0; g<2; i++)
            {
                if(i==ile) g++;
                else if(obj[i]>=1);
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

