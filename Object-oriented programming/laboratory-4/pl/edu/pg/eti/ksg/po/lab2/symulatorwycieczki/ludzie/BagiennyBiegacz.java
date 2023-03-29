package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.PrzeprawaPrzezRzeke;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Blotostrada;

public class BagiennyBiegacz extends Czlowiek
{
    public BagiennyBiegacz(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 6.0, 12.0, 20.0);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 5;
    }

    @Override
    public void reagujNaWedrowke(Wedrowka w, double czas) {
        if(w instanceof PrzeprawaPrzezRzeke || w instanceof Blotostrada)
            czas = czas / 2;

        aktualizujZmeczenie(czas);
        mow("Hmm, wędrówka: "+w.getNazwa());
    }
}
