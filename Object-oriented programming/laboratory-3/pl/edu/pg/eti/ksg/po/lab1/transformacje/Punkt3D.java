package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Punkt3D extends Punkt
{
    private final double z;
    public Punkt3D(double x, double y, double z)
    {
        super(x, y);
        this.z = z;
    }
    public Punkt3D(Punkt3D punkt3D)
    {
        this(punkt3D.x, punkt3D.y, punkt3D.z);
    }
    public double getZ()
    {
        return this.z;
    }
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof Punkt3D)
        {
            Punkt3D temp = (Punkt3D)obj;
            return (this.x == temp.x && this.y == temp.y && this.z == temp.z);
        }
        return false;
    }
    @Override
    public int hashCode()
    {
        return 23 * (Double.hashCode(this.x) + Double.hashCode(this.y) + Double.hashCode(this.z));
    }
    @Override
    public String toString()
    {
        return "Punkt3D x: " + this.x + ", y: " + this.y + ", z: " + this.z;
    }
}
