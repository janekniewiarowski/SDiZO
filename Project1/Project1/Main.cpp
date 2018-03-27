#include<iostream>
#include<string>
#include<conio.h>
#include"Tablica.h"
#include"Lista.h"
#include"Kopiec.h"
#include <time.h>
#include <fstream>
#include <windows.h>


using namespace std;


// menu tablicy, ktore pozwala przeprowadzac operacje na strukturze
void menuTablicy()
{
	int wybor = 100; // zmienna potrzebna do poruszania sie po menu

	Tablica mojaTablica; // tworzenie nowego obiektu klasy Tablica

	while (wybor != 0)
	{	// szereg operacji wykonywanych przez program
		cout << "Wybierz operacje:" << endl;
		cout << "    1. Dodaj wartosc na poczatek tablicy. " << endl;
		cout << "    2. Stworz tablice o podanym przez Ciebie rozmiarze." << endl;
		cout << "    3. Wypisz tablice." << endl;
		cout << "    4. Zaladuj tablice z pliku." << endl;
		cout << "    5. Dodaj wartosc na koniec tablicy." << endl;
		cout << "    6. Dodaj wartosc na wybrane miejsce w tablicy." << endl;
		cout << "    7. Usun pierwszy element tablicy." << endl;
		cout << "    8. Usun ostatni element tablicy." << endl;
		cout << "    9. Usun wybrany element tablicy." << endl;
		cout << "    10. Znajdz element w tablicy." << endl;
	
		cout << "    0. Powrot do glownego menu." << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;


		if (wybor == 1)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz dodac na poczatek tablicy." << endl;
			cin >> wartosc;
			//wywolywanie metowdy z klasy tablica
			mojaTablica.dodajNaPoczatek(wartosc); // dodawanie wartosci na poczatek tablicy
			system("cls");
		}

		if (wybor == 2)
		{	//wywolywanie metowdy z klasy tablica
			mojaTablica.stworzTablice(); // tworzenie tablicy o zadanym rozmiarze
			system("cls");
		}

		if (wybor == 3)
		{//wywolywanie metowdy z klasy tablica
			system("cls");
			mojaTablica.wypiszTablice(); // drukowanie tablicy na ekranie

		}

		if (wybor == 4)
		{//wywolywanie metowdy z klasy tablica
			system("cls");
			mojaTablica.zaladujZPliku(); // ladowaniee wartosci z pliku do tablicy
		}

		if (wybor == 5)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz dodac na koniec tablicy." << endl;
			cin >> wartosc;

			system("cls");
			mojaTablica.dodajNaKoniec(wartosc);//wywolywanie metowdy z klasy tablica, dodawanie zadanej wartosci na koniec tablicy
		}

		if (wybor == 6)
		{
			int wartosc;
			int indeks;

			cout << "Podaj wartosc, ktora chcesz dodac do tablicy." << endl;
			cin >> wartosc;

			cout << "Podaj pozycje, na ktora chcesz dodac element do tablicy." << endl;
			cin >> indeks;

			indeks = indeks - 1;

			system("cls");
			mojaTablica.dodajNaWybrany(wartosc, indeks);//wywolywanie metowdy z klasy tablica, dodawanie wybranej wartosci na wybrana pozycje naszej tablicy
		}

		if (wybor == 7)
		{
			system("cls");
			mojaTablica.usunPierwszy();//wywolywanie metowdy z klasy tablica, usuwa pierwszy element z naszej tablicy

		}

		if (wybor == 8)
		{
			system("cls");
			mojaTablica.usunOstatni();//wywolywanie metowdy z klasy tablica, usuwa ostatni element naszej tablicy

		}

		if (wybor == 9)
		{
			int indeks;
			cout << "Podaj pozycje, ktora chcesz usunac wartosc z tablicy." << endl;
			cin >> indeks;

			indeks = indeks - 1;
			system("cls");
			mojaTablica.usunWybrany(indeks);//wywolywanie metowdy z klasy tablica, usuwa element o podanym przez nas indeksie
		}

		if (wybor == 10)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz znalezc w tablicy." << endl;
			cin >> wartosc;
			system("cls");
			mojaTablica.znajdzWTablicy(wartosc);//wywolywanie metowdy z klasy tablica, sprawdza czy zadana wartosc zgadza sie z ktoras z wartosci w tablicy
		}

	}
}


