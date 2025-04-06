#ifndef STRUKTURA_H
#define STRUKTURA_H
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Studentas {
    public:
        std::string vardas;
        std::string pavarde;
        std::vector<int> pazymiai;
        int egzaminoPazimys;
        double GalutinisBalasVidurkis;
        double GalutinisBalasMediana;
    
        Studentas() : vardas(""), pavarde(""), egzaminoPazimys(0), GalutinisBalasVidurkis(0.0), GalutinisBalasMediana(0.0) {}
};

#endif 
