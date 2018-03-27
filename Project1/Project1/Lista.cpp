#include "Lista.h"
#include <string>
#include<cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

// inicjowanie zmiennych klasowych
Lista::Lista()
{
	ostatniElement = NULL;
	pierwszyElement = NULL;
	rozmiarListy = 0;
}

Lista::~Lista()
{
	ElementListy * element;

	while (pierwszyElement)
	{	//przypisuje kolejny element jako aktualny
		element = pierwszyElement->nastepnyElement;
		//usuwa pierwszy element
		delete pierwszyElement;
		pierwszyElement = element;
	}
	rozmiarListy = 0;
}

int Lista::zaladujZPliku(string nazwaPliku)// funkcja, ktora laduje wartosci z pliku o zadanej nazwie
{
	ifstream plik; // zmienna konieczna do czytania z pliku
	int nr_linii = 1; // zmienna pomocnicza
	int rozmiarListy = 0;// nadanie wartosci poczatkowej 0 dla listy, ktora chcemy zaladowac z pliku
	string linia; // inicjowanie zmiennej potrzebnej do wczytania z pliku
	plik.open(nazwaPliku.c_str()); // otwieranie pliku o nazwie podanej przez uzytkownika

	if (plik.good() == false) // sprawdzanie poprawnosci wczytywania pliku
	{
		cout << "Blad wczytywania" << endl;
		return 0;
	}

	ostatniElement = pierwszyElement = NULL; // nadanie wartosci glowie i ogonowi listy
	rozmiarListy = 0;

	while (getline(plik, linia)) // wczytywanie z pliku
	{
		if (nr_linii == 1)//w pierwszej lini podajemy ilosc argumentow
		{
		}
		else
		{
			dodajDoListy(atoi(linia.c_str()), rozmiarListy); // zamiania string linia na int zapisany w pliku
			rozmiarListy++; // zwieksza potrzebny rozmiar dla listy
		}
		nr_linii++; // zwieksza numer lini
	}
	plik.close(); // zamkniecie pliku
	return 0;
}

bool Lista::znajdzWLiscie(int value) // funkcja, ktora sprawdza czy podany element jest jednym z elementow naszej listy
{
	ElementListy* element = pierwszyElement; //wskaznik na aktualny element

	for (int i = 0; i < rozmiarListy; i++) // przeszukiwanie listy
	{
		if (element->wartosc == value) // jezeli aktualny element ma zadana wartosc to zwroc true
		{
			cout << "Podany element znajduje sie w liscie." << endl;
			return true;
		}
		else
			element = element->nastepnyElement; // tymczasowy element dostaje wskaznik na kolejny element listy
	}
	
	cout << "Podanej wartosci nie ma w liscie." << endl; // jezeli nie to false
	return false;
}


void Lista::dodajDoListy(int value, int index) // dodanie wartsci do listy na zadany przez nas indeks 
{
	ElementListy *element;//wskaznik
	ElementListy *newElement = new ElementListy();//tworzymy nowy element
	element = pierwszyElement;//ustawianie aktualnego elementu na poczatek
	int i = 1; // zmienna pomocnicza

	if (index > rozmiarListy) // jezeli nie ma takiego indeksu w naszej listy
	{
		cout << "Podano zly indeks." << endl;
		return;
	}

	if (index == 0) // jezeli dodajemy element, ktory staje sie pierwszym elementem naszej listy
	{
		newElement->nastepnyElement = pierwszyElement; // tymczasowy element otrzymuje wskaznik na kolejny element listy
		newElement->poprzedniElement = NULL; // nadanie wskaznika na poprzedni element, ktory jest rowny NULL 
		if (pierwszyElement) pierwszyElement->poprzedniElement = newElement;
		pierwszyElement = newElement; // wartosc tymczasowego pierwszego elementu listy jest przypisywana pierwszemu elementowi listy
		if (!ostatniElement) ostatniElement = pierwszyElement;
		newElement->wartosc = value;
		rozmiarListy++;
		return;
	}

	while (element)
	{
		if (i == index)
		{
			newElement->nastepnyElement = element->nastepnyElement;//nowy element wskazuje na kolejny
			newElement->poprzedniElement = element;
			element->nastepnyElement = newElement;
			if (newElement->nastepnyElement)
			{
				newElement->nastepnyElement->poprzedniElement = newElement;//element przed nowym elementem dostajne nowy element jako swoj poprzedni
			}
			else
			{
				ostatniElement = newElement;
			}
			newElement->wartosc = value;//wpisywanie wartosci do nowego elementu
			rozmiarListy++;
			break;
		}
		else
		{
			element = element->nastepnyElement;//element wskazuje na nastepny element w liscie
			i++;
		}

	}

}

