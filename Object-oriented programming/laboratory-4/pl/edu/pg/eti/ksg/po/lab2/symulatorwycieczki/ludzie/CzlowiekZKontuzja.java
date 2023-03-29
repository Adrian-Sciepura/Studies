package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class CzlowiekZKontuzja extends Czlowiek
{
    public CzlowiekZKontuzja(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 3.0, 18.0, 12.0);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 2;
    }

}
