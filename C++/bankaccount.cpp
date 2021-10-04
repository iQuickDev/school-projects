#include <iostream>

using namespace std;

bool ricerca(int arrN[], int ll, int numero, int& posizione)
{
	if (ll >= 0)
	{
		for (int i = 0; i < ll; i++)
		{
			if (arrN[i] == numero)
			{
				posizione = i;
				return true;
			}
		}
	}
	return false;
}

int inserimento(int arrN[], float arrS[], int ll, int lf, int numero, float saldo)
{
	int pos;
	if (ll < lf && !ricerca(arrN, ll, numero, pos))
	{
		for (int i = 0; i < ll; i++)
		{
			if (numero < arrN[i])
			{
				for (int j = ll; j > i; j--)
				{
					arrN[j] = arrN[j - 1];
					arrS[j] = arrS[j - 1];
				}
				arrN[i] = numero;
				arrS[i] = saldo;
				return ll + 1;
			}
		}
		arrN[ll] = numero;
		arrS[ll] = saldo;
		return ll + 1;
	}
	return ll;
}

bool saldo(int arrN[], float arrS[], int ll, int numero, float incremento)
{
	int pos;

	if (ricerca(arrN, ll, numero, pos))
	{
		for (int i = 0; i < ll; i++)
		{
			arrS[pos] += incremento;
			return true;
		}
	}
	else
		return false;
}

int rimozione(int arrN[], float arrS[], int ll, int numero)
{
	int pos;
	if (ricerca(arrN, ll, numero, pos))
	{
		for (int i = pos; i < ll - 1; i++)
		{
			arrN[i] = arrN[i + 1];
			arrS[i] = arrN[i + 1];
		}
		return ll - 1;
	}
	return ll;
}


void main()
{
	int arrN[100], scelta, ll = 0, numero = 0, posizione, lf = 100;;
	float arrS[100], incremento, s;
	do {
		cout << "[1] Inserisci nuovo conto corrente" << endl;
		cout << "[2] Resetta conti" << endl;
		cout << "[3] Modifica saldo" << endl;
		cout << "[4] Visualizza saldo" << endl;
		cout << "[5] Rimuovi conto corrente" << endl;

		cout << "Opzione: ";
		cin >> scelta;

		switch (scelta)
		{
		case 1:
		{
			cout << "Inserisci numero conto: ";
			cin >> numero;
			cout << "Inserisci saldo conto: ";
			cin >> s;
			ll = inserimento(arrN, arrS, ll, lf, numero, s);
			break;

		}

		case 2:
		{
			ll = 0;
			break;
		}

		case 3:
		{
			cout << "Inserisci numero conto: ";
			cin >> numero;
			cout << "Inserisci incremento: ";
			cin >> incremento;
			saldo(arrN, arrS, ll, numero, incremento);
			break;
		}

		case 4:
		{
			cout << "Inserisci numero conto: ";
			cin >> numero;
			if (ricerca(arrN, ll, numero, posizione));
			{
				for (int i = 0; i < ll; i++)
				{
					if (arrN[i] == numero)
						cout << "---- Conto N. " << numero << "----" << endl;
					cout << "Saldo: " << arrS[posizione] << endl;
				}
			}
			break;
		}

		case 5:
		{
			cout << "Inserisci numero conto: ";
			cin >> numero;
			rimozione(arrN, arrS, ll, numero);
			break;
		}
		}
	} while (5 < scelta < 1);
}