#include <iostream>
#include <vector>

#include "Human.h"
#include "DataBase.h"
#include "LoveFinder.h"
#include "B.h"
#include "A.h"

using namespace std;


int main(int argc, char** argv) {
  DataBase baza; // baza w ktorej znajduja sie ludzie
//zaczyna sie dodawanie osob
  Human AnnaKowalska = Human("Anna", "Kowalska", "Blond", "Niebieskie", "Kobieta", "Mezczyzna", 30, vector<string>{"Zeglarstwo", "Siatkowka"}, vector<string>{"Zeglarstwo"}, "Brunet", "Brazowe");
  baza.dodajOsobe(AnnaKowalska);

  Human JanBrzeczyszczykiewicz = Human("Jan", "Brzeczyszczykiewicz", "Brunet", "Niebieskie", "Mezczyzna", "Kobieta", 27, vector<string>{"Informatyka", "Kino", "Ksiazki"}, vector<string>{"Kino", "Sport"}, "Blond", "Niebieskie");
  baza.dodajOsobe(JanBrzeczyszczykiewicz);
  
  Human JagodLazar = Human("Jagod", "Lazar", "Brunet", "Brazowe", "Mezczyzna", "Kobieta", 27, vector<string>{"Zeglarstwo", "Kino", "Ksiazki"}, vector<string>{"Kino", "Sport"}, "Blond", "Niebieskie");
  baza.dodajOsobe(JagodLazar);

  LoveFinder znajdywacz(baza);
  auto znalezioneLove = znajdywacz.znajdzLove(AnnaKowalska); // szukam loff dla Anny Kowalskiej

  if(znalezioneLove.size() == 0) {
    cout << "Niestety, nikogo nie znaleziono :/" << endl;
  } else {
    cout << "Znalezione osoby:" << endl;

    for(auto it = znalezioneLove.begin(); it != znalezioneLove.end(); ++it) { // znalezione love to vector osob i wspl. dopasowania
      try {
	    znajdywacz.potwierdzDopasowanie(AnnaKowalska, it->first, it->second); //1st imie osoby, 2nd wspolcz. dopasowania
	    
        cout << "Wspolczynnik dopasowania: " << it->second << endl;
        it->first.drukujPoszukiwacza(); // drukuje dane pierwszego elementu z pair czyli, osoby
      } 
	  catch(string s) {
	    cout << s << "cos jest nie tak" << endl; 
      }
    }
  }

  return 0;
}
