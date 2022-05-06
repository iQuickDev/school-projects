package registro;

import java.util.ArrayList;

public class Studente
{
    private String codice;
    private ArrayList<Materia> materie = new ArrayList<>();
    
    public Studente(String codice)
    {
        this.codice = codice;
    }
    
    public ArrayList<Materia> getMaterie()
    {
        ArrayList<Materia> arr = new ArrayList<>();
        
        for (Materia m : materie)
        {
            arr.add(m);
        }
        
        return arr;
    }
    
    public void addMateria(Materia m)
    {
        materie.add(m);
    }
    
    public String getCodice()
    {
        return this.codice;
    }
    
}
