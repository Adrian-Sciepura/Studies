package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public interface Transformacja3D
{
    Punkt3D transformuj(Punkt3D p);
    Transformacja3D getTransformacjaOdwrotna()
            throws BrakTransformacjiOdwrotnejException;
}
