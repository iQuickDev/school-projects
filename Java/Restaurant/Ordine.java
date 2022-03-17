package restaurant;

import java.util.ArrayList;

public abstract class Ordine {
    
    protected String codice;
    protected double costo;
    protected ArrayList<Piatto> piatti = new ArrayList<Piatto>();

    public Ordine(String codice)
    {
        this.codice = codice;
    }
    
    public void addPiatto(Piatto x)
    {
        piatti.add(x);
        this.aggiornaCosto();
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
        this.aggiornaCosto();
    }
    
    public double getCosto()
    {
        return this.costo;
    }
    
    public String getCodice() {
        return codice;
    }

    public ArrayList<Piatto> getPiatti() {
        return piatti;
    }

    public void setCodice(String codice) {
        this.codice = codice;
    }

    public void setPiatti(ArrayList<Piatto> piatti) {
        this.piatti = piatti;
    }
    
    public void aggiornaCosto()
    {
        this.costo = 0;
        
        for (Piatto p : piatti)
        {
            this.costo += p.getCosto();
        }
    }
    
    public String toString()
    {
        String stringaOrdine = "Codice: " + this.codice + "\nCosto: " + this.getCosto() + "\nPiatti:\n";
        
        for (Piatto p : piatti)
        {
            stringaOrdine += p.getNome() + "\n";
        }
        
        return stringaOrdine;
    }
}
