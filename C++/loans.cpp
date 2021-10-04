#include <iostream>

using namespace std;

void main()
{
	int ct[10], cl[10], genere[10], prestito[31], opzione, nuovoct;
	char risp;

	// Inizializzazione array

	for (int i = 0; i < 5; i++)
	{
		ct[i] = 0;
		cl[i] = 0;
		genere[i] = 0;
		prestito[i] = 0;
	}
	// MENU
	do {
		cout << "[1] Inserisci prestito" << endl;
		cout << "[2] Visualizza prestiti" << endl;
		cout << "[3] Visualizza libri di genere romantico in un giorno del mese" << endl;
		cout << "[4] Visualizza il numero di libri presi in prestito da un associato" << endl;
		cout << "[5] Visualizza codice tessera di un associato con libro horror in prestito con input codice libro" << endl;
		cout << "[6] Modifica il codice tessera di un associato con input codice libro" << endl;
		cout << "[7] Elimina libro dai record con input codice tessera" << endl;
		cout << "[8] Chiudi programma" << endl;

		cout << "Opzione: ";
		cin >> opzione;

		switch (opzione)
		{
		case 1:
			risp = 's';
			for (int i = 0; risp == 's'; i++)
			{
				cout << "Inserisci codice tessera: ";
				cin >> ct[i];

				cout << "01 | Romantico" << endl;
				cout << "02 | Fantascienza" << endl;
				cout << "03 | Gialli" << endl;
				cout << "04 | Thriller" << endl;
				cout << "05 | Horror" << endl << endl;
				cout << "Inserisci genere: ";
				cin >> genere[i];
				cout << "Inserisci codice libro: ";
				cin >> cl[i];
				cout << "Inserisci giorno del prestito: ";
				cin >> prestito[i];
				cout << "Vuoi inserirne un altro ? (s/n) ";
				cin >> risp;
			}
			break;
		case 2:
			for (int i = 0; i < 5; i++)
			{
				cout << "-------------------------" << endl;
				cout << "Codice tessera: " << ct[i] << endl;
				cout << "Codice libro: " << cl[i] << endl;
				cout << "Genere: " << genere[i] << endl;
				cout << "Prestito giorno: " << prestito[i] << endl;
				cout << "-------------------------" << endl;
			}
			break;
		case 3:
			for (int i = 0; i < 1; i++)
			{
				cout << "Inserisci giorno di dicembre: ";
				cin >> prestito[i];

				if (genere[i] == 01)
				{
					cout << "Libri presi in prestito nel seguente giorno: " << endl;
					cout << genere[i] << endl;
				}
				else
					cout << "Nessun libro trovato per quel giorno" << endl;
			}
			break;
		case 4:
			for (int i = 0; i < 1; i++)
			{
				cout << "Inserisci codice tessera: ";
				cin >> ct[i];
				cout << "Codice libri presi dall'associato:" << endl << cl[i] << endl;
			}
			break;
		case 5:
			cout << "Codici tessera di associati che hanno preso libri di genere horror: " << endl;
			for (int i = 0; i < 5; i++)
				if (genere[i] == 05)
				{
					cout << ct[i];
				}
			break;
		case 6:
			for (int i = 0; i < 1; i++)
			{
				cout << "Inserisci codice libro: ";
				cin >> cl[i];
				cout << "Inserisci il nuovo codice tessera: ";
				cin >> nuovoct;
				nuovoct = ct[i];
			}
			break;
		case 7:
			for (int i = 0; i < 1; i++)
			{
				cout << "Inserisci il codice tessera: ";
				cin >> ct[i];
				cl[i] = 0;
				ct[i] = 0;
				prestito[i] = 0;
				genere[i] = 0;
			}
			break;
		case 8:
			return;
			break;
		}

	} while (1 < opzione < 8);
}