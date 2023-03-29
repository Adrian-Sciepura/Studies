package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class Panorama extends Atrakcja
{
    private String nazwa;

    public Panorama(String nazwa) {
        super(1/6);
        this.nazwa = nazwa;
    }
    @Override
    public String getNazwa()
    {
        return nazwa;
    }
}
