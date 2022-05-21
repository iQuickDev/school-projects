package libreria;

import javax.swing.*;
import java.awt.*;

public class FormLibreria extends JFrame
{
    Libreria libreria = new Libreria();
    private JLabel codiceLabel;
    private JLabel titoloLabel;
    private JLabel prezzoLabel;
    private JTextField codiceField;
    private JTextField titoloField;
    private JTextField prezzoField;
    private JPanel sopra;
    private JPanel centro;
    private JPanel sotto;
    private JButton conferma;
    private JButton annulla;
    private JLabel outputCodice;
    private JLabel outputCopie;
    private JLabel outputLibriTotali;
    
    public FormLibreria()
    {
        super("Libreria");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new BorderLayout());
        this.setSize(400,200);
        codiceLabel = new JLabel("Codice ISBN: ");
        titoloLabel = new JLabel("Titolo: ");
        prezzoLabel = new JLabel("Prezzo: ");
        conferma = new JButton("Conferma");
        annulla = new JButton("Annulla");
        outputCodice = new JLabel(" ");
        outputCopie = new JLabel(" ");
        outputLibriTotali = new JLabel(" ");
        codiceField = new JTextField();
        titoloField = new JTextField();
        prezzoField = new JTextField();
        sopra = new JPanel();
        sopra.add(codiceLabel);
        sopra.add(codiceField);
        sopra.add(titoloLabel);
        sopra.add(titoloField);
        sopra.add(prezzoLabel);
        sopra.add(prezzoField);
        sotto = new JPanel();
        sotto.add(conferma);
        sotto.add(annulla);
        centro = new JPanel();
        centro.add(outputCodice);
        centro.add(outputCopie);
        centro.add(outputLibriTotali);
        sopra.setLayout(new GridLayout(3,2));
        sotto.setLayout(new GridLayout(1,2));
        centro.setLayout(new GridLayout(3,1));
        this.add(sopra, BorderLayout.NORTH);
        this.add(centro, BorderLayout.CENTER);
        this.add(sotto, BorderLayout.SOUTH);
        this.setVisible(true);
        
        conferma.addActionListener(e -> {
            libreria.addLibro(new Libro(codiceField.getText(), titoloField.getText(), Double.parseDouble(prezzoField.getText())));
            UpdateLabels(codiceField.getText());
        });
        
        annulla.addActionListener(e -> {
            codiceField.setText("");
            titoloField.setText("");
            prezzoField.setText("");
        });
    }
    
    public void UpdateLabels(String codice)
    {
        outputCodice.setText("Codice libro inserito: " + codice);
        outputCopie.setText("Copie del libro presenti in libreria: " + libreria.searchLibriByCodice(codice));
        outputLibriTotali.setText("Libri totali inseriti: " + libreria.searchLibriTotali());
    }
}