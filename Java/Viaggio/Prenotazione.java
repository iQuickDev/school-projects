package viaggio;

public class Prenotazione {
    private final String cognome;
    private final String nome;
    private final String telefono;
    private final String partenza;
    private final String destinazione;
    private final String data;

    public Prenotazione(String cognome, String nome, String telefono, String partenza, String destinazione, String data) {
        this.cognome = cognome;
        this.nome = nome;
        this.telefono = telefono;
        this.partenza = partenza;
        this.destinazione = destinazione;
        this.data = data;
    }

    public String getCognome() {
        return cognome;
    }

    public String getNome() {
        return nome;
    }

    public String getTelefono() {
        return telefono;
    }

    public String getPartenza() {
        return partenza;
    }

    public String getDestinazione() {
        return destinazione;
    }

    public String getData() {
        return data;
    }

    public String toString() {
        return "Prenotazione: " + cognome + " " + nome + " " + telefono + " " + partenza + " " + destinazione + " " + data;
    }
}
