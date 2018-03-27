#include<iostream>
#include<cstdlib>
#include<string>
#include <time.h>
#include<fstream>
#include"Kopiec.h"


using namespace std;
// konstruktor kopca, inicjowanie zmiennych klasowych
Kopiec::Kopiec()
{
	Kopiec::kopiec = NULL;
	Kopiec::rozmiarKopca = 0;
}
//destruktor kopca, jezeli ten istnieje
Kopiec::~Kopiec()
{
	if (rozmiarKopca > 0) // sprawdzenie warunku istnienia kopca
	{
		delete[]kopiec;
	}
	else
	{
		cout << "Nie ma co usuwac." << endl;
	}

}

bool Kopiec::zaladujZPliku() // funkcja pozwalajaca na zaladowanie danych z pliku
{
	int n = 0; //inicjowanie zmiennych lokalny niezbednych do wczytania pliku
	int j, k;
	int v;
	fstream plik; 
	plik.open("wartosci.txt"); // otwieranie pliku o nazwie "wartosci.txt"
	plik >> rozmiarKopca; // przepisanie ilosci elementow jako rozmiar kopca
	kopiec = new int[rozmiarKopca]; // stworzenie nowego kopca o potrzebnym rozmiarze
	if (plik.good() == false) // sprawdzenie poprawnosci otwierania pliku
	{
		cout << "Plik zostal zle wczytany";
		return false;
	}
	for (int i = 0; i<rozmiarKopca; i++) // jezeli plik udalo sie poprawnie otworzyc
	{
		j = n++; 
		k = (j - 1) / 2;
		plik >> v;
		while (j>0 && kopiec[k]<v) {
			kopiec[j] = kopiec[k];
			j = k;
			k = (j - 1) / 2;
		}
		kopiec[j] = v;
	}
	plik.close(); // zamkniecie pliku
	return true; // bool prawda
	Kopiec::poprawKopiec(); // poprawianie struktury kopca, aby byly spelnione jego zalozenia
}

void Kopiec::wyswietlKopiec(string sp, string sn, int value) // funkcja, ktora obrazuje budowe kopca i wyswietla na ekranie
{
	if (rozmiarKopca == 0) // sprawdzanie warunku czy kopiec nie jest pusty
	{
		cout << "Kopiec jest pusty." << endl;

		return;
	}
	string s; // zmienna pomocnicza przy realizacji graficznej drzewa
	string cr, cl, cp; // inicjowanie zmiennych, ktora beda stanowily nasze polaczenie wizualne pomiedzy wezlami
	cr = cl = cp = "  "; // zmienne, ktore pozwalaja na wyswietlanie kopca w poprawny sposob
	cr[0] = 218; cr[1] = 196; cl[0] = 192; cl[1] = 196; cp[0] = 179; // nadanie wartosci zmiennym tak, aby odstep pomiedzy wezlami byl zachowany i struktura wygladala jak drzewo (wykorzystanie kodow tablicy kodow ASCII)

	if (value < rozmiarKopca ) // sprawdzenie warunku, czy wprowadzona wartosc jest mniejsza od rozmiaru naszej struktury
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' '; // warunek ktory sprawdza poprawnosc kolejnych elementow kopca i decyduje czy wypisac grafike czy wartosc elementu
		wyswietlKopiec(s + cp, cr, 2 * value +2 );

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << kopiec[value] << endl; // wyswietlanie elementu kopca w zaleznosci od wartosci value 

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		wyswietlKopiec(s + cp, cl, 2 * value + 1);
	}
}
	

void Kopiec::dodajDoKopca(int wartosc) // funkcja, ktora dodaje wartosc do kopca
{
	if (znajdzWKopcu(wartosc) == false) // sprawdzanie warunku, ze wartosci w kopcu nie moga sie powtarzac 
	{
		int *nowyKopiec = new int[rozmiarKopca + 1]; // tworzenie nowej tablicy wiekszej o 1

		for (int i = 0; i < rozmiarKopca; i++) // przepisanie danych ze starej tablicy do nowej
		{
			nowyKopiec[i] = kopiec[i];
		}

		nowyKopiec[rozmiarKopca] = wartosc; // dodanie wybranej wartosci do kopca
		delete[]kopiec; // usuwanie starej tablicy
		kopiec = nowyKopiec; // zastepuje nowa tablica

		Kopiec::poprawKopiec(); // poprawia kolejnosc elementow w  kopcu
		rozmiarKopca++; // zwiekszenie rozmiaru kopca o 1
	}
}

void Kopiec::usunZKopca(int wartosc)
{
	if (rozmiarKopca > 0) // sprawdzenie czy kopiec nie jest pusty
	{
		for (int i = 0; i < rozmiarKopca; i++) // petla, ktora porusza sie w zaleznosci od rozmiaru struktury
		{
			if (kopiec[i] == wartosc) // sprawdzanie czy szukana wartosc pokrywa sie z ta w kopcu
			{
				int *nowyKopiec = new int[rozmiarKopca - 1]; // stworzenie tablicy o rozmiar mniejszej od poprzedniej

				for (int j = 0; j < i; j++) // przepisywanie wartosci ze starego kopca do nowego 
				{
					nowyKopiec[j] = kopiec[j];
				}

				for (int k = i + 1; k < rozmiarKopca; k++) // przepisywanie wartosci ze starego kopca do nowego
				{
					nowyKopiec[k - 1] = kopiec[k];
				}


				delete[]kopiec; // usuwanie danych ze starego kopca
				kopiec = nowyKopiec; // przypisywanie nowych danych

				rozmiarKopca--; // zmniejszenie rozmiaru kopca o 1
				Kopiec::poprawKopiec(); // poprawienie struktury kopca


			}
		}
	}
	else
	{
		cout << "Brak elementu do usuniecia." << endl;
	}


}


bool Kopiec::znajdzWKopcu(int wartosc)
{
	for (int i = 0; i < rozmiarKopca; i++) // przeszukiwanie kopca 
	{
		if (kopiec[i] == wartosc) // jezeli wartosc podana zgadza sie z ta w kopcu to zwroc true
		{
			cout << "Podana wartosc znajduje sie w kopcu." << endl;
			return true;
		}
	}

	cout << "Podanej wartosci nie ma w kopcu." << endl; // jezeli wartosci nie ma w kopcu zwraca false
	return false;
}

void Kopiec::poprawKopiec()
{

	
	int wartoscPomocnicza = 0; // zmienna pomocnicza przy sortowaniu kopca

	
	for (int i = rozmiarKopca; i>0; i--) 
	{
		if (kopiec[i - 1] < kopiec[i]) 
		{
			wartoscPomocnicza = kopiec[i - 1];
			kopiec[i - 1] = kopiec[i];
			kopiec[i] = wartoscPomocnicza;
		}


	}

}