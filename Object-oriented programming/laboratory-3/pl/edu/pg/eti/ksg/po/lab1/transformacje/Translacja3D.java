package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Translacja3D implements Transformacja3D
{
    private final double dX, dY, dZ;
    public Translacja3D(double dX, double dY, double dZ)
    {
        this.dX = dX;
        this.dY = dY;
        this.dZ = dZ;
    }
    @Override
    public Punkt3D transformuj(Punkt3D p) {
        return new Punkt3D(p.getX() + dX, p.getY() + dY, p.getZ() + dZ);
    }
    @Override
    public Transformacja3D getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
        return new Translacja3D(-dX, -dY, -dZ);
    }
    public double getdX()
    {
        return this.dX;
    }
    public double getdY()
    {
        return this.dY;
    }
    public double getdZ()
    {
        return this.dZ;
    }
    @Override
    public String toString()
    {
        return "Translacja o wektor (" + dX + ", " + dY + ", " + dZ + ")";
    }
}
