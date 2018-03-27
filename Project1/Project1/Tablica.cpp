#include "Tablica.h"
#include <iostream>


using namespace std;

//inicjowanie zmiennych klasowych
Tablica::Tablica()
{
	rozmiarTablicy = 0;
	tablica = NULL;
}

//destruktor zwalnia pamiec tablicy
Tablica::~Tablica()
{
	rozmiarTablicy = 0;
	if (tablica != NULL) // sprawdzanie warunku, czy tablica istnieje
	{
		delete[]tablica;
	}


}


void Tablica::stworzTablice() // funkcja, ktora tworzy tablice o zadanym rozmiarze
{
	system("cls");
	tablica = NULL;  // kasowanie wczesniejszej tablicy, zwalnanie pamieci

	cout << "Podaj rozmiar tablicy, ktora chcesz stworzyc." << endl;
	cout << "Rozmiar: ";
	cin >> rozmiarTablicy; // zapisywanie wczytanego rozmiaru do zmiennej

	tablica = new int[rozmiarTablicy]; // alokuje pamiec na nowa tablice o zadanym rozmiarze

	for (int i = 0; i < rozmiarTablicy; i++)//petla, ktora wypelnia tablice losowymi liczbami
	{
		tablica[i] = rand(); // wypelnianie tablicy losowymi liczbami 
	}

	system("cls");

	
}

void Tablica::wypiszTablice() // funkcja, ktora drukuje tablice na ekranie
{
	if (rozmiarTablicy > 0) // sprawdzanie warunku, czy tablica ma rozmiar wiekszy od 0 
	{
		cout << "Oto Twoja tablica:" << endl;

		for (int i = 0; i < rozmiarTablicy; i++) // petla, ktora wypisuje elementy tablicy w zaleznosci od jej rozmiaru
		{
			cout << i + 1 << ". " << tablica[i] << "   ";
		}

		cout << endl;
	}

	else cout << "Brak tablicy do wyswietlenia." << endl; // jezeli rozmiar tablicy jest rowny 0
	
}

void Tablica::zaladujZPliku() // funkcja, ktora wczytuje wartosci ze wczesniej przygotowanego pliku tekstowego o nazwie "wartosci.txt"
{
	tablica = NULL; // usuwanie poprzedniej tablicy

	fstream plik; // inicjalizacja zmiennej lokalnej potrzebnej do wczytania wartosci z pliku
	plik.open("wartosci.txt"); // podanie z jakiego pliku mamy czytac wartosci
	plik >> rozmiarTablicy; // ilosc elementow w pliku tekstowym jest zapisywana jako nowy rozmiar tablicy
	tablica = new int[rozmiarTablicy]; // towrzymy nowa tablice o rozmiarze elementow w pliku
	if (plik.good() == false) // sprawdczenie poprawnosci wczytywania pliku
		cout << "Plik zostal zle wczytany";
	for (int i = 0; i<rozmiarTablicy; i++) // jezeli poprawnie odczytano plik to petla wpisuje wartosci z pliku do nowej tablicy
		plik >> tablica[i];
	plik.close(); // zamkniecie pliku

}

void Tablica::dodajNaPoczatek(int wartosc) // funkcja, ktora dodaje wartosc na poczatek tablicy
{
	int *nowaTablica = new int[rozmiarTablicy + 1]; // alokowanie pamieci na tablice o 1 wieksza od poprzedniej
	nowaTablica[0] = wartosc; // przypisywanie zadanej wartosci na pierwszy indeks w tablicy

	for (int i = 0; i < rozmiarTablicy; i++) // przepisywanie wartosci ze starej tablicy do nowej
	{
		nowaTablica[i + 1] = tablica[i];
	}

	delete[]tablica; // zwalnanie pamieci
	tablica = nowaTablica; // przepisywanie nowej tablicy do starej
	nowaTablica = nullptr;
	rozmiarTablicy++; // zwiekszenie rozmiaru tablicy
}

void Tablica::dodajNaKoniec(int wartosc)// funkcja, ktora dodaje wartosc na koniec tablicy
{
	int*nowaTablica = new int[rozmiarTablicy + 1]; // alokowanie pamieci na tablice o 1 wieksza od poprzedniej
	nowaTablica[rozmiarTablicy] = wartosc; // przypisywanie wartosci na koniec nowej tablicy

	for (int i = 0; i < rozmiarTablicy; i++) // przepisanie wartosci ze starej tablicy do nowej
	{
		nowaTablica[i] = tablica[i];
	}

	delete[]tablica; // zwalnianie pamieci
	tablica = nowaTablica; // przepisywanie wartosci z tymczasowej tablicy do starej tablicy
	nowaTablica = nullptr; // usuwanie elementow tymczasowej tablicy
	rozmiarTablicy++; // zwiekszenie rozmiaru tablicy

}

