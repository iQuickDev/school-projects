#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"      
#define BLUE    "\033[34m"     
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"      
#define WHITE   "\033[37m"      

using namespace std;

int inserimento(int arrM[], int arrL[], int ll, int lf, int newM, int newL)
{
	if (ll < lf)
	{
		if (ll == 0)
		{
			arrM[0] = newM;
			arrL[0] = newL;
			ll++;
		}
		else
		{
			arrM[ll] = newM;
			arrL[ll] = newL;
			ll++;
		}
	}
	return ll;
}

void stampa(int arrM[], int arrL[], int ll)
{
	if (ll == 0)
	{
		cout << RED << "Nessun autobus e' stato inserito" << RESET << endl;
		return;
	}
	cout << CYAN << "---- AUTOBUS ----    ---- LINEA ----" << RESET << endl;
	for (int i = 0; i < ll; i++)
	{
		cout << CYAN << arrM[i] << "                    " << arrL[i] << RESET << endl;
	}
	return;
}

bool ricercaMezzo(int arrM[], int ll, int mezzo, int& pos)
{
	for (int i = 0; i < ll; i++)
	{
		if (arrM[i] == mezzo)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int contaMezzi(int arrM[], int arrL[], int ll, int linea, int conta)
{
	conta = 0;
	for (int i = 0; i < ll; i++)
	{
		if (arrL[i] == linea)
		{
			conta++;
		}
	}
	return conta;
}

int rimozione(int arrM[], int arrL[], int ll, int mezzo)
{
	for (int i = 0; i < ll; i++)
	{
		if (arrM[i] == mezzo)
		arrM[i] = 0;
	}
	return ll;
}

void main() {
	const int lf = 10;
	int arrM[lf], arrL[lf], scelta, ll = 0, newM, newL, pos, mezzo, linea, conta = 0;

	do {
		cout << BLUE << "[1] Inserisci autobus" << RESET << endl;
		cout << BLUE << "[2] Visualizza tutti gli autobus" << RESET << endl;
		cout << BLUE << "[3] Elimina autobus" << RESET << endl;
		cout << BLUE << "[4] Conta autobus" << RESET << endl;
		cout << BLUE << "[5] Cerca se l'autobus e' in servizio" << RESET << endl;
		cout << BLUE << "[6] Esci" << RESET << endl;

		cout << YELLOW << "Opzione: " << RESET;
		cin >> scelta;

		switch (scelta)
		{
			case 1:
			{
				cout << YELLOW << "Inserisci l'autobus che esce dal deposito: " << RESET;
				cin >> newM;
				cout << YELLOW << "Inserisci il numero di linea alla quale l'autobus e' assegnato: " << RESET;
				cin >> newL;
				ll = inserimento(arrM, arrL, ll, lf, newM, newL);
				break;
			}
			case 2:
			{
				stampa(arrM, arrL, ll);
				break;
			}
			case 3:
			{
				cout << YELLOW << "Inserisci l'autobus da eliminare: " << RESET;
				cin >> mezzo;
				ll = rimozione(arrM, arrL, ll, mezzo);
				break;
			}
			case 4:
			{
				cout << YELLOW << "Inserisci la linea su cui ricercare: " << RESET;
				cin >> linea;
				conta = contaMezzi(arrM, arrL, ll, linea, conta);
				cout << "Conta: " << conta << endl;
				break;
			}
			case 5:
			{
				cout << YELLOW << "Inserisci l'autobus da ricercare: " << RESET;
				cin >> mezzo;
				if (ricercaMezzo(arrM, ll, mezzo, pos))
				{
					cout << GREEN << "L'autobus e' in servizio" << RESET << endl;
				}
				else
				{
					cout << RED << "L'autobus non e' in servizio" << RESET << endl;
				}
				break;
			}
			case 6:
			{
				cout << RED << "Programma terminato." << RESET << endl;
				return;
			}
		}
	} while (0 < scelta < 7);
}