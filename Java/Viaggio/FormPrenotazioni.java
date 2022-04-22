package viaggio;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class FormPrenotazioni extends JFrame
{
    protected final JPanel sopra = new JPanel(new GridLayout(6, 2));

    protected final JLabel cognomeLabel = new JLabel("Cognome: ");
    protected final JTextField cognome = new JTextField();

    protected final JLabel nomeLabel = new JLabel("Nome: ");
    protected final JTextField nome = new JTextField();

    protected final JLabel telefonoLabel = new JLabel("Telefono: ");
    protected final JTextField telefono = new JTextField();

    protected final JLabel partenzaLabel = new JLabel("Città Partenza: ");
    protected final JTextField partenza = new JTextField();

    protected final JLabel destinazioneLabel = new JLabel("Città Destinazione: ");
    protected final JTextField destinazione = new JTextField();

    protected final JLabel dataLabel = new JLabel("Data: ");
    protected final JTextField data = new JTextField();

    protected final JPanel sotto = new JPanel(new GridLayout(1, 2));

    protected final JButton conferma = new JButton("Conferma");
    protected final JButton annulla = new JButton("Annulla");

    protected final JLabel info = new JLabel("INFO", JLabel.CENTER);

    public FormPrenotazioni()
    {
        super("Prenota il tuo biglietto!");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(500, 400);
        setLayout(new BorderLayout());

        sopra.add(cognomeLabel);
        sopra.add(cognome);
        sopra.add(nomeLabel);
        sopra.add(nome);
        sopra.add(telefonoLabel);
        sopra.add(telefono);
        sopra.add(partenzaLabel);
        sopra.add(partenza);
        sopra.add(destinazioneLabel);
        sopra.add(destinazione);
        sopra.add(dataLabel);
        sopra.add(data);
        add(sopra, BorderLayout.NORTH);

        sotto.add(conferma);
        sotto.add(annulla);
        add(sotto, BorderLayout.SOUTH);
        add(info, BorderLayout.CENTER);

        conferma.setEnabled(false);
        annulla.setEnabled(false);

        cognome.getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {

            }
            public void removeUpdate(DocumentEvent e) {

            }
            public void insertUpdate(DocumentEvent e) {
                if (cognome.getText().matches(".*\\d.*"))
                {
                    Runnable change = new Runnable()
                    {
                        public void run()
                        {
                            cognome.setText("" + cognome.getText().substring(0, cognome.getText().length() - 1));
                        }
                    };
                    SwingUtilities.invokeLater(change);
                }
                checkInputs();
            }
        });


        nome.getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {

            }
            public void removeUpdate(DocumentEvent e) {

            }
            public void insertUpdate(DocumentEvent e) {
                if (nome.getText().matches(".*\\d.*"))
                {
                    Runnable change = new Runnable()
                    {
                        public void run()
                        {
                            nome.setText("" + nome.getText().substring(0, nome.getText().length() - 1));
                        }
                    };
                    SwingUtilities.invokeLater(change);
                }
                checkInputs();
            }
        });

        telefono.getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {

            }
            public void removeUpdate(DocumentEvent e) {

            }
            public void insertUpdate(DocumentEvent e) {
                if (!telefono.getText().matches("[0-9]+") || telefono.getText().length() > 10)
                {
                    Runnable change = new Runnable()
                    {
                        public void run()
                        {
                            telefono.setText("" + telefono.getText().substring(0, telefono.getText().length() - 1));
                        }
                    };
                    SwingUtilities.invokeLater(change);
                }
                checkInputs();
            }
        });

        partenza.getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {

            }
            public void removeUpdate(DocumentEvent e) {

            }
            public void insertUpdate(DocumentEvent e) {
                if (partenza.getText().matches(".*\\d.*"))
                {
                    Runnable change = new Runnable()
                    {
                        public void run()
                        {
                            partenza.setText("" + partenza.getText().substring(0, partenza.getText().length() - 1));
                        }
                    };
                    SwingUtilities.invokeLater(change);
                }
                checkInputs();
            }
        });

        destinazione.getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {

            }
            public void removeUpdate(DocumentEvent e) {

            }
            public void insertUpdate(DocumentEvent e) {
                if (destinazione.getText().matches(".*\\d.*"))
                {
                    Runnable change = new Runnable()
                    {
                        public void run()
                        {
                            destinazione.setText("" + destinazione.getText().substring(0, destinazione.getText().length() - 1));
                        }
                    };
                    SwingUtilities.invokeLater(change);
                }
                checkInputs();
            }
        });

        data.getDocument().addDocumentListener(new DocumentListener() {
            public void changedUpdate(DocumentEvent e) {

            }
            public void removeUpdate(DocumentEvent e) {

            }
            public void insertUpdate(DocumentEvent e) {
                if (!data.getText().matches(".*\\d.*"))
                {
                    Runnable change = new Runnable()
                    {
                        public void run()
                        {
                            data.setText("" + data.getText().substring(0, data.getText().length() - 1));
                        }
                    };
                    SwingUtilities.invokeLater(change);
                }
                checkInputs();
            }
        });

        conferma.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                    String name = nome.getText();
                    String surname = cognome.getText();
                    String phone = telefono.getText();
                    String start = partenza.getText();
                    String end = destinazione.getText();
                    String date = data.getText();
                    Prenotazioni.addPrenotazione(new Prenotazione(name, surname, phone, start, end, date));
                clearFields();
                conferma.setEnabled(false);
                info.setText("Prenotazione avvenuta con successo!");
                int cnt = Prenotazioni.checkPrenotazioneByDate(date);
                if (cnt > 1)
                    info.setText("Prenotazioni per questa data: " + cnt);
                annulla.setEnabled(false);
            }
        });

        annulla.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                clearFields();
                conferma.setEnabled(false);
                annulla.setEnabled(false);
            }
        });
    }


    private void clearFields()
    {
        cognome.setText("");
        nome.setText("");
        telefono.setText("");
        partenza.setText("");
        destinazione.setText("");
        data.setText("");
    }

    private void checkInputs()
    {
        conferma.setEnabled(!cognome.getText().equals("")
                && !nome.getText().equals("")
                && !telefono.getText().equals("")
                && !partenza.getText().equals("")
                && !destinazione.getText().equals("")
                && !data.getText().equals(""));
        annulla.setEnabled(!cognome.getText().equals("")
                || !nome.getText().equals("")
                || !telefono.getText().equals("")
                || !partenza.getText().equals("")
                || !destinazione.getText().equals("")
                || !data.getText().equals(""));
    }
}