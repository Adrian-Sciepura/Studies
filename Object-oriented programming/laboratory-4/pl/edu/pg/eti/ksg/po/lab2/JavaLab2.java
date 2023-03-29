package pl.edu.pg.eti.ksg.po.lab2;

import java.util.HashSet;
import java.util.Set;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.*;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Droga;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Las;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Panorama;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.Schronisko;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy.*;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.sudety.ObserwatoriumMeteorlogiczne;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.sudety.WychodnieSkalne;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Czlowiek;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.PrzewodnikStudencki;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.Student;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie.StudentKSG;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.niziny.biebrza.BlotnistaDroga;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.niziny.biebrza.ZalanyLas;

/**
 *
 * @author TB
 */
public class JavaLab2 {
    public static void main(String[] args) {
        Wycieczka w = wGory();
        
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
                if(i <= lp)
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

    public static Wycieczka wGory() {
        Wycieczka w = new Wycieczka("W Gory");
        w.dodajElementWycieczki(new ZalanyLas(3.0));
        w.dodajElementWycieczki(new BlotnistaDroga(2.0));
        w.dodajElementWycieczki(new CmentarzZIWojny("Cmentarz"));
        w.dodajElementWycieczki(new Droga(2.0));
        w.dodajElementWycieczki(new ChatkaStudencka("Chatka Studencka", "PG"));
        w.dodajElementWycieczki(new WychodnieSkalne("Wychodnie skalne"));
        w.dodajElementWycieczki(new ObserwatoriumMeteorlogiczne("Obserwatorium"));

        return w;
    }
   
}
