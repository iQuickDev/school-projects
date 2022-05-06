package registro;

import java.util.ArrayList;

public class Materia
{
    private String nome;
    private ArrayList<Double> voti = new ArrayList<>();
    
    public Materia(String nome)
    {
        this.nome = nome;
    }
    
    public void addVoto(Double voto)
    {
        voti.add(voto);
    }
    
    public int getVotiCount()
    {
        return voti.size();
    }
    
    public String getNome()
    {
        return this.nome;
    }
}
