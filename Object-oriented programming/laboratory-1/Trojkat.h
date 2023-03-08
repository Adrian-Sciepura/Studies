#ifndef TROJKAT_H
#define TROJKAT_H

#include "FiguraPlaska.h"
#include <cmath>

class Trojkat : public FiguraPlaska
{
private:
    double a,b,c;

protected:
    void Wypisz(std::ostream& out) const override;

public:
    Trojkat(double a, double b, double c);
    ~Trojkat() override;

    double GetA() const;
    void SetA(double a);

    double GetB() const;
    void SetB(double b);

    double GetC() const;
    void SetC(double c);

    double Obwod() override;
    double Pole() override;
};

#endif