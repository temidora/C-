#include "DataBase.h"

DataBase::DataBase() : osoby(std::vector<Human>{}) {}; // lista inicjalizacyjna konstruktor parametryczny osobie przypisuje vector o typie Human

void DataBase::dodajOsobe(Human nowaOsoba) {
  osoby.push_back(nowaOsoba);  //
}

std::vector<Human>::iterator DataBase::begin() { 
  return osoby.begin();
}

std::vector<Human>::iterator DataBase::end() {
  return osoby.end();
}


