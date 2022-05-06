package registro;

import java.util.ArrayList;

public class Registro
{
   private ArrayList<Studente> studenti = new ArrayList<>();
   
   public void addStudente(String codice)
   {
       for (Studente s : studenti)
       {
           if (s.getCodice().equals(codice))
           {
               return;
           }
       }
              
       studenti.add(new Studente(codice));
   }
   
   public void addMateria(String codice, String materia)
   {
       for (Studente s : studenti)
       {
           if (s.getCodice().equals(codice))
           {
               for (Materia m : s.getMaterie())
               {
                   if (m.getNome().equals(materia))
                   {
                       return;
                   }
               }
               s.addMateria(new Materia(materia));
           }
       }
   }
   
   public void addVoto(String codice, String materia, Double voto)
   {
       for (Studente s : studenti)
       {
           if (s.getCodice().equals(codice))
           {
                for (Materia m : s.getMaterie())
                {
                    if (m.getNome().equals(materia))
                    {
                        m.addVoto(voto);
                    }
                }
           }
       }
   }
   
   public ArrayList<Studente> getVoti(String codice)
   {
       ArrayList<Studente> arr = new ArrayList<>();
       
       for (Studente s : studenti)
       {
           if (s.getCodice().equals(codice))
              arr.add(s);
       }
       
       return arr;
   }
   
   public ArrayList<Studente> getStudenti()
   {
       ArrayList<Studente> arr = new ArrayList<>();
       
       for (Studente s : studenti)
       {
           arr.add(s);
       }
       
       return arr;
   }
}
