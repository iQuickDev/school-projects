public class Giocatore extends Thread
{
    private int cartaEstratta;

    public Giocatore(String nome)
    {
        super(nome);
    }

    public int getCartaEstratta()
    {
        return this.cartaEstratta;
    }

    @Override
    public void run()
    {
        System.out.println("Il giocatore " + this.getName() + " sta giocando...");
        this.cartaEstratta = (int)(10*Math.random())+1;
        System.out.println("Il giocatore " + this.getName() + " ha pescato " + this.getCartaEstratta());
    }
}