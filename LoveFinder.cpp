#include "LoveFinder.h"
#include <algorithm>
using namespace std; 

int wielkoscCzesciWsplolnej(vector<string> &v1, vector<string> &v2) { //v1 to vector pasji 1 osoby, v2 to vector pasji 2 osoby
  vector<string> v3; //wektor pasji czesci wspolnej

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  set_intersection(v1.begin(),v1.end(), //set_intersection sprawdza ile jes elementow czesci wspolnej obu wektorow, ktore musza byc odpowiednio posortowane
                        v2.begin(),v2.end(),
                        back_inserter(v3)); // część wspolna obu wektorow wsadzana jest do v3
  return v3.size();
}

LoveFinder::LoveFinder(DataBase baza) {
  this->baza = baza;
};

vector<pair<Human, double>> LoveFinder::znajdzLove(Human szukacz) {
  vector<pair<Human, double>> znalezioneLove{};

  for(auto it = baza.begin(); it != baza.end(); ++it) {
		Human dopasowywanaOsoba = *it; // sprawdzam po calej bazie

  		if(szukacz == dopasowywanaOsoba) {
     		 continue; // przy spotkaniu w bazie osoby do ktorej szukamy partnera, kontynuuj
   		 }

    	double wspolczynnikDopasowania = liczDopasowanie(szukacz, dopasowywanaOsoba); // liczdopasowanie zdefiniowane nizej
   		if(wspolczynnikDopasowania > 0) {
      		znalezioneLove.push_back(pair<Human, double>{dopasowywanaOsoba, wspolczynnikDopasowania});
    }
  }
  return znalezioneLove; // zwraca caly zbior ludzi , ktorzy jakos pasuja
};

double LoveFinder::liczDopasowanie(Human szukacz, Human dopasowywanaOsoba) {
  if(szukacz.preferowanaPlec != dopasowywanaOsoba.plec) {
    return 0.0;
  }

  int liczbaDopasowan = 1;
  int maksymalneDopasowanie = 3 + szukacz.preferencjePasji.size();

  if(szukacz.preferencjaWlosy == dopasowywanaOsoba.wlosy) {
    liczbaDopasowan++;
  }

  if(szukacz.preferencjaOczy == dopasowywanaOsoba.oczy) {
    liczbaDopasowan++;
  }

  liczbaDopasowan += wielkoscCzesciWsplolnej(szukacz.preferencjePasji, dopasowywanaOsoba.pasje);

  return (double) liczbaDopasowan / (double) maksymalneDopasowanie;
};

void LoveFinder::potwierdzDopasowanie(Human szukacz, Human dopasowywanaOsoba, double wyliczoneDopasowanie) {
	if (liczDopasowanie(szukacz, dopasowywanaOsoba) != wyliczoneDopasowanie) throw "niezgodnosc";
};
