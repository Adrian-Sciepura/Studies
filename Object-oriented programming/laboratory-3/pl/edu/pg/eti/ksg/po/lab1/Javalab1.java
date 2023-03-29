package pl.edu.pg.eti.ksg.po.lab1;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.*;
import sun.awt.geom.AreaOp;

import java.sql.SQLOutput;
import java.util.SortedMap;

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

//        try
//        {
//            Punkt p1 = Punkt.E_X;
//            System.out.println(p1);
//            Transformacja zl = new ZlozenieTransformacji(new Translacja(5, 6), new Skalowanie(2, 3));
//            Punkt p2 = zl.transformuj(p1);
//            System.out.println(p2);
//            Transformacja zl2 = zl.getTransformacjaOdwrotna();
//            Punkt p3 = zl2.transformuj(p2);
//            System.out.println(p3);
//        }
//        catch (BrakTransformacjiOdwrotnejException ex)
//        {
//            ex.printStackTrace();
//        }

        try
        {
            Punkt3D p1 = new Punkt3D(0, 0, 0);
            System.out.println(p1);
            Transformacja3D tr1 = new Translacja3D(6, 8 ,10);
            Punkt3D p2 = tr1.transformuj(p1);
            System.out.println(p2);
            Transformacja3D tr2 = new Obrot3D(Math.toRadians(60));
            Punkt3D p3 = tr2.transformuj(p2);
            System.out.println(p3);
            Transformacja3D tr3 = tr2.getTransformacjaOdwrotna();
            Punkt3D p4 = tr3.transformuj(p3);
            System.out.println(p4);
            Transformacja3D tr4 = tr1.getTransformacjaOdwrotna();
            Punkt3D p5 = tr4.transformuj(p4);
            System.out.println(p5);
            //System.out.println(p4.getY());

        }
        catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }

        System.out.println();

        try
        {
            Punkt3D p1 = new Punkt3D(0, 0, 0);
            System.out.println(p1);
            Transformacja3D t = new ZlozenieTransformacji3D(new Translacja3D(6, 8 ,10), new Obrot3D(Math.toRadians(60)));
            Punkt3D p2 = t.transformuj(p1);
            System.out.println(p2);
            Transformacja3D t2 = t.getTransformacjaOdwrotna();
            Punkt3D p3 = t2.transformuj(p2);
            System.out.println(p3);

        }
        catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
    }
}