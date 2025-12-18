
#include <iostream>
#include <cstdlib>
using namespace std;

void Logowanie()
{
	int PIN = 6969;
	int podanyPIN = 0;
	while (podanyPIN != PIN)
	{
		cout << "Podaj PIN: " << endl;
		cin >> podanyPIN;
		if (podanyPIN != PIN)
		{
			cout << "Niepoprawny PIN" << endl;
		}
	}
	cout << "Dostep przyznany. " << endl;
}
void PokazMenu()
{
	cout << endl << "Menu glowne: " << endl;
	cout << "----------------------" << endl;
	cout << "1. Stan konta " << endl;
	cout << "2. Wyplata gotowki " << endl;
	cout << "3. Wplata gotowki " << endl;
	cout << "4. Transfer srodkow" << endl;
	cout << "5. Wyjdz" << endl;
	cout << "----------------------" << endl;

}
void StanKonta(int glowne, int oszcz)
{
	cout << "Stan konta: " << endl;
	cout << "Konto osobiste: " << glowne << " ZL" << endl;
	cout << "Konto oszczednosciowe: " << oszcz << " ZL" << endl;
	cout << "_______________________ " << endl;
	cout << "Saldo: " << (glowne + oszcz) << " ZL" << endl;
}
void wyplata(int& srodki)
{
	int kwota = 0;
	while (true)
	{
		cout << "Podaj kwote do wyplaty (lub wpisz 0 aby anulowac): " << endl;
		cin >> kwota;

		if (kwota == 0)
		{
			cout << "Transakcja anulowana." << endl;
			return;
		}
		if (kwota > srodki)
		{
			cout << "brak wystarczajacych srodkow. " << endl;
			cout << "stan konta: " << srodki << "ZL" << endl;
		}
		else
		{
			cout << "wyplacono: " << kwota << " ZL" << endl;
			srodki -= kwota;
			cout << "stan konta: " << (srodki) << " ZL" << endl;
			return;
		}

	}
}
void wplata(int& srodki)
{
	int kwota = 0;

	cout << "Podaj kwote do wplaty " << endl;
	cin >> kwota;
	if (kwota == 0)
	{
		cout << "Transakcja anulowana." << endl;
		return;
	}
	else
	{
		cout << "wplacono: " << kwota << " ZL" << endl;
		srodki += kwota;
		cout << "stan konta: " << srodki << " ZL" << endl;
	}
}
void Przelew(int& zKonta, int& naKonto)
{
	int kwota;
	cout << "Podaj kwote przelewu: " << endl;
	cin >> kwota;
	if (kwota > zKonta)
	{
		cout << "Brak wystarczajacych srodkow. " << endl;
		cout << "stan konta: " << zKonta << "ZL" << endl;
		return;
	}
	if (kwota == 0)
	{
		cout << "Transakcja anulowana." << endl;
		return;
	}
	else
	{
		zKonta -= kwota;
		naKonto += kwota;
		cout << "Przelano " << kwota << " ZL" << endl;
		cout << "Stan konta: " << naKonto << " ZL" << endl;
		return;
	}
}
int main()
{

	Logowanie();

	int KontoOsobiste = 5000;
	int KontoOszczednosciowe = 15000;
	int opcja;
	int wybor;
	int wyborB;

	do
	{
		system("cls");
		PokazMenu();
		cin >> opcja;

		switch (opcja)
		{
		case 1:
			StanKonta(KontoOsobiste, KontoOszczednosciowe);
			break;
		case 2:
			cout << "Wybierz konto dla operacji: 1. Osobiste  2. Oszczednosciowe " << endl;
			cin >> wybor;
			if (wybor == 1)wyplata(KontoOsobiste);
			if (wybor == 2)wyplata(KontoOszczednosciowe);
			break;

		case 3:
			cout << "Wybierz konto dla operacji: 1. Osobiste  2. Oszczednosciowe " << endl;
			cin >> wybor;
			if (wybor == 1)wplata(KontoOsobiste);
			if (wybor == 2)wplata(KontoOszczednosciowe);
			break;
		case 4:
			cout << "Wybierz konto dla operacji: 1. Osobiste  2. Oszczednosciowe " << endl;
			cin >> wybor;
			cout << "Wybierz konto docelowe: 1. Osobiste  2. Oszczednosciowe " << endl;
			cin >> wyborB;
			if (wybor == 1 && wyborB == 2)Przelew(KontoOsobiste, KontoOszczednosciowe);
			if (wybor == 2 && wyborB == 1)Przelew(KontoOszczednosciowe, KontoOsobiste);
			else
			{
				cout << "Transakcja anulowana." << endl;

			}
			break;

		case 5:
			cout << "Wylogowano " << endl;
			break;

		default:
			cout << "Niepoprawny numer" << endl;
			break;
		}
		cout << endl;
		cout << "Nacisnij dowolny przycisk aby kontynuowac... ";
		system("pause > nul");

	} while (opcja != 5);

	return 0;
}