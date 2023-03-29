package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Wedrowka;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Panorama;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.PrzeprawaPrzezRzeke;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Blotostrada;

public class MistrzPanoram extends Czlowiek
{
    public MistrzPanoram(String imie, String nazwisko, Plec plec) {
        super(imie, nazwisko, plec, 5.0, 12.0, 20.0);
    }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 4;
    }

    @Override
    public void reagujNaAtrakcje(Atrakcja a)
    {
        if(a instanceof Panorama)
            regeneruj(a.getCzasZwiedzania()*2);
        else
            regeneruj(a.getCzasZwiedzania());
    }
}
