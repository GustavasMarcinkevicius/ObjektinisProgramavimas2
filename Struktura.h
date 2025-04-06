#ifndef STRUKTURA_H
#define STRUKTURA_H
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    double egzaminoPazimys;
    double galutinisBalasVidurkis;
    double galutinisBalasMediana;

public:
    // Constructor
    Studentas() : egzaminoPazimys(0), galutinisBalasVidurkis(0), galutinisBalasMediana(0) {}

    ~Studentas() {}

    // Getters
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int>& getPazymiai() { return pazymiai; }
    double getEgzaminoPazimys() const { return egzaminoPazimys; }
    double getGalutinisBalasVidurkis() const { return galutinisBalasVidurkis; }
    double getGalutinisBalasMediana() const { return galutinisBalasMediana; }

    // Setters
    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setEgzaminoPazimys(double egzaminoPazimys) { this->egzaminoPazimys = egzaminoPazimys; }
    void setGalutinisBalasVidurkis(double balas) { galutinisBalasVidurkis = balas; }
    void setGalutinisBalasMediana(double balas) { galutinisBalasMediana = balas; }


};
#endif