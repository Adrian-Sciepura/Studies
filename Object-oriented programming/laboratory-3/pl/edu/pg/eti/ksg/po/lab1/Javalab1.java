package pl.edu.pg.eti.ksg.po.lab1;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.*;

public class Javalab1
{
    public static void main(String[] args)
    {
//        try
//        {
//            Punkt p1 = Punkt.E_X;
//            System.out.println(p1);
//            Transformacja tr = new Translacja(5, 6);
//            System.out.println(tr);
//            Punkt p2 = tr.transformuj(p1);
//            System.out.println(p2);
//            Transformacja trr = tr.getTransformacjaOdwrotna();
//            System.out.println(trr);
//            Punkt p3 = trr.transformuj(p2);
//            System.out.println(p3);
//        }
//        catch (BrakTransformacjiOdwrotnejException ex)
//        {
//            ex.printStackTrace();
//        }
//        System.out.println();
//
//        try
//        {
//            Punkt p1 = new Punkt(2, 2);
//            System.out.println(p1);
//            Transformacja tr2 = new Skalowanie(5, 4);
//            System.out.println(tr2);
//            Punkt p2 = tr2.transformuj(p1);
//            System.out.println(p2);
//            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
//            System.out.println(trr2);
//            Punkt p3 = trr2.transformuj(p2);
//            System.out.println(p3);
//        }
//        catch(BrakTransformacjiOdwrotnejException ex)
//        {
//            ex.printStackTrace();
//        }
//        System.out.println();
//
//        try
//        {
//            Punkt p1 = new Punkt(2, 2);
//            Transformacja tr2 = new Skalowanie(5, 0);
//            System.out.println(tr2);
//            System.out.println(p1);
//            Punkt p2 = tr2.transformuj(p1);
//            System.out.println(p2);
//            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
//            System.out.println(trr2);
//            Punkt p3 = trr2.transformuj(p2);
//            System.out.println(p3);
//        }
//        catch(BrakTransformacjiOdwrotnejException ex)
//        {
//            ex.printStackTrace();
//        }
//        System.out.println();


//        try
//        {
//            Punkt p1 = new Punkt(10, 10);
//            Transformacja t = new Obrot(Math.toRadians(45));
//            Punkt p2 = t.transformuj(p1);
//            System.out.println(p2);
//            Transformacja t2 = t.getTransformacjaOdwrotna();
//            Punkt p3 = t2.transformuj(p2);
//            System.out.println(p3);
//        }
//        catch (BrakTransformacjiOdwrotnejException ex)
//        {
//            ex.printStackTrace();
//        }
        try
        {
            Punkt p1 = Punkt.E_X;
            System.out.println(p1);
            Transformacja zl = new ZlozenieTransformacji(new Translacja(5, 6), new Skalowanie(2, 3));
            Punkt p2 = zl.transformuj(p1);
            System.out.println(p2);
            Transformacja zl2 = zl.getTransformacjaOdwrotna();
            Punkt p3 = zl2.transformuj(p2);
            System.out.println(p3);
        }
        catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
    }
}