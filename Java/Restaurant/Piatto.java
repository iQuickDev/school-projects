package restaurant;

import java.util.ArrayList;

public class Piatto
{
    private String nome;
    private String tipo;
    private double costo;
    private ArrayList<Ingrediente> ingredienti = new ArrayList<Ingrediente>();

    public Piatto(String nome, String tipo)
    {
        this.nome = nome;
        this.tipo = tipo;
    }
   
    public void addIngrediente(Ingrediente x)
    {
        ingredienti.add(x);
        this.aggiornaCosto();
    }
    
    public void removeIngrediente(String descrizione)
    {
        for (Ingrediente i : ingredienti)
        {
            if (i.getDescrizione().equals(descrizione))
            {
                ingredienti.remove(i);
            }
        }
        
        this.aggiornaCosto();
    }
    
    private void aggiornaCosto()
    {
        this.costo = 0;
        
        for (Ingrediente i : ingredienti)
        {
            this.costo += (i.getPrezzo() * i.getQta());
        }
    }
    
    public String getNome() {
        return this.nome;
    }

    public String getTipo() {
        return tipo;
    }

    public double getCosto() {
        return costo;
    }

    public ArrayList<Ingrediente> getIngredienti() {
        return ingredienti;
    }
    
    public void setCosto(double costo)
    {
        this.costo = costo;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setIngredienti(ArrayList<Ingrediente> ingredienti) {
        this.ingredienti = ingredienti;
    }
    
    public String toString()
    {
        return "Nome: " + this.nome + "\nTipo: " + this.tipo + "\nCosto: " + this.costo + "\n";
    }
}
