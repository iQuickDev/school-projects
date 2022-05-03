import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception
    {
        ArrayList<Giocatore> giocatori = new ArrayList<>();

        Giocatore g1 = new Giocatore("yang");
        Giocatore g2 = new Giocatore("battistini");
        Giocatore g3 = new Giocatore("vlan");
        
        giocatori.add(g1);
        giocatori.add(g2);
        giocatori.add(g3);

        System.out.println("MAIN PARTITA INIZIATA");

        g1.start();
        g2.start();
        g3.start();

        g1.join();
        g2.join();
        g3.join();

        if (g1.getCartaEstratta() == g2.getCartaEstratta() || g1.getCartaEstratta() == g3.getCartaEstratta() || g2.getCartaEstratta() == g3.getCartaEstratta())
        {
            System.out.println("I GIOCATORI HANNO PAREGGIATO");
            return;
        }

        int max = Math.max(Math.max(g1.getCartaEstratta(), g2.getCartaEstratta()),g3.getCartaEstratta());

        for (Giocatore g : giocatori)
        {
            if (g.getCartaEstratta() == max)
            {
                System.out.println("IL GIOCATORE " + g.getName() + " HA VINTO CON " + g.getCartaEstratta());
            }
        }
    }
}
