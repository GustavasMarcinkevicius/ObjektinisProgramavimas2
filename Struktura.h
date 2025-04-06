#ifndef STRUKTURA_H
#define STRUKTURA_H
#include <iostream>
#include <vector>

using std::string;
using std::vector;


class Studentas {
    private:
        std::string vardas;
        std::string pavarde;
        std::vector<int> pazymiai;
        int egzaminoPazimys;
        double GalutinisBalasVidurkis;
        double GalutinisBalasMediana;
    
    public:
        Studentas(const std::string& vardas, const std::string& pavarde,
                  const std::vector<int>& pazymiai, int egzaminoPazimys)
            : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egzaminoPazimys(egzaminoPazimys) {
            GalutinisBalasVidurkis = calculateFinalGradeAverage();
            GalutinisBalasMediana = calculateFinalGradeMedian();
        }
    
        std::string getVardas() const { return vardas; }
        std::string getPavarde() const { return pavarde; }
        double getGalutinisBalasVidurkis() const { return GalutinisBalasVidurkis; }
        double getGalutinisBalasMediana() const { return GalutinisBalasMediana; }
   
        double calculateFinalGradeAverage() {
            double avg = 0.0;
            for (int grade : pazymiai) {
                avg += grade;
            }
            if (!pazymiai.empty()) {
                avg /= pazymiai.size();
            }
            return 0.4 * avg + 0.6 * egzaminoPazimys;
        }
    
        double calculateFinalGradeMedian() {
            if (pazymiai.empty()) return 0.0;
            std::vector<int> sortedGrades = pazymiai;
            std::sort(sortedGrades.begin(), sortedGrades.end());
            int n = sortedGrades.size();
            double median = 0.0;
            if (n % 2 == 0) {
                median = (sortedGrades[n / 2 - 1] + sortedGrades[n / 2]) / 2.0;
            } else {
                median = sortedGrades[n / 2];
            }
            return 0.4 * median + 0.6 * egzaminoPazimys;
        }
    
     
        void printStudent() const {
            std::cout << std::left << std::setw(25) << vardas
                      << std::setw(25) << pavarde;
            for (int grade : pazymiai) {
                std::cout << std::setw(6) << grade;
            }
            std::cout << std::setw(6) << egzaminoPazimys << "\n";
        }
    };
    

#endif 

