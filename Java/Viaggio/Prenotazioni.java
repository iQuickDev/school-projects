package viaggio;

import java.util.ArrayList;

public class Prenotazioni {
    public static ArrayList<Prenotazione> prenotazioni = new ArrayList<>();

    public static void addPrenotazione(Prenotazione prenotazione)
    {
        prenotazioni.add(prenotazione);
    }

    public static int checkPrenotazioneByDate(String date)
    {
        int count = 0;
        for(Prenotazione prenotazione : prenotazioni)
        {
            if(prenotazione.getData().equals(date))
            {
                count++;
            }
        }
        return count;
    }
}
