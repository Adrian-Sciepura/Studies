#include <iostream>
#include "FiguraPlaska.h"
#include "Prostokat.h"
#include "Trojkat.h"

int main()
{
    FiguraPlaska* f = new Prostokat(10.0, 15.0);
    FiguraPlaska* f2 = new Trojkat(3.0, 4.0, 5.0);
    
    std::cout << *f;
    std::cout << f2->Pole() << '\n';

    delete f;
    return 0;
}