void Tablica::dodajNaWybrany(int wartosc, int indeks) // funkcja, ktora dodaje wartosc na wybrany przez nas indeks w tablicy
{
	int*nowaTablica = new int[rozmiarTablicy + 1]; // alkowoanie pamieci dla tablicy o rozmiar wiekszej
	nowaTablica[indeks] = wartosc; // przypisywanie wartosci na zadany indeks
	
	for (int i = 0; i < indeks; i++) // przepisywanie wartosci do zadanego miejsca
	{
		nowaTablica[i] = tablica[i];
	}

	for (int i = indeks; i < rozmiarTablicy; i++) // przepisywanie wartosci od zadanego miejsca
	{
		nowaTablica[i+1] = tablica[i];
	}
	
	
	delete[]tablica; // zwalnianie pamieci
	tablica = nowaTablica; // przypisanie wartosci 
	nowaTablica = nullptr; // zwalnianie pamieci, poprzez usuwanie tymczasowej tablicy
	rozmiarTablicy++; // zwieksznie rozmiaru tablicy

}

void Tablica::usunPierwszy() // funkcja, ktora usuwa pierwszy element tablicy
{
	if (rozmiarTablicy > 0) // sprawdzanie czy tablica nie jest pusta
	{
		int*nowaTablica = new int[rozmiarTablicy - 1]; // alokowanie pamieci dla tablicy o rozmiar mniejszej od poprzedniej

		for (int i = 0; i < rozmiarTablicy; i++) // przepisywanie wartosci do nowej tablicy
		{
			nowaTablica[i] = tablica[i + 1];

		}

		delete[]tablica; // zwalnianie pamieci
		tablica = nowaTablica; // przypisywanie nowego wskaznika
		nowaTablica = nullptr; // zwalnianie pamieci
		rozmiarTablicy--; // zmniejszenie rozmiaru tablicy o 1
	}
	else
	{
		cout << "Tablica jest pusta, nie mozna nic usunac." << endl; // jezeli rozmiar tablicy jest rowny 0
	}
}

void Tablica::usunOstatni() // funkcja, ktora usuwa ostatni element tablicy
{
	
	if (rozmiarTablicy > 0) // sprawdzanie czy tablica nie jest pusta
	{
		int*nowaTablica = new int[rozmiarTablicy - 1]; // alokowanie pamieci na tablice o rozmiar mniejsza od poprzedniej

		for (int i = 0; i < rozmiarTablicy - 1; i++) // przepisywanie wartosci ze starej tablicy do nowej
		{
			nowaTablica[i] = tablica[i];

		}

		delete[]tablica;	// zwalnianie pamieci starego wskaznika
		tablica = nowaTablica; // przypisywanie nowego wskaznika
		nowaTablica = nullptr; // usuwanie tymczasowej tablicy
		rozmiarTablicy--; // zmniejszanie rozmiaru struktury
	}
	else
	{
		cout << "Tablica jest pusta, nie mozna nic usunac."; // jezeli rozmiar tablicy jest rowny 0
	}

}

void Tablica::usunWybrany(int indeks) // funkcja, ktora usuwa wybrany przez nas element z tablicy
{
	if (rozmiarTablicy > 0 || indeks > 0 || indeks < rozmiarTablicy) // sprawdzanie czy podany indeks spelania zalozenia oraz czy tablica istnieje
	{


		int*nowaTablica = new int[rozmiarTablicy - 1]; // zaalokowuje pamiec na tablice o 1 mniejsza od pierwotnej

		for (int i = 0; i < indeks; i++) // petla, ktora przepsuje wartosci do nowej tablicy po wybranej pozycji
		{
			nowaTablica[i] = tablica[i];
		}

		for (int i = indeks; i < rozmiarTablicy - 1; i++) // petla, ktora przepisuje wartosci do nowej tablicy po wybranej pozycji
		{
			nowaTablica[i] = tablica[i + 1];
		}

		delete[]tablica; // zwolnienie pamieci po starym wskazniku
		tablica = nowaTablica; // przypisanie nowego wskaznika 
		nowaTablica = nullptr; // zwolnienie pamieci, usuwanie tymczasowej tablicy
		rozmiarTablicy--; // zmniejszenie rozmiaru tablicy 
	}
	else
	{
		cout << "Nie mozna usunac tego elementu." << endl; // jezeli rozmiar tablicy jest rowny 0
	}

}

bool Tablica::znajdzWTablicy(int wartosc) // sprawdzanie czy podana przez nas wartosc jest jednym z elementow tablicy
{
	for (int i = 0; i < rozmiarTablicy; i++) // przeszukuje tablice pod k¹tem znalezienia zadanej wartosci
	{
		if (wartosc == tablica[i]) // jezeli zadana wartosc wystapi w strukturze zwroc true
		{
			cout << "Podana wartosc jest " << i+1 << " elementem tablicy." << endl;
			return true;
		}
	}
	cout << "Podanej wartosci nie ma w tablicy." << endl; // jezeli zadanej wartosci nie ma w tablicy, zwraca false
		return false;
	
	

}