#pragma once

#include <vector>
#include "Human.h"
#include "DataBase.h"
using namespace std; 

class LoveFinder: public DataBase {
public:
  LoveFinder(DataBase baza);

  vector<pair<Human, double>> znajdzLove(Human szukacz);
  void potwierdzDopasowanie(Human szukacz, Human dopasowywanaOsoba, double wyliczoneDopasowanie);
	~LoveFinder(){ };

private:
  double liczDopasowanie(Human szukacz, Human dopasowywanaOsoba);
  DataBase baza;
};
