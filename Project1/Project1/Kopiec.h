#pragma once
#include <iostream>

class Kopiec
{
	//zmienne
	int *kopiec;
	int rozmiarKopca;
	public:
	
	//metody
	Kopiec();
	~Kopiec();

	bool zaladujZPliku();
	void wyswietlKopiec(std::string sp, std::string sn, int value);
	void dodajDoKopca(int wartosc);
	void usunZKopca(int wartosc);
	bool znajdzWKopcu(int wartosc);
	void poprawKopiec();
};
