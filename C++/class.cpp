#include <iostream>

using namespace std;

void main()
{

	const int num = 10; // Numero studenti

	int scelta, pos;
	float matricola[num], votomate[num], votoingl[num], votoita[num];
	float media;

	// Menu

	do {
		cout << "[1] Inserisci matricola e voti" << endl;
		cout << "[2] Visualizza tutti i voti" << endl;
		cout << "[3] Visualizza media di tutti" << endl;
		cout << "[4] Visualizza media di ogni singola materia" << endl;
		cout << "[5] Visualizza insufficienze" << endl;
		cout << "[6] Azzera vettore specifico" << endl;
		cout << "[7] Azzera tutti i vettori" << endl;
		cout << "[8] Esci" << endl;

		cout << "Opzione: ";
		cin >> scelta;

		if (scelta < 1 ^ scelta>8)
		{
			cout << "\033[31mOpzione non esistente, scegli nuovamente.\033[0m" << endl;
		}

		switch (scelta)
		{
		case 1:

			// Inserimento in un vettore [1]

			for (int i = 0; i < num; i++)
			{
				cout << "Inserisci Matricola: ";
				cin >> matricola[i];
				cout << "Inserisci voto Matematica: ";
				cin >> votomate[i];
				cout << "Inserisci voto Inglese: ";
				cin >> votoingl[i];
				cout << "Inserisci voto Italiano: ";
				cin >> votoita[i];
			}
			break;

		case 2:

			// Visualizzazione vettore [2]

			for (int i = 0; i < num; i++)
			{
				cout << "---------------" << endl;
				cout << "| Matricola " << matricola[i] << " |" << endl;
				cout << "---------------" << endl;
				cout << "Voto Matematica: " << votomate[i] << endl;
				cout << "Voto Inglese: " << votoingl[i] << endl;
				cout << "Voto Italiano: " << votoita[i] << endl;
			}
			break;

		case 3:

			// Visualizzazione della media di ciascuno studente [3]

			for (int i = 0; i < num; i++)
			{
				media = (votomate[i] + votoingl[i] + votoita[i]) / num;
				cout << "Media dello studente matricola n." << matricola[i] << ": " << media << endl;
			}
			break;

			//case 4:

				// Visualizzazione media di ogni singola materia [4]

		case 5:

			// Voti insufficienti [5]

			for (int i = 0; i < num; i++)
			{
				cout << "---------------" << endl;
				cout << "| Matricola " << matricola[i] << " |" << endl;
				cout << "---------------" << endl;


				if (votoingl[i] < 6)
				{
					cout << "Inglese: " << votoingl[i] << endl;
				}
				if (votomate[i] < 6)
				{
					cout << "Matematica: " << votomate[i] << endl;
				}
				if (votoita[i] < 6)
				{
					cout << "Italiano: " << votoita[i] << endl;
				}
			}
			break;

		case 6:

			// Eliminazione vettore specifico [6]

			cout << "Inserisci matricola da eliminare: ";
			cin >> pos;
			pos--;

			for (int i = 0; i < num; i++)
				votoingl[pos] = 0;

			for (int i = 0; i < num; i++)
				votoita[pos] = 0;

			for (int i = 0; i < num; i++)
				votomate[pos] = 0;
			matricola[pos] = matricola[pos + 1];

			break;

		case 7:

			// Azzeramento vettore [7]

			for (int i = 0; i < num; i++)

				matricola[i] = 0;

			for (int i = 0; i < num; i++)

				votoingl[i] = 0;

			for (int i = 0; i < num; i++)
				votoita[i] = 0;

			for (int i = 0; i < num; i++)
				votomate[i] = 0;

			break;

		case 8:

			// Uscita programma

			return;
		}
	} while (1 < scelta < 8);

}