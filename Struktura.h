#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

#ifndef ZMOGUS_H
#define ZMOGUS_H

class Zmogus {
public:
    // Default constructor
    Zmogus() = default;

    // Virtual destructor
    virtual ~Zmogus() = default;

    // Copy constructor
    Zmogus(const Zmogus& other)
        : vardas(other.vardas), pavarde(other.pavarde) {}

    // Copy assignment operator
    Zmogus& operator=(const Zmogus& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
        }
        return *this;
    }

    // Move constructor
    Zmogus(Zmogus&& other) noexcept
        : vardas(std::move(other.vardas)), pavarde(std::move(other.pavarde)) {}

    // Move assignment operator
    Zmogus& operator=(Zmogus&& other) noexcept {
        if (this != &other) {
            vardas = std::move(other.vardas);
            pavarde = std::move(other.pavarde);
        }
        return *this;
    }


    virtual void readFromConsole() = 0;
    virtual void print() const = 0;

protected:
   
    string vardas;  
    string pavarde; 
};

#endif // ZMOGUS_H

#ifndef STRUKTURA_H
#define STRUKTURA_H

class Studentas : public Zmogus {
private:
    vector<int> pazymiai;
    double egzaminoPazimys = 0;
    double galutinisBalasVidurkis = 0;
    double galutinisBalasMediana = 0;

public:
    // Default constructor
    Studentas() = default;

    // Destructor
    ~Studentas() = default;

    // Copy constructor
    Studentas(const Studentas& other)
        : Zmogus(other),
          pazymiai(other.pazymiai),
          egzaminoPazimys(other.egzaminoPazimys),
          galutinisBalasVidurkis(other.galutinisBalasVidurkis),
          galutinisBalasMediana(other.galutinisBalasMediana) {}

    // Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other); 
            pazymiai = other.pazymiai;
            egzaminoPazimys = other.egzaminoPazimys;
            galutinisBalasVidurkis = other.galutinisBalasVidurkis;
            galutinisBalasMediana = other.galutinisBalasMediana;
        }
        return *this;
    }

    // Move constructor
    Studentas(Studentas&& other) noexcept
        : Zmogus(std::move(other)), 
          pazymiai(std::move(other.pazymiai)),
          egzaminoPazimys(other.egzaminoPazimys),
          galutinisBalasVidurkis(other.galutinisBalasVidurkis),
          galutinisBalasMediana(other.galutinisBalasMediana) {}

    // Move assignment operator
    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            Zmogus::operator=(std::move(other));  
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

    //read from console
    void readFromConsole() override {
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

        // read from file
        void readFromFile(istream& in) {
            pazymiai.clear();
            in >> vardas >> pavarde;
        
            int paz;
            while (in >> paz) {
                pazymiai.push_back(paz);
            }
        
            egzaminoPazimys = pazymiai.back();
            pazymiai.pop_back();  
        };

    //print
    void print() const override {
        cout << left << setw(20) << vardas 
             << setw(20) << pavarde         
             << setw(15) << galutinisBalasVidurkis
             << setw(15) << galutinisBalasMediana
             << endl;
    }
};

#endif 
