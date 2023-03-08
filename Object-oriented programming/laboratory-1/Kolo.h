#ifndef KOLO_H
#define KOLO_H

#include "FiguraPlaska.h"

class Kolo : public FiguraPlaska
{
private:
    double promien;

protected:
    void Wypisz(std::ostream& out) const override;

public: 
    Kolo(double promien);
    ~Kolo();

    double GetPromien() const;
    void SetPromien(double promien);

    double Obwod() override;
    double Pole() override;
};

#endif