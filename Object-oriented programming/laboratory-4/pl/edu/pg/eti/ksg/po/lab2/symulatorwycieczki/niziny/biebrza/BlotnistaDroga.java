package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.niziny.biebrza;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;

public class BlotnistaDroga extends Wedrowka
{
    public BlotnistaDroga(double odleglosc) {
        super(odleglosc);
    }

    @Override
    public double modyfikujPredkoscGrupy(double predkosc) {
        return predkosc * 0.9;
    }

    @Override
    public int getTrudnoscNawigacyjna() {
        return 1;
    }

    @Override
    public String getNazwa() {
        return "Blotnista Droga";
    }
}
