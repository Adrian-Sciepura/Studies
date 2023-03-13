#include "Bryla.h"

std::ostream& operator<<(std::ostream& os, const Bryla& bryla)
{
    bryla.Wypisz(os);
    return os;
}

Bryla::~Bryla()
{
    
}