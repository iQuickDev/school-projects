package registro;

import javax.swing.*;
import java.awt.*;

public class FormRegistro extends JFrame
{
    private final JLabel codiceLabel;
    private final JLabel materiaLabel;
    private final JLabel votoLabel;
    private final JTextField codiceField;
    private final JTextField materiaField;
    private final JTextField votoField;
    private final JPanel sopra;
    private final JPanel centro;
    private final JPanel sotto;
    private final JButton conferma;
    private final JButton annulla;
    private JLabel outputCodice;
    private JLabel outputVotiMateria;
    private JLabel outputVotiTotali;
    private Registro registro = new Registro();
    private int votiAggiunti = 0;
    
    public FormRegistro()
    {
        super("Registro Elettronico");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new BorderLayout());
        this.setSize(400,200);
        codiceLabel = new JLabel("Codice studente: ");
        materiaLabel = new JLabel("Materia: ");
        votoLabel = new JLabel("Voto: ");
        conferma = new JButton("Conferma");
        annulla = new JButton("Annulla");
        outputCodice = new JLabel(" ");
        outputVotiMateria = new JLabel(" ");
        outputVotiTotali = new JLabel(" ");
        codiceField = new JTextField();
        materiaField = new JTextField();
        votoField = new JTextField();
        sopra = new JPanel();
        sopra.add(codiceLabel);
        sopra.add(codiceField);
        sopra.add(materiaLabel);
        sopra.add(materiaField);
        sopra.add(votoLabel);
        sopra.add(votoField);
        sotto = new JPanel();
        sotto.add(conferma);
        sotto.add(annulla);
        centro = new JPanel();
        centro.add(outputCodice);
        centro.add(outputVotiMateria);
        centro.add(outputVotiTotali);
        sopra.setLayout(new GridLayout(3,2));
        sotto.setLayout(new GridLayout(1,2));
        centro.setLayout(new GridLayout(3,1));
        this.add(sopra, BorderLayout.NORTH);
        this.add(centro, BorderLayout.CENTER);
        this.add(sotto, BorderLayout.SOUTH);
        this.setVisible(true);
        
        conferma.addActionListener(e -> {
            votiAggiunti++;
            registro.addStudente(codiceField.getText());
            registro.addMateria(codiceField.getText(), materiaField.getText());
            registro.addVoto(codiceField.getText(), materiaField.getText(), Double.parseDouble(votoField.getText()));
            UpdateLabels(codiceField.getText(), materiaField.getText());
        });
        
        annulla.addActionListener(e -> {
            materiaField.setText("");
            votoField.setText("");
            codiceField.setText("");
        });
    }
    
    public void UpdateLabels(String codice, String materia)
    {
        outputCodice.setText("Codice studente inserito: " + codice);
        outputVotiTotali.setText("Voti totali inseriti: " + votiAggiunti);

        for (Studente s : registro.getStudenti())
        {
            if (s.getCodice().equals(codice))
            { 
               for (Materia m : s.getMaterie())
               {
                   if (m.getNome().equals(materia))
                   {
                       outputVotiMateria.setText("Voti della materia inseriti: " + m.getVotiCount());
                   }
               }
            }
        }
    }
}
