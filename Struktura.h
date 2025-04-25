#ifndef STRUKTURA_H
#define STRUKTURA_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>  // For std::setw and formatting output

using namespace std;

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    double egzaminoPazimys = 0;
    double galutinisBalasVidurkis = 0;
    double galutinisBalasMediana = 0;

public:
    // Default constructor default
    Studentas() = default;

    // Destructor default
    ~Studentas() = default;

    // Copy constructor
    Studentas(const Studentas& other)
        : vardas(other.vardas),
          pavarde(other.pavarde),
          pazymiai(other.pazymiai),
          egzaminoPazimys(other.egzaminoPazimys),
          galutinisBalasVidurkis(other.galutinisBalasVidurkis),
          galutinisBalasMediana(other.galutinisBalasMediana) {}

    // Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            pazymiai = other.pazymiai;
            egzaminoPazimys = other.egzaminoPazimys;
            galutinisBalasVidurkis = other.galutinisBalasVidurkis;
            galutinisBalasMediana = other.galutinisBalasMediana;
        }
        return *this;
    }

    // Move constructor
    Studentas(Studentas&& other) noexcept
        : vardas(std::move(other.vardas)),
          pavarde(std::move(other.pavarde)),
          pazymiai(std::move(other.pazymiai)),
          egzaminoPazimys(other.egzaminoPazimys),
          galutinisBalasVidurkis(other.galutinisBalasVidurkis),
          galutinisBalasMediana(other.galutinisBalasMediana) {}

    // Move assignment operator
    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            vardas = std::move(other.vardas);
            pavarde = std::move(other.pavarde);
            pazymiai = std::move(other.pazymiai);
            egzaminoPazimys = other.egzaminoPazimys;
            galutinisBalasVidurkis = other.galutinisBalasVidurkis;
            galutinisBalasMediana = other.galutinisBalasMediana;
        }
        return *this;
    }

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

    // Method to read input from the console
    void readFromConsole() {
        pazymiai.clear();
        cout << "Vardas: ";
        cin >> vardas;
        cout << "Pavarde: ";
        cin >> pavarde;
    
        cout << "Iveskite pazymius (iveskite -1 kad baigti):\n";
        int paz;
        while (cin >> paz && paz != -1) {
            pazymiai.push_back(paz);
        }
        cout << "Iveskite egzamino pazymi:\n";
        cin >> egzaminoPazimys;
    }

    // Method to read input from the file
    void readFromFile(istream& in) {
        pazymiai.clear();
        in >> vardas >> pavarde;
    
        int paz;
        while (in >> paz) {
            pazymiai.push_back(paz);
        }
    
        egzaminoPazimys = pazymiai.back();
        pazymiai.pop_back();  
    }
};

// Output 
std::ostream& operator<<(std::ostream& out, const Studentas& s) {
    out << std::left << std::setw(20) << s.getVardas()         
        << std::setw(15) << s.getGalutinisBalasVidurkis()         
        << std::setw(15) << s.getGalutinisBalasMediana()           
        << std::endl;                                            
    return out;
}

#endif