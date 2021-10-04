#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void main()
{
	int punteggio = 0, ncasuale, numero, tentativi = 0;
	srand(time(NULL));
	cout << "INDOVINA IL NUMERO" << endl << endl;
	ncasuale = rand() % 100 + 1;
	cout << "Il numero si trova tra 1 e 100" << endl;
	do
	{
		cin >> numero;


		if (numero == ncasuale)
		{
			tentativi++;
			cout << "Bravo, hai indovinato il numero in " << tentativi << " tentativi ed hai ottenuto " << punteggio << " punti" << endl;
		}
		if (numero > ncasuale)
		{
			tentativi++;
			cout << "Numero inserito maggiore del numero da indovinare" << endl;
		}

		if (numero < ncasuale)
		{
			tentativi++;
			cout << "Numero inserito minore del numero da indovinare" << endl;
		}

		//Punteggio

		switch (tentativi)
		{
		case 1:
			punteggio = 100;
			break;
		case 2:
			punteggio = 50;
			break;
		case 3:
			punteggio = 50;
			break;
		case 4:
			punteggio = 50;
			break;
		case 5:
			punteggio = 25;
			break;
		case 6:
			punteggio = 25;
			break;
		case 7:
			punteggio = 25;
			break;
		case 8:
			punteggio = 10;
			break;
		case 9:
			punteggio = 10;
			break;
		case 10:
			punteggio = 10;
			break;
		}

	}

	while (tentativi < 10);

	cout << "Hai perso (tentativi esauriti)" << endl;

	system("pause");
}

// Leonardo Di Carlo 3C-IA