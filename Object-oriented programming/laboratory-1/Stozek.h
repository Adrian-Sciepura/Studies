#ifndef STOZEK_H
#define STOZEK_H

#include "Bryla.h"
#include "Kolo.h"
#include <iostream>
#include <cmath>

class Stozek : public Bryla
{
private:
    static constexpr double PI = 3.14;
    double promien, wysokosc;

protected:
    void Wypisz(std::ostream& out) const override;

public:
    Stozek();
    Stozek(double promien, double wysokosc);
    ~Stozek() override;

    double GetPromien() const;
    void SetPromien(double a);
    
    double GetWysokosc() const;
    void SetWysokosc(double b);

    double Pole() override;
    double Tworzaca();
    double PolePowBocznej();
};

#endif