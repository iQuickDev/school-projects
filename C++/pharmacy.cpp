#include <iostream>
using namespace std;

struct Stock
{
	string casa;
	string nome;
	char forma;
	float prezzo;
	char data[10];
	int quantita;
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
	int tot = 0;
	for (int i = 0; i < ll; i++)
	{
		tot += stock[i].prezzo;
	}
	return tot;
}

void visualizzaScadenza(Stock stock[], int ll, char data[])
{
	cout << "Prodotti scaduti:" << endl;
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].data < data)
			cout << stock[i].nome << " con data: " << stock[i].data << endl;
	}
}

void visualizzaCosto(Stock stock[], int ll, float min, float max)
{
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].prezzo > min && stock[i].prezzo < max)
			cout << stock[i].nome << " con prezzo: " << stock[i].prezzo << endl;
	}
}

void visualizzaCasa(Stock stock[], int ll, string casa)
{
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].casa == casa)
		{
			cout << stock[i].nome << " con quantita': " << stock[i].prezzo << endl;
		}
	}
}

bool decrementa(Stock stock[], int ll, string nomeFarmaco, int quant)
{
	int oldvalue = 0;
	int pos = 0;
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].nome == nomeFarmaco)
		{
			oldvalue = stock[i].quantita;
			pos = i;
			stock[i].quantita -= quant;
		}
	}
	if (oldvalue != stock[pos].quantita)
		return true;
	else
		return false;
}

int elimina(Stock stock[], int ll)
{
	for (int i = 0; i < ll; i++)
	{
		if (stock[i].quantita == 0)
			stock[i++] = stock[i];
	}
	ll--;
	return ll;
}

void main()
{
	int const lf = 10;
	int ll = 0, scelta, tot, quant;
	float min, max;
	char data[10];
	string casa, nomeFarmaco;
	Stock stock[lf], nuovoStock;
	do {
		cout << "[1] Inserisci prodotto" << endl;
		cout << "[2] Calcola valore totale dei prodotti" << endl;
		cout << "[3] Visualizza prodotti che scadono prima di una certa data" << endl;
		cout << "[4] Visualizza prodotti con costo compreso tra due valori" << endl;
		cout << "[5] Visualizza prodotti di una casa produttrice" << endl;
		cout << "[6] Decrementa quantita' di un prodotto" << endl;
		cout << "[7] Elimina prodotti con quantita' nulla" << endl;

		cout << "Opzione: ";
		cin >> scelta;

		switch (scelta)
		{
			case 1:
				cout << "Casa produttrice: ";
				cin >> nuovoStock.casa;
				cout << "Nome: ";
				cin >> nuovoStock.nome;
				cout << "Forma: ";
				cin >> nuovoStock.forma;
				cout << "Prezzo: ";
				cin >> nuovoStock.prezzo;
				cout << "Scadenza: ";
				cin >> nuovoStock.data;
				cout << "Quantita': ";
				cin >> nuovoStock.quantita;
				ll = inserimento(stock, ll, lf, nuovoStock);
				break;

			case 2:
				tot = totale(stock, ll);
				cout << "Il totale dei prodotti nella farmacia e' " << tot << " EUR" << endl;
				break;

			case 3:
				cout << "Inserisci la data di scadenza: ";
				cin >> data;
				visualizzaScadenza(stock, ll, data);
				break;

			case 4:
				cout << "Inserisci il valore minimo: ";
				cin >> min;
				cout << "Inserisci il valore massimo: ";
				cin >> max;
				visualizzaCosto(stock, ll, min, max);
				break;
				
			case 5:
				cout << "Inserisci il nome della casa produttrice: ";
				cin >> casa;
				visualizzaCasa(stock, ll, casa);
				break;
				
			case 6:
				cout << "Inserisci il nome del farmaco: ";
				cin >> nomeFarmaco;
				cout << "Inserisci la quantita' da decrementare: ";
				cin >> quant;
				if (decrementa(stock, ll, nomeFarmaco, quant))
				{
					cout << "Quantita' decrementata con successo" << endl;
				}
				else
					cout << "Errore nella decrementazione" << endl;
				break;

			case 7:
				ll = elimina(stock, ll);
				break;
		}

	} while (scelta > 0 && scelta < 8);
}