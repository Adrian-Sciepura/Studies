#include "Kolo.h"

using namespace std;

Kolo::Kolo(double promien) : promien(promien)
{
    cout << "Konstruktor Kola(" << promien << ")" << endl;
}

Kolo::~Kolo()
{
    cout << "Destruktor Kola(" << promien << ")" << endl;
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
    return 2 * PI * promien;
}

double Kolo::Pole()
{
    return PI * promien * promien;
}

void Kolo::Wypisz(std::ostream& out) const
{
    cout << "Kolo o promieniu: " << promien << '\n';
}