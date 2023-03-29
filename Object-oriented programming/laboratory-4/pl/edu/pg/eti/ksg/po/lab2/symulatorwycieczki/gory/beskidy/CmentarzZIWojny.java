package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class CmentarzZIWojny extends Atrakcja
{
    private String nazwa;

    public CmentarzZIWojny(String nazwa) {
        super(1/3);
        this.nazwa = nazwa;
    }
    @Override
    public String getNazwa()
    {
        return nazwa;
    }
}
