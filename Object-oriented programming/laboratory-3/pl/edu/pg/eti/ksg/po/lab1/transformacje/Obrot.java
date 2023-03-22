package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import java.lang.Math;
public class Obrot implements Transformacja
{
    private final double kat;
    public Obrot(double kat)
    {
        this.kat = kat;
    }
    @Override
    public Punkt transformuj(Punkt p)
    {
        double sinA = Math.sin(kat);
        double cosA = Math.cos(kat);

        return new Punkt(p.getX() * cosA - p.getY() * sinA,
                p.getX() * sinA + p.getY() * cosA);
    }
    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException
    {
        return new Obrot(-kat);
    }
    public double getKat()
    {
        return this.kat;
    }
}
