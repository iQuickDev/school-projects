package libreria;

public class Libro
{
    private String codice;
    private String titolo;
    private double prezzo;
    
    public Libro(String codice, String titolo, double prezzo)
    {
        this.codice = codice;
        this.titolo = titolo;
        this.prezzo = prezzo;
    }

    public String getCodice() {
        return codice;
    }

    public String getTitolo() {
        return titolo;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public void setCodice(String codice) {
        this.codice = codice;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    @Override
    public String toString() {
        return "Libro{" + "codice=" + codice + ", titolo=" + titolo + ", prezzo=" + prezzo + '}';
    }
    
    
}