void Lista::usunZListy(int value)
{
	ElementListy *element;//wskaznik na element
	element = pierwszyElement;//wskaznik na pierwszy element listy
	if (rozmiarListy == 0) cout << "Lista jest pusta, nie mozna z niej nic usunac." << endl;
	else
	{
		while ((element->nastepnyElement != NULL) && (element->wartosc != value))
		{
			element = element->nastepnyElement;
		}
		if (element->wartosc == value)//jezeli wartosc szukana jest rowna sie aktualnej wartosci
		{
			if (element->nastepnyElement)//sprawdzamy czy aktualny element ma nastepny element
				element->nastepnyElement->poprzedniElement = element->poprzedniElement;
			else
				ostatniElement = element->poprzedniElement;
			if (element->poprzedniElement)
			{
				element->poprzedniElement->nastepnyElement = element->nastepnyElement;
			}
			else
				pierwszyElement = element->nastepnyElement;
			rozmiarListy--;
			cout << "Usunieto podana wartosc." << endl;
		}
		else cout << "W liscie nie ma podanej wartosci." << endl;
	}
}

void Lista::wypiszListe() // funkcja, ktora wypisuje liste
{
	ElementListy * element = new ElementListy(); // tworzenie nowego tymczasowego elementu
	int i = 1;
	if (!pierwszyElement) cout << "Lista jest pusta" << endl; // sprawdzanie czy lista nie jest pusta
	else
	{
		cout << "Oto Twoja lista:" << endl;
		element = pierwszyElement; // ustanawianie tymczasowego elementu, elementem pierwszym
		while (element)
		{
			cout << element->wartosc << " ";
			element = element->nastepnyElement;
			i++;
		}
		cout << endl << endl;
	}
	delete element;
}

void Lista::stworzListe(int size) // metoda, ktora tworzy liste o zadanym rozmiarze
{
	time_t t;
	srand((unsigned)time(&t));
	ostatniElement = pierwszyElement = NULL;
	rozmiarListy = 0;
	int rozmiarListy = 0;

	for (int i = 0; i < size; i++)
	{
		dodajDoListy(rand() % 100, rozmiarListy);
		rozmiarListy++;
	}

}

void Lista::usunPierwszy()//funkcja, ktora usuwa pierwszy element z listy
{
	ElementListy * element = new ElementListy(); // tworzenie tymczasowego aktualnego elementu
	//przypisz drugi element jako aktualny
	element = pierwszyElement->nastepnyElement; // ustawianie tymczasowego elementu jako pierwszy element listy

	//Usuñ pierwszy element
	delete pierwszyElement;

	//SprawdŸ, czy w liœcie s¹ jeszcze jakieœ elementy
	//Je¿eli tak, ustaw aktualny element jako pierwszy
	//Je¿eli nie, wyzeruj elementy listy
	if (rozmiarListy > 1) {
		element->poprzedniElement = NULL;
		pierwszyElement = element;
	}
	else {
		element = NULL; // usuwanie tymczasowego elementu
		pierwszyElement = NULL; // usuwanie pierwszego elementu
		ostatniElement = NULL;
	}

	//Zmniejsz rozmiar listy o 1
	rozmiarListy--;

}

void Lista::usunOstatni() // funkcja, ktora usuwa ostatni element z listy
{
	ElementListy * element = new ElementListy();
	//Przypisz przedostani element jako aktualny (tymaczasowy)
	element = ostatniElement->poprzedniElement;
	//Usuñ ostatni element
	delete ostatniElement;


	//Je¿eli lista ma tylko jeden element to ja zerujemy, w innym przypadku usuwamy tylko ostatni element
	if (rozmiarListy > 1) {
		element->nastepnyElement = NULL;
		ostatniElement = element;
	}
	else {
		element = NULL;
		pierwszyElement = NULL;
		
	}

	//Zmniejsz rozmiar listy
	rozmiarListy--;

}
