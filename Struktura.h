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
        std::string vardas;
        std::string pavarde;
        std::vector<int> pazymiai;
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
        std::string getVardas() const { return vardas; }
        std::string getPavarde() const { return pavarde; }
        std::vector<int>& getPazymiai() { return pazymiai; }
        double getEgzaminoPazimys() const { return egzaminoPazimys; }
        double getGalutinisBalasVidurkis() const { return galutinisBalasVidurkis; }
        double getGalutinisBalasMediana() const { return galutinisBalasMediana; }
    
        // Setters
        void setVardas(const std::string& v) { vardas = v; }
        void setPavarde(const std::string& p) { pavarde = p; }
        void setEgzaminoPazimys(double egzaminoPazimys) { this->egzaminoPazimys = egzaminoPazimys; }
        void setGalutinisBalasVidurkis(double balas) { galutinisBalasVidurkis = balas; }
        void setGalutinisBalasMediana(double balas) { galutinisBalasMediana = balas; }
    
    }; 

#endif