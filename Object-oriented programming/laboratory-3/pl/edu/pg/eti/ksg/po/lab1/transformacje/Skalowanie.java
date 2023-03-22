package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Skalowanie implements Transformacja
{
    private final double skalaX, skalaY;
    public Skalowanie(double skalaX, double skalaY)
    {
        this.skalaX = skalaX;
        this.skalaY = skalaY;
    }
    @Override
    public Punkt transformuj(Punkt p)
    {
        return new Punkt(this.skalaX * p.getX(), skalaY * p.getY());
    }
    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException
    {
        if(this.skalaX == 0 || this.skalaY == 0)
            throw new BrakTransformacjiOdwrotnejException("Brak transformacji odwrotnej. Przynajmniej jeden z czynników skalowania jest równy 0");

        return new Skalowanie(1/skalaX, 1/skalaY);
    }
    public double getSkalaX()
    {
        return this.skalaX;
    }
    public double getSkalaY()
    {
        return this.skalaY;
    }
    @Override
    public String toString()
    {
        return "Skalowanie " + skalaX + "x oraz " + skalaY + "y";
    }
}
