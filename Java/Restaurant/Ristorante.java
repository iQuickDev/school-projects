package restaurant;

import java.util.ArrayList;

public class Ristorante
{
    private ArrayList<Piatto> piatti = new ArrayList<Piatto>();
    private ArrayList<Ordine> ordini = new ArrayList<Ordine>();

    public Ristorante()
    {
        
    }
    
    public void addPiatto(Piatto x)
    {
        piatti.add(x);
    }
    
    public void removePiatto(String nome)
    {
        for (Piatto p : piatti)
        {
            if (p.getNome().equals(nome))
            {
                piatti.remove(p);
            }
        }
    }
    
    public void addOrdine(Ordine x)
    {
        ordini.add(x);
    }
    
    public void removeOrdine(String codice)
    {
        ordini.remove(codice);
    }
    
    public void showOrdiniCameriere(String cameriere)
    {
        for (Ordine o : ordini)
        {
            if (o instanceof Ordine_Tavolo)
            {
                if (((Ordine_Tavolo) o).getNomeCameriere().equals(cameriere))
                System.out.println(o.toString());
            }
        }
    }
    
    public void showPiattiTipo(String tipo)
    {
        for (Piatto p : piatti)
        {
            if (p.getTipo().equals(tipo))
            {
                System.out.println(p.toString());
            }
        }
    }
    
    public void showOrdiniOrario()
    {
        for (Ordine o : ordini)
        {
            System.out.println(o.toString());
        }
    }
}
