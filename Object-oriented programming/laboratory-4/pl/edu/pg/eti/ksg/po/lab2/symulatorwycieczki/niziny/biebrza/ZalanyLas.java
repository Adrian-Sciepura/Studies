package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.niziny.biebrza;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;

public class ZalanyLas extends Wedrowka
{
    public ZalanyLas(double odleglosc) {
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc) {
        return predkosc * 0.25;
    }

    @Override
    public int getTrudnoscNawigacyjna() {
        return 4;
    }

    @Override
    public String getNazwa() {
        return "Zalany Las";
    }
}
