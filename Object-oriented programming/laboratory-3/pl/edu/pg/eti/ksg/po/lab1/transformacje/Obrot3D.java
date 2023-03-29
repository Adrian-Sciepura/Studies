package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import java.lang.Math;
public class Obrot3D implements Transformacja3D
{
    private final double kat;
    public Obrot3D(double kat)
    {
        this.kat = kat;
    }

    @Override
    public Punkt3D transformuj(Punkt3D p)
    {
        double sinA = Math.sin(kat);
        double cosA = Math.cos(kat);
        return new Punkt3D(p.getX(),
                p.getY() * cosA - p.getZ() * sinA,
                p.getY() * sinA + p.getZ() * cosA);
    }
    @Override
    public Transformacja3D getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException
    {
        return new Obrot3D(-kat);
    }
    public double getKat()
    {
        return this.kat;
    }
}
