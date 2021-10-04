#include <iostream>

using namespace std;

void main()
{
    const int lunghezzaarray = 1000;


    int scelta, v, contascatoloni = 0, mi = -1, larghezza[lunghezzaarray], lunghezza[lunghezzaarray], altezza[lunghezzaarray];

    do
    {
        cout << " ________________________________________________________" << endl;
        cout << "|                        MENU                            |" << endl;
        cout << "|________________________________________________________|" << endl;
        cout << "1. Inizializza array" << endl;
        cout << "2. Inserisci valori scatolone" << endl;
        cout << "3. Modifica valori scatolone" << endl;
        cout << "4. Visualizza valori scatolone" << endl;
        cout << "5. Calcola volume di uno spefico scatolone" << endl;
        cout << "6. Calcola volume totale di tutti gli scatoloni" << endl;
        cout << "7. Visualizza numero scatoloni" << endl;
        cout << "8. Esci" << endl << endl;
        cout << "Scelta: ";

        cin >> scelta;

        switch (scelta)
        {

        case 1:
            for (int i = 0; i < lunghezzaarray; i++)
            {
                larghezza[i] = 0;
                lunghezza[i] = 0;
                altezza[i] = 0;
            }
            contascatoloni = 0;
            cout << "Array inizializzato." << endl;
            break;

        case 2:
            cout << "Posizione scatola da inserire: ";
            cin >> v;
            if (larghezza[--v] == 0)
            {
                cout << "Inserire la larghezza della scatola: ";
                cin >> larghezza[v];
                cout << "Inserire la lunghezza della scatola: ";
                cin >> lunghezza[v];
                cout << "Inserire l'altezza della scatola: ";
                cin >> altezza[v];
                if (mi < v)
                    mi = v;
                contascatoloni++;
            }
            else
                cout << "Scatola esistente." << endl;
            break;

        case 3:
            cout << "Inserire la scatola a cui modificare i valori: ";
            cin >> v;
            if (larghezza[--v] == 0)
                cout << "Scatola non esistente." << endl;
            else
            {
                cout << "Inserire la nuova larghezza della scatola: ";
                cin >> larghezza[v];
                cout << "Inserire la nuova lunghezza della scatola: ";
                cin >> lunghezza[v];
                cout << "Inserire la nuova altezza della scatola: ";
                cin >> altezza[v];
            }
            break;

        case 4:
            cout << "Inserire il numero della scatola da visualizzare: ";
            cin >> v;
            cout << "Larghezza: " << larghezza[--v] << endl
                << "Lunghezza: " << lunghezza[v] << endl
                << "Altezza: " << altezza[v] << endl;
            break;

        case 5:
            cout << "Inserire il numero della scatola: ";
            cin >> v;
            v = larghezza[--v] * lunghezza[v] * altezza[v];
            cout << "Volume scatolone: " << v << endl;
            break;

        case 6:
            v = 0;
            for (int i = 0; i <= mi; i++)
                v += larghezza[i] * lunghezza[i] * altezza[i];
            cout << "Volume totale: " << v << endl;
            break;

        case 7:
            cout << "Numero scatoloni: " << contascatoloni << endl;
            break;

        case 8:
            cout << "Programma interrotto." << endl;
            break;

        default:
            cout << "Opzione non valida, reinserire." << endl;
            break;
        }
    } while (scelta != 8);
}