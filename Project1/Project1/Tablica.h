#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>

class Tablica
{
public:
	//zmienne
	int *tablica;
	int rozmiarTablicy;
	//metody
	Tablica();
	~Tablica();

	void dodajNaPoczatek(int wartosc);
	void dodajNaKoniec(int wartosc);
	void dodajNaWybrany(int wartosc, int indeks);
	void usunPierwszy();
	void usunOstatni();
	void usunWybrany(int pozycja);
	void wypiszTablice();
	void zaladujZPliku();
	void stworzTablice();
	bool znajdzWTablicy(int wartosc);
	

};