// menu Kopca, ktore pozwala na operacje na tej strukturze
void menuKopca()
{
	int wybor = 100; // zmienna potrzebna do korzystania z menu
	

	Kopiec mojKopiec; // tworzenie nowego obiektu klasy Kopiec

	while (wybor != 0)
	{
		cout << "Wybierz operacje:" << endl;
		cout << "    1. Zaladuj kopiec z pliku. " << endl;
		cout << "    2. Wyswietl kopiec. " << endl;
		cout << "    3. Dodaj do kopca. " << endl;
		cout << "    4. Usun z kopca. " << endl;
		cout << "    5. Znajdz w kopcu. " << endl;

		cout << "    0. Powrot do glownego menu." << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		if (wybor == 1)
		{
			system("cls");
			mojKopiec.zaladujZPliku();//wywolywanie metowdy z klasy Kopiec, zaladowanie wartosci z pliku do kopca
		}

		if (wybor == 2)
		{
			system("cls");
			mojKopiec.wyswietlKopiec("", "", 0);//wywolywanie metody z klasy Kopiec, wyswietlanie kopca w postaci drzewa na ekranie
		}
		
		if (wybor == 3)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz dodac do kopca." << endl;
			cin >> wartosc; // wartosc, ktora bedzie dodana do kopca

			system("cls");
			mojKopiec.dodajDoKopca(wartosc);//wywolywanie metowdy z klasy Kopiec, dodanie wartosci do kopca
		}

		if (wybor == 4)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz usunac do kopca." << endl;
			cin >> wartosc; // wartosc, ktora zostanie usunieta z kopca

			system("cls");
			mojKopiec.usunZKopca(wartosc);//wywolywanie metowdy z klasy Kopiec, usuwanie wybranej wartosci z kopca
		}

		if (wybor == 5)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz znalezc w kopcu." << endl;
			cin >> wartosc;

			system("cls");
			mojKopiec.znajdzWKopcu(wartosc);//wywolywanie metowdy z klasy Kopiec, sprawdzanie czy wartosc w kopcu odpowiada zadanej przez nas wartosci
		}

	}


}
//menu listy, pozwala na operacje na tej strukturze
void menuListy()
{
	int wybor = 100; // zmienna pomocnicza, do poruszania sie po menu

	Lista mojaLista; // tworzenie obiektu klasy Lista

	while (wybor != 0)
	{
		cout << "	 Wybierz operacje:" << endl;
		cout << "    1. Dodaj wartosc do listy. " << endl;
		cout << "    2. Wypisz liste." << endl;
		cout << "    3. Usun wartosc z listy." << endl;
		cout << "    4. Stworz liste o podanym przez Ciebie rozmiarze." << endl;
		cout << "    5. Wczytaj liste z pliku." << endl;
		cout << "    6. Znajdz wartosc w liscie." << endl;
		cout << "    7. Usun pierwszy element listy." << endl;
		cout << "    8. Usun ostatni element listy." << endl;

		cout << "    0. Powrot do glownego menu." << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		if (wybor == 1)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz dodac do listy." << endl;
			cin >> wartosc;
			system("cls");

			int pozycja;
			cout << "Podaj pozycje, na ktora chcesz zapisac podana wartosc." << endl;
			cin >> pozycja;
			system("cls");

			mojaLista.dodajDoListy(wartosc, pozycja); // wywolywanie metody zawartej w klasie Lista, dodawanie elementu do listy na wybrany indeks, poczatek lub koniec
		}

		if (wybor == 2)
		{
		
			mojaLista.wypiszListe();// wywolywanie metody zawartej w klasie Lista, wypisywanie listy na ekranie
		}

		if (wybor == 3)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz usunac z listy." << endl;
			cin >> wartosc; 
			system("cls");
			mojaLista.usunZListy(wartosc);// wywolywanie metody zawartej w klasie Lista, usuwanie zadanej wartosci z kopca
		}
		
		if (wybor == 4)
		{
			int rozmiar;
			cout << "Podaj rozmiar listy, ktora chcesz stworzyc." << endl;
			cin >> rozmiar;
			system("cls");
			mojaLista.stworzListe(rozmiar);// wywolywanie metody zawartej w klasie Lista, tworzenie listy o zadanym przez nas rozmiarze, wypelnienie jej losowymi wartosciami
		}

		if (wybor == 5)
		{
			string nazwa;
			cout << "Podaj nazwe pliku." << endl; // nazwa pliku, ktory chcemy otworzyc
			cin >> nazwa;
			system("cls");
			mojaLista.zaladujZPliku(nazwa);// wywolywanie metody zawartej w klasie Lista, otwieramy plik o zadanej przez nas nazwie i wczytujemy z niego wartosci do listy
		}

		if (wybor == 6)
		{
			int wartosc;
			cout << "Podaj wartosc, ktora chcesz znalezc." << endl;
			cin >> wartosc; // wartosc, ktora bedzie poszukiwana w liscie
			system("cls");// wywolywanie metody zawartej w klasie Lista
			mojaLista.znajdzWLiscie(wartosc); // sprawdzanie czy w podana wartosc znajduje sie w tablicy
		}

		if (wybor == 7)
		{
			mojaLista.usunPierwszy(); // usuwanie pierwszego elementu z listy
		}

		if (wybor == 8)
		{
			mojaLista.usunOstatni(); // usuwanie ostatniego elementu listy
		}
	}

}

int main()
{
	int wybor = 100;
	// ogolne menu, dzieki ktoremu mozemy wybrac na jakiej strukturze chcemy dzialac 
	while (wybor != 0) {
		cout << "Wybierz strukture:" << endl;
		cout << "    1. Tablica " << endl;
		cout << "    2. Lista" << endl;
		cout << "    3. Kopiec Binarny" << endl;
		cout << "    0. Wyjscie" << endl << endl;
		cout << "Wybor: ";
		cin >> wybor;

		//Zamknij, je¿eli wybrano 0
		if (wybor == 0)
		{
			return 0;
		}
		//przejdz do menu tablicy jezeli wybrano 1
		if (wybor == 1)
		{
			system("cls");
			menuTablicy();
			
		}
		//przejdz do menu listy jezeli wybrano 2
		if (wybor == 2)
		{
			system("cls");
			menuListy();
		}
		// przejdz do menu kopca jezeli wybrano 3
		if (wybor == 3)
		{
			system("cls");
			menuKopca();

		}
	}
	return 0;
}


