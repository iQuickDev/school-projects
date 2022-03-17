package restaurant;

public class Ordine_Domicilio extends Ordine
{
    private String indirizzo;
    public final double COSTO_CONSEGNA = 3;
    private int ora;
    
    public Ordine_Domicilio(String codice, String indirizzo, int ora)
    {
        super(codice);
        this.indirizzo = indirizzo;
        this.ora = ora;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public int getOra() {
        return ora;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public void setOra(int ora) {
        this.ora = ora;
    }
    
    public void aggiornaCosto()
    {
        this.costo = 0;
        
        for (Piatto p : piatti)
        {
            this.costo += p.getCosto();
        }
        
        this.costo += COSTO_CONSEGNA;
    }
}
