package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.Atrakcja;

public class ChatkaStudencka extends Atrakcja
{
    private String nazwa, nazwaOpiekuna;

    public ChatkaStudencka(String nazwa, String nazwaOpiekuna) {
        super(0.5);
        this.nazwaOpiekuna = nazwaOpiekuna;
        this.nazwa = nazwa;
    }
    @Override
    public String getNazwa()
    {
        return nazwa;
    }
    public String getNazwaOpiekuna()
    {
        return this.nazwaOpiekuna;
    }
}
