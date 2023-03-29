package pl.edu.pg.eti.ksg.po.lab1.transformacje;

import java.util.ArrayList;

public class ZlozenieTransformacji3D implements Transformacja3D
{
    private ArrayList<Transformacja3D> transformacje;
    public ZlozenieTransformacji3D()
    {
        this.transformacje = new ArrayList<Transformacja3D>();
    }
    public ZlozenieTransformacji3D(Transformacja3D... t)
    {
        this();
        for(Transformacja3D x: t)
        {
            transformacje.add(x);
        }
    }
    public void dodajTransformacje(Transformacja3D t)
    {
        this.transformacje.add(t);
    }
    @Override
    public Punkt3D transformuj(Punkt3D p)
    {
        Punkt3D temp = new Punkt3D(p);
        for(Transformacja3D t: this.transformacje)
        {
            temp = t.transformuj(temp);
        }
        return temp;
    }
    @Override
    public Transformacja3D getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException
    {
        ZlozenieTransformacji3D temp = new ZlozenieTransformacji3D();
        for(int i = transformacje.size() - 1; i >= 0; i--)
        {
            temp.dodajTransformacje(transformacje.get(i).getTransformacjaOdwrotna());
        }
        return temp;
    }
}
