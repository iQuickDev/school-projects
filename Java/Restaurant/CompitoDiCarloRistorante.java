package restaurant;

public class Restaurant
{
    public static void main(String[] args)
    {
        Ingrediente pomodoro = new Ingrediente("pomodoro", 100, 3);
        Ingrediente origano = new Ingrediente("origano", 10, 1);
        Ingrediente olio = new Ingrediente("olio", 25, 2);
        Ingrediente mais = new Ingrediente("mais", 50, 3);
        Ingrediente pasta = new Ingrediente("pasta", 200, 10);
        Ingrediente gnocchi = new Ingrediente("gnocchi", 100, 10);
        Ingrediente pesto = new Ingrediente("pesto", 100, 10);
        Ingrediente parmigiano = new Ingrediente("parmigiano", 100, 5);
        
        Piatto pastaAlPomodoro = new Piatto("pasta al pomodoro", "primo");
        pastaAlPomodoro.addIngrediente(pasta);
        pastaAlPomodoro.addIngrediente(pomodoro);
        Piatto pastaAllOlio = new Piatto("pasta all'olio", "primo");
        pastaAllOlio.addIngrediente(pasta);
        pastaAllOlio.addIngrediente(olio);
        Piatto gnocchiAlPesto = new Piatto("gnocchi al pesto", "primo");
        gnocchiAlPesto.addIngrediente(gnocchi);
        gnocchiAlPesto.addIngrediente(pesto);
        gnocchiAlPesto.addIngrediente(parmigiano);
        
        Ristorante ristorante = new Ristorante();
        
        ristorante.addPiatto(pastaAllOlio);
        ristorante.addPiatto(gnocchiAlPesto);
        ristorante.addPiatto(pastaAlPomodoro);
        
        Ordine o1 = new Ordine_Tavolo("0", 10, "Andrea");
        o1.addPiatto(pastaAllOlio);
        o1.addPiatto(gnocchiAlPesto);
        
        Ordine o2 = new Ordine_Domicilio("1", "Via Verdi, 27", 21);
        o2.addPiatto(pastaAlPomodoro);
        
        ristorante.addOrdine(o1);
        ristorante.addOrdine(o2);
        
        ristorante.showOrdiniCameriere("Andrea");
        System.out.println("-------------------------------");
        ristorante.showPiattiTipo("primo");
        System.out.println("-------------------------------");
        ristorante.showOrdiniOrario();
    }
    
}
