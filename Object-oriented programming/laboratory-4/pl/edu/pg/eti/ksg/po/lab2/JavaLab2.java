package pl.edu.pg.eti.ksg.po.lab2;

import java.util.HashSet;
import java.util.Set;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.*;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Droga;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Las;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Panorama;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Schronisko;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Blotostrada;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.DrewnianaCerkiew;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.Tory;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Czlowiek;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.PrzewodnikStudencki;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Student;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.StudentKSG;

/**
 *
 * @author TB
 */
public class JavaLab2 {
    public static void main(String[] args) {
        Wycieczka w = naETI();
        
        PrzewodnikStudencki przewodnik = new PrzewodnikStudencki("Stefan", "Długonogi", Czlowiek.Plec.MEZCZYZNA);
        Set<Uczestnik> uczestnicy = new HashSet<>();
        uczestnicy.add(new Student("Alojzy", "Mechanik", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new Student("Ada", "Lovelace", Czlowiek.Plec.KOBIETA));
        uczestnicy.add(new Student("Jan", "Elektronik", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new StudentKSG("Piotr","Teledetekcyjny", Czlowiek.Plec.MEZCZYZNA));
        
        Grupa g = new Grupa(przewodnik, uczestnicy);
        
        SymulatorWycieczki symulator = new SymulatorWycieczki(g, w);
        symulator.dodajSluchacza((ElementWycieczki elementWycieczki, int lp, int liczbaElementow) -> {
            System.out.println("Element: " + elementWycieczki.getNazwa());
            System.out.print("Postęp: ");
            for(int i = 0; i < liczbaElementow; i++)
            {
                if(i < lp)
                    System.out.print('█');
                else
                    System.out.print('░');
            }
            System.out.println();
        } );

        symulator.symuluj();
    }
    
    public static Wycieczka doDydiowki() {
        Wycieczka ret = new Wycieczka("Do Dydiówki");
        ret.dodajElementWycieczki(new Droga(1.0));
        ret.dodajElementWycieczki(new DrewnianaCerkiew("Smolnik"));
        ret.dodajElementWycieczki(new Droga(4.0));
//        ret.dodajElementWycieczki(new PrzeprawaPrzezRzeke(1.0));
//        ret.dodajElementWycieczki(new GestyLas(2.0));
        ret.dodajElementWycieczki(new Las(2.0));
        ret.dodajElementWycieczki(new Droga(5.0));
        
        return ret;
    }

    public static Wycieczka naETI() {
        Wycieczka w = new Wycieczka("Na wydział ETI");
        w.dodajElementWycieczki(new Droga(3.0));
        w.dodajElementWycieczki(new Tory(8.0));
        w.dodajElementWycieczki(new Panorama("Przystanek Miszewskiego"));
        w.dodajElementWycieczki(new Blotostrada(5.0));
        w.dodajElementWycieczki(new Schronisko("Wydział ETI"));
        w.dodajElementWycieczki(new Droga(2.0));
        w.dodajElementWycieczki(new Panorama("NE 237"));

        return w;
    }
   
}
