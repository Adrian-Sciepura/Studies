package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class DrewnianaCerkiew extends Atrakcja {

    private String nazwa;
    public DrewnianaCerkiew(String nazwa) {
        super(0.5);
        this.nazwa = nazwa;
    }
    @Override
    public String getNazwa() {
        return nazwa;
    }
}
