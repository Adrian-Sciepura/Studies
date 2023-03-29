package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.sudety;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class ObserwatoriumMeteorlogiczne extends Atrakcja
{
    private String nazwa;

    public ObserwatoriumMeteorlogiczne(String nazwa) {
        super(1.0);
        this.nazwa = nazwa;
    }
    @Override
    public String getNazwa()
    {
        return nazwa;
    }
}
