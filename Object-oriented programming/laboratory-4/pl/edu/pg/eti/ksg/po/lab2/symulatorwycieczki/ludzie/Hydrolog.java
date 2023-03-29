package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.PrzeprawaPrzezRzeke;

public class Hydrolog extends Czlowiek
{
    public Hydrolog(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 6.0, 18.0, 18.0);
    }


    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 5;
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        if(w instanceof PrzeprawaPrzezRzeke){
            mow("Uuu! Przeprawa przez rzekę. Zbiore dane do badan naukowych.");
            aktualizujZmeczenie(czas);
        }
        else
            super.reagujNaWedrowke(w, czas);
    }
}
