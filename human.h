#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std; 

enum class Plec { Kobieta, Mezczyzna }; // Kobieta=0, Mezczyzna=1 domyslnie z enum

class Human {
public:
  string imie, nazwisko, wlosy, oczy;
  Plec plec;
  Plec preferowanaPlec;
  vector<string> pasje;
  vector<string> preferencjePasji;
  string preferencjaWlosy;
  string preferencjaOczy;
  
  Human(string imie, string nazwisko, string wlosy, string oczy, string plec, string preferowanaPlec, int wiek, vector<string> pasje, vector<string> preferencjePasji, string preferencjaWlosy, string preferencjaOczy);
// konstruktor 
  bool operator == (Human innaOsoba) {
    return imie == innaOsoba.imie && nazwisko == innaOsoba.nazwisko && wiek == innaOsoba.wiek; // przeciazenie operatora
  };

  void dodajPasje(string nowaPasja);
  void drukujPoszukiwacza();

 //~Human(){ };
 
private:
  string plecString();
  int wiek;
};
