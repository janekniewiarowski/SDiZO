#include<iostream>

using namespace std;

class ElementListy
{
public:
	ElementListy * nastepnyElement;//wskaznik na nastepnyElement element
	ElementListy * poprzedniElement;//wskaznik na poprzedniElement element
	int wartosc;
};

class Lista
{
	int rozmiarListy;//ilosc elementow w liscie
	ElementListy *ostatniElement;//wskaznik na ostatni element
	ElementListy *pierwszyElement;//wskaznik na pierwszy element

public:

	Lista();
	~Lista();

	int zaladujZPliku(string nazwaPliku);

	bool znajdzWLiscie(int value);

	void dodajDoListy(int value, int index);

	void usunZListy(int value);
	void usunOstatni();
	void usunPierwszy();
	void wypiszListe();

	void stworzListe(int size);

	

};