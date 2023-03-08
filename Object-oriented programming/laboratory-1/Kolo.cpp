#include "Kolo.h"

using namespace std;

Kolo::Kolo(double promien) : promien(promien)
{

}

Kolo::~Kolo()
{

}

double Kolo::GetPromien() const
{
    return promien;
}

void Kolo::SetPromien(double promien) 
{
    this->promien = promien;
}

double Kolo::Obwod()
{
    return 2 * 3.14 * promien;
}

double Kolo::Pole()
{
    return 3.14 * promien * promien;
}

void Kolo::Wypisz(std::ostream& out) const
{
    cout << "Kolo o promieniu: " << promien << '\n';
}