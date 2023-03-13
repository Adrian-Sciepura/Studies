#include <iostream>
#include "FiguraPlaska.h"
#include "Prostokat.h"
#include "Trojkat.h"
#include "Kolo.h"
#include "Bryla.h"
#include "Stozek.h"

using std::cout;

int main()
{
    /*
    FiguraPlaska* figury[10];

    for(int i = 0; i < 10; i++)
    {
        int temp = i % 3;
        if(temp == 1)
        {
            figury[i] = new Prostokat(10*i, 20*i);
        }
        else if(temp == 2)
        {
            figury[i] = new Trojkat(3*i, 4*i, 5*i);
        }
        else
        {
            figury[i] = new Kolo(13*i);
        }
    }

    cout << '\n';

    for(int i = 0; i < 10; i++)
    {
        delete figury[i];
    }
    */

    Stozek s(10, 10);
    cout << s.PolePowBocznej() << "\n";
    cout << s.Pole() << '\n';

    Bryla* b = new Stozek(10, 10);
    cout << b->Pole() << '\n';
     
    delete b;
    return 0;
}