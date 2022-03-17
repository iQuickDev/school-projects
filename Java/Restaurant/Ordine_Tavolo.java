package restaurant;

public class Ordine_Tavolo extends Ordine
{
    private int numeroTavolo;
    private String nomeCameriere;

    public Ordine_Tavolo(String codice, int numeroTavolo, String nomeCameriere)
    {
        super(codice);
        this.numeroTavolo = numeroTavolo;
        this.nomeCameriere = nomeCameriere;
    }

    public int getNumeroTavolo() {
        return numeroTavolo;
    }

    public String getNomeCameriere() {
        return nomeCameriere;
    }

    public void setNumeroTavolo(int numeroTavolo) {
        this.numeroTavolo = numeroTavolo;
    }

    public void setNomeCameriere(String nomeCameriere) {
        this.nomeCameriere = nomeCameriere;
    }
    
    
}
