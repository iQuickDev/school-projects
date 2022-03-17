package restaurant;

public class Ingrediente
{
    String descrizione;
    int qta;
    float prezzo;
    
    public Ingrediente(String descrizione, int qta, int prezzo)
    {
        this.descrizione = descrizione;
        this.qta = qta;
        this.prezzo = prezzo;
    }
    
    public Ingrediente(Ingrediente ingrediente)
    {
        this.descrizione = ingrediente.descrizione;
        this.qta = ingrediente.qta;
        this.prezzo = ingrediente.prezzo;
    }

    public String getDescrizione()
    {
        return descrizione;
    }

    public int getQta()
    {
        return qta;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public void setQta(int qta) {
        this.qta = qta;
    }

    public void setPrezzo(float prezzo) {
        this.prezzo = prezzo;
    }
    
    
}
