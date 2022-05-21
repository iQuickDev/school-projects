package libreria;

import java.util.ArrayList;

public class Libreria
{
   private ArrayList<Libro> libri = new ArrayList<>();
   
   public void addLibro(Libro l)
   {
       libri.add(l);
   }
   
   public int searchLibriByCodice(String c)
   {
       int count = 0;
       for (Libro l : libri)
       {
           if (l.getCodice().equals(c))
           {
               count++;
           }
       }
       
       return count;
   }
   
   public int searchLibriTotali()
   {
       return libri.size();
   }
}
