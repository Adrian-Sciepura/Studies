package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.sudety;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class WychodnieSkalne extends Atrakcja
{
    private String nazwa;

    public WychodnieSkalne(String nazwa) {
        super(1/6);
        this.nazwa = nazwa;
    }
    @Override
    public String getNazwa()
    {
        return nazwa;
    }
}
