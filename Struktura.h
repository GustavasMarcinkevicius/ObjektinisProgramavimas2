#ifndef STRUKTURA_H
#define STRUKTURA_H
#include <iostream>
#include <vector>

using std::string;
using std::vector;


class Studentas {
    private:
        std::string vardas_;
        std::string pavarde_;
        double egzaminas_;
        std::vector<double> nd_;
    
    public:
        Studentas() : egzaminas_(0) { }
    
        Studentas(std::istream& is);
    
        inline std::string vardas() const { return vardas_; }
    
        inline std::string pavarde() const { return pavarde_; }
   
    };

#endif 

