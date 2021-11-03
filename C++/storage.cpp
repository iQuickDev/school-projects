#include <iostream>

using namespace std;

struct Stock
{
	string marca;
	string nome;
	string tipo;
	float prezzo;
	string data;
	int quant;
};

int inserimento(Stock stock[], int ll, int lf, Stock nuovoStock)
{
	if (ll < lf)
	{
		stock[ll] = nuovoStock;
		ll++;
	}

	return ll;
}

float totale(Stock stock[], int ll)
{
	float somma = 0;
	int iterazioni = 0;

	for (int i = 0; i < ll; i++)
	{
		somma += stock[i].prezzo * stock[i].quant;
		iterazioni++;
	}
	
	return somma / iterazioni;
}

void visualizzaScadenza(Stock stock[], int ll, string data)
{
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].data < data && stock[i].tipo == "A")
		{
			cout << "-------------------------------" << endl;
			cout << "Nome: " << stock[i].nome << endl;
			cout << "Tipo: " << stock[i].tipo << endl;
			cout << "Scadenza: " << stock[i].data << endl;
		}
	}
}

void visualizzaCosto(Stock stock[], int ll, float min, float max)
{
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].prezzo > min && stock[i].prezzo < max)
		{
			cout << "-------------------------------" << endl;
			cout << "Nome: " << stock[i].nome << endl;
			cout << "Tipo: " << stock[i].tipo << endl;
			cout << "Prezzo: " << stock[i].prezzo << endl;
		}
	}
}

void visualizzaCasa(Stock stock[], int ll, string marca)
{
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].marca == marca)
		{
			cout << "-------------------------------" << endl;
			cout << "Nome: " << stock[i].nome << endl;
			cout << "Tipo: " << stock[i].tipo << endl;
			cout << "Quantita': " << stock[i].quant << endl;
		}
	}
}

int elimina(Stock stock[], int ll)
{
	Stock stockTemp;

	for (int i = 0; i < ll; i++)
	{
		if (stock[i].quant == 0)
		{
			stockTemp = stock[i];
			stock[i++] = stock[i];
			stock[i] = stockTemp;
			ll--;
		}
	}

	return ll;
}

void stampa(Stock stocks[], int ll)
{
	for (int i = 0; i < ll; i++)
	{
		cout << "-------------------------------" << endl;
		cout << "POS: " << i << endl;
		cout << "MARCA: " << stocks[i].marca << endl;
		cout << "NOME: " << stocks[i].nome << endl;
		cout << "TIPO: " << stocks[i].tipo << endl;
		cout << "PREZZO: " << stocks[i].tipo << endl;
		cout << "SCADENZA: " << stocks[i].data << endl;
		cout << "QUANTITA': " << stocks[i].quant << endl;
	}
}

void main()
{
	const int LF = 100;
	int scelta, ll = 0, totaleMagazzino;
	string data, marca;
	Stock stocks[LF], nuovoStock;
	do {
		cout << "[1] Inserisci nuovo stock" << endl;
		cout << "[2] Calcola valore totale prodotti" << endl;
		cout << "[3] Visualizza prodotti che scadono prima di una certa data" << endl;
		cout << "[4] Visualizza prodotti di una certa marca" << endl;
		cout << "[5] Elimina tutti gli stock con quantita' nulla" << endl;
		cout << "[6] Visualizza tutti i prodotti" << endl;
		cout << "[7] Esci" << endl;

		cout << "Opzione: ";
		cin >> scelta;

		switch (scelta)
		{
			case 1:
				cout << "Inserisci nome prodotto: ";
				cin >> nuovoStock.nome;
				cout << "Inserisci marca prodotto: ";
				cin >> nuovoStock.marca;
				cout << "Inserisci tipo prodotto: ";
				cin >> nuovoStock.tipo;

				if (nuovoStock.tipo == "A")
				{
					cout << "Inserisci data di scadenza prodotto (yyyy/mm/gg): ";
					cin >> nuovoStock.data;
				}
				else
					nuovoStock.data = "0000/00/00";

				cout << "Inserisci prezzo prodotto: ";
				cin >> nuovoStock.prezzo;
				cout << "Inserisci quantita' prodotto: ";
				cin >> nuovoStock.quant;

				ll = inserimento(stocks, ll, LF, nuovoStock);
				break;

			case 2:
				totaleMagazzino = totale(stocks, ll);
				cout << "Valore totale magazzino: " << totaleMagazzino << " EUR" << endl;
				break;

			case 3:
				cout << "Inserisci la data: ";
				cin >> data;
				visualizzaScadenza(stocks, ll, data);
				break;

			case 4:
				cout << "Inserisci la marca: ";
				cin >> marca;
				visualizzaCasa(stocks, ll, marca);
				break;

			case 5:
				ll = elimina(stocks, ll);
				break;

			case 6:
				stampa(stocks, ll);
				break;

			case 7:
				cout << "Programma terminato...";
				return;
			}
	} while (scelta > 0 || scelta < 6);
}