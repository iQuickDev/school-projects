#include <iostream>

#define LF 100

using namespace std;

struct chiamata
{
	int pianoAttuale;
	int pianoDestinazione;
	bool daTastieraInterna;
	int pianoTastiera;
};

int inserimento(chiamata arr[], int ll, int lf, chiamata obj)
{
	if (ll < lf)
	{
		arr[ll] = obj;
		ll++;
	}

	return ll;
}

int ContaChiamateTastiereEsterne(chiamata arr[], int ll)
{
	int ctr = 0;
	for (int i = 0; i < ll; i++)
	{
		if (arr[i].daTastieraInterna)
		{
			++ctr;
		}
	}
	return ctr;
}

int ContaChiamatePiano(chiamata arr[], int ll, int piano)
{
	int ctr = 0;
	for (int i = 0; i < ll; i++)
	{
		if (arr[i].pianoAttuale == piano)
		{
			ctr++;
		}
	}
	return ctr++;
}

int SommaTragitti(chiamata arr[], int ll)
{
	int sum = 0;
	for (int i = 0; i < ll; i++)
	{
		sum = abs(arr[i].pianoAttuale - arr[i].pianoDestinazione);
	}
	return sum;
}

void sort(int arr[], int length)
{
	for (int i = 1; i < length; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i = 0;
		}
	}
}

int PianoPiuRichiesto(chiamata arr[], int ll) // O(n)
{
	int piani[LF], contaMax = 1, conta = 1, piano = 0;

	for (int i = 0; i < ll; i++)
		piani[i] = arr[i].pianoDestinazione;

	sort(piani, ll);

	for (int i = 1; i < ll; i++)
	{
		if (piani[i - 1] == piani[i])
			conta++;
		else
		{
			if (conta > contaMax)
			{
				contaMax = conta;
				piano = piani[i - 1];
			}

			conta = 1;
		}
	}

	if (conta > contaMax)
		piano = piani[ll - 1];

	return piano;
}

int PianoPiuFrequente(chiamata arr[], int ll)  // O(n)
{
	int piani[LF], contaMax, conta = 1, piano = 0;

	for (int i = 0; i < ll; i++)
		piani[i] = arr[i].pianoAttuale;

	sort(piani, ll);

	for (int i = 1; i < ll; i++)
	{
		if (piani[i - 1] == piani[i])
			conta++;
		else
		{
			contaMax = conta;
			conta = 1;
			piano = piani[i - 1];
		}
	}

	return piano;
}


void main()
{
	int scelta, ll = 0, piano;
	chiamata chiamate[LF], obj;

	do
	{
		cout << "[1] Inserisci chiamata" << endl;
		cout << "[2] Conta chiamate provenienti da tastiere esterne" << endl;
		cout << "[3] Conta chiamate provenienti da piano specifico" << endl;
		cout << "[4] Somma dei tragitti" << endl;
		cout << "[5] Mostra piano piu richiesto" << endl;
		cout << "[6] Mostra piano dove si trova piu spesso l'ascensore" << endl;

		cout << "Scelta: ";
		cin >> scelta;

		switch (scelta)
		{
			case 1:
				cout << "Piano attuale: ";
				cin >> obj.pianoAttuale;
				cout << "Piano destinazione: ";
				cin >> obj.pianoDestinazione;
				cout << "Da tastiera interna ? ";
				cin >> obj.daTastieraInterna;
				cout << "Piano tastiera: ";
				cin >> obj.pianoTastiera;

				ll = inserimento(chiamate, ll, LF, obj);
				break;
				// dopo vieni su discord ho sbuggato le cuffie 
				// va bene mi chiami e vengo
				// sai come le sbuggo?
				// col driver ? 
				// no no, il problema era che le mie cuffie essendo bluetooth [...] insomma hanno un mic
				// integrato + quello del cavo, quindi non sa quale mic usare il driver e si bugga
				// allora cosa ho fatto ho attaccato delle cuffiette lerce con microfono in-ear dietro
				// nell'ingressso rosa/rosso del microfono ma non riuscivo ad utilizzarle come microfono
				// allora le ho staccate e a caso il mic delle cuffie ha iniziato a fare
				// perchè tipo il driver da la precedenza al filo e mi rileva il mic al filo a caso
				// non potevi tipo disabilitare uno dei due mic ?
				// no, appena gli arriva corrente dal pc si attivano entrambi
				// eh si poi dal device manager ne disabiliti uno
				// no perchè me li rileva come 1 solo
				// ahh ok comunque Rosa Mari dovrebbe vedere questo commentone
				// ok lascialo e gli si fa vedere in classe
				// vai lo lascio
				// insomma da ora in poi per usare il microfono ogni volta devo pluggare le cuffiette magiche di dietro e unplaggarle, gg
				// che CENSORED, trova una soluzione migliore
				// non c'è
				// allora le compri nuove
				// costano 200 euro CENSORED
				// vabbè fra io continuo il programma, te porta fuori doggo
				// ok
				// 26/09/2021 02:08 AnyDesk
			case 2:
				cout << "Chiamate da tastiere esterne: " << ContaChiamateTastiereEsterne(chiamate, ll) << endl;
				break;

			case 3:
				cout << "Inserisci il piano: ";
				cin >> piano;
				cout << "Chiamate da piano " << piano << ": " << ContaChiamatePiano(chiamate, ll, piano) << endl;
				break;

			case 4:
				cout << "Somma dei tragitti: " << SommaTragitti(chiamate, ll) << endl;
				break;

			case 5:
				cout << "Piano piu richiesto: " << PianoPiuRichiesto(chiamate, ll) << endl;
				break;

			case 6:
				cout << "Piano dove si trova piu spesso l'ascensore: " << PianoPiuFrequente(chiamate, ll) << endl;
				break;

			case 7:
				cout << "Programma terminato";
				break;

			default:
				cout << "Opzione non valida";
				break;
		}
	} while (scelta != 7);
}