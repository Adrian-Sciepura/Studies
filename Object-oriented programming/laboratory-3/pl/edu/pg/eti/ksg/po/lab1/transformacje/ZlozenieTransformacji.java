package pl.edu.pg.eti.ksg.po.lab1.transformacje;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class ZlozenieTransformacji implements Transformacja
{
    private ArrayList<Transformacja> transformacje;
    public ZlozenieTransformacji()
    {
         this.transformacje = new ArrayList<Transformacja>();
    }
    public ZlozenieTransformacji(Transformacja... t)
    {
        this();
        for(Transformacja x: t)
        {
            transformacje.add(x);
        }
    }
    public void dodajTransformacje(Transformacja t)
    {
        this.transformacje.add(t);
    }
    @Override
    public Punkt transformuj(Punkt p)
    {
        Punkt temp = new Punkt(p);
        for(Transformacja t: this.transformacje)
        {
            temp = t.transformuj(temp);
        }
        return temp;
    }
    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException
    {
        ZlozenieTransformacji temp = new ZlozenieTransformacji();
        for(int i = transformacje.size() - 1; i >= 0; i--)
        {
            temp.dodajTransformacje(transformacje.get(i).getTransformacjaOdwrotna());
        }
        return temp;
    }
}
