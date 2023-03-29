package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class Punkt {
    protected final double x, y;
    public Punkt(double x, double y)
    {
        this.x = x;
        this.y = y;
    }
    public Punkt(Punkt p)
    {
        this.x = p.x;
        this.y = p.y;
    }
    public double getX()
    {
        return this.x;
    }
    public double getY()
    {
        return this.y;
    }
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof Punkt)
        {
            Punkt temp = (Punkt)obj;
            return (this.x == temp.x && this.y == temp.y);
        }
        return false;
    }
    @Override
    public int hashCode()
    {
        return 23 * (Double.hashCode(this.x) + Double.hashCode(this.y));
    }
    @Override
    public String toString()
    {
        return "Punkt x: " + this.x + ", y: " + this.y;
    }
    public static final Punkt O = new Punkt(0,0);
    public static final Punkt E_X = new Punkt(1,0);
    public static final Punkt E_Y = new Punkt(0,1);
}
