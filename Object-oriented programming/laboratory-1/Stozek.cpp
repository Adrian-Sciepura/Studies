#include "Stozek.h"

using namespace std;

Stozek::Stozek() : promien(0.5), wysokosc(0.5)
{

}

Stozek::Stozek(double promien, double wysokosc) : promien(promien), wysokosc(wysokosc)
{
    cout << "Konstruktor Stozka(" << promien << "," << wysokosc << ")" << endl;
}

Stozek::~Stozek()
{
    cout << "Destruktor Stozka(" << promien << "," << wysokosc << ")" << endl;
}

double Stozek::GetPromien() const
{
    return promien;
}

double Stozek::GetWysokosc() const
{
    return wysokosc;
}

void Stozek::SetPromien(double promien)
{
    this->promien = promien;
}

void Stozek::SetWysokosc(double wysokosc)
{
    this->wysokosc = wysokosc;
}

double Stozek::Pole()
{
    Kolo k(promien);
    return k.Pole() + PolePowBocznej();
}

double Stozek::Tworzaca()
{
    return sqrt(promien*promien + wysokosc*wysokosc);
}

double Stozek::PolePowBocznej()
{
    return PI * promien * Tworzaca();
}

void Stozek::Wypisz(std::ostream& out) const
{
    out << "Stozek o promieniu: " << promien << " i wysokosci: " << wysokosc << endl;
}