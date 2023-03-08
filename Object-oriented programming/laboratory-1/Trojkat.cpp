#include "Trojkat.h"

using namespace std;

Trojkat::Trojkat(double a, double b, double c) : a(a), b(b), c(c)
{
    
}

Trojkat::~Trojkat()
{

}

double Trojkat::GetA() const
{
    return a;
}

double Trojkat::GetB() const
{
    return b;
}

double Trojkat::GetC() const
{
    return c;
}

void Trojkat::SetA(double a)
{
    this->a = a;
}

void Trojkat::SetB(double b)
{
    this->b = b;
}

void Trojkat::SetC(double c)
{
    this->c = c;
}

double Trojkat::Obwod()
{
    return a + b + c;
}

double Trojkat::Pole()
{
    double p = this->Obwod() / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Trojkat::Wypisz(std::ostream& out) const
{
    cout << "Trojkat o bokach: " << a << " " << b << " " << c << '\n';
}