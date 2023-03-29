package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class Schronisko extends Atrakcja
{
    private String nazwa;

    public Schronisko(String nazwa) {
        super(3/4);
        this.nazwa = nazwa;
    }
    @Override
    public String getNazwa()
    {
        return nazwa;
    }
}
