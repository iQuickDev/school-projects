#include <iostream>

using namespace std;

struct lavoratore {
	string nome;
	string cognome;
	int stipendio;
};

int inserimento(lavoratore v[], int ll, int lf, lavoratore x)
{
	if (ll == 0 && ll < lf)
	{
		v[0] = x;
		ll++;
	}
	else if (ll != 0 && ll < lf)
	{
		v[ll] = x;
		ll++;
	}

	return ll;
}

void visualizzazione(lavoratore lav[], int ll)
{
	for (int i = 0; i < ll; i++)
	{
		cout << "---------- LAVORATORE " << i << " ----------" << endl;
		cout << "Nome: " << lav[i].nome << endl;
		cout << "Cognome: " << lav[i].cognome << endl;
		cout << "Stipendio: " << lav[i].stipendio << " EUR" << endl << endl;
	}
	return;
}

int stampaMigliorLavoratore(lavoratore lav[], int ll)
{
	int valoremax = 0, pos = 0;

	for (int i = 0; i < ll; i++)
	{
		if (valoremax < lav[i].stipendio)
		{
			valoremax = lav[i].stipendio;
			pos = i;
		}
	}
	return pos;
}

int calcolaMedia(lavoratore lav[], int ll)
{
	int sommastipendi = 0, media = 0;

	for (int i = 0; i < ll; i++)
	{
		sommastipendi += lav[i].stipendio;
		media = (sommastipendi / ll + 1);
	}
	return media;
}

void main()
{
	int ll = 0, lf = 5, scelta, pos, stipendio;
	float media;
	struct lavoratore lav[5];
	lavoratore x;

	do {
		cout << "[1] Inserisci dati" << endl;
		cout << "[2] Visualizza vettore" << endl;
		cout << "[3] Visualizza dipendente con stipendio massimo" << endl;
		cout << "[4] Visualizza media stipendi" << endl;
		cout << "[5] Esci" << endl;

		cout << "Opzione: ";
		cin >> scelta;

		switch (scelta)
		{

			case 1:
			{
				cout << "Inserisci il nome: ";
				cin >> x.nome;
				cout << "Inserisci il cognome: ";
				cin >> x.cognome;
				cout << "Inserisci lo stipendio (in EUR): ";
				cin >> x.stipendio;
				ll = inserimento(lav, ll, lf, x);
				break;
			}
			case 2:
			{
				if (ll == 0)
				cout << "Opzione non disponibile (Inserisci dati)" << endl;
				else
				{
					visualizzazione(lav, ll);
				}
				break;
			}
			case 3:
			{	
				if (ll == 0)
				cout << "Opzione non disponibile (Inserisci dati)" << endl;
				else
				{
					pos = stampaMigliorLavoratore(lav, ll);
					cout << "Posizione del miglior lavoratore: " << pos << " con stipendio: " << lav[pos].stipendio << " EUR" << endl;
				}
				break;
			}
			case 4:
			{
				if (ll == 0)
				cout << "Opzione non disponibile (Inserisci dati)" << endl;
				else
				{
					media = calcolaMedia(lav, ll);
					cout << "Media di tutti gli stipendi: " << media << endl;
				}
				break;
			}
			case 5:
			{
				cout << "Programma terminato." << endl;
				return;
			}

		}
	} while (0 < scelta < 5);
	
	
}