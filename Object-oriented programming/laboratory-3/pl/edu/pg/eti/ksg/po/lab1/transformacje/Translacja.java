package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Translacja implements Transformacja
{
    private final double dX, dY;
    public Translacja(double dX, double dY)
    {
        this.dX = dX;
        this.dY = dY;
    }
    @Override
    public Punkt transformuj(Punkt p)
    {
        return new Punkt(p.getX() + dX, p.getY() + dY);
    }
    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException
    {
        return new Translacja(-dX, -dY);
    }
    public double getdX()
    {
        return this.dX;
    }
    public double getdY()
    {
        return this.dY;
    }
    @Override
    public String toString()
    {
        return "Translacja o wektor (" + dX + ", " + dY + ")";
    }
}
