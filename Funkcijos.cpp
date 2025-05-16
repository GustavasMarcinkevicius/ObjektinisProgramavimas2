#include "Includes.h"
#include "Struktura.h"
#ifdef NOMINMAX
#undef NOMINMAX
#endif
#define NOMINMAX
#define byte win_byte_override 
#include <windows.h>
#undef byte

#include <filesystem>

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

string generateRandomName() {
    vector<string> vardai = {"Lonnie", "Sylvain", "Lukas", "Ignas", "Dovydas", "Laurynas", "Alen", "Matt", "Tomas", "Bryant", "Brady", "Arnas", "Deividas", "Edgaras"};
    return vardai[generateRandomNumber(0, vardai.size() -1 )];
}

string generateRandomSurname() {
    vector<string> pavardes = {"Walker IV", "Francisko", "Lekavicius", "Brazdeikis", "Giedraitis", "Birutis", "Smailagic", "Mitchell", "Dimsa", "Dunston", "Manek", "Butkevicius", "Sirvydis", "Ulanovas"};
    return pavardes[generateRandomNumber(0, pavardes.size() -1 )];
}

void ApskaiciuotiVeikimoLaikoVidurki() {
    std::ifstream file("TestavimoLaikuLog.txt");

    double inputTime, runningTime;
    std::vector<double> inputTimes;
    std::vector<double> runningTimes;

    while (file >> inputTime >> runningTime) {
        inputTimes.push_back(inputTime);
        runningTimes.push_back(runningTime);
    }

    file.close();

    double totalInputTime = 0.0;
    for (double time : inputTimes) {
        totalInputTime += time;
    }
    double avgInputTime = totalInputTime / inputTimes.size();

    double totalRunningTime = 0.0;
    for (double time : runningTimes) {
        totalRunningTime += time;
    }
    double avgRunningTime = totalRunningTime / runningTimes.size();

    std::cout << "Vidutinis Skaitymo laikas: " << std::fixed << std::setprecision(6) << avgInputTime << " sekundziu" << std::endl;
    std::cout << "Vidutinis Programos veikimo laikas: " << std::fixed << std::setprecision(6) << avgRunningTime << " sekundziu" << std::endl;
}

template <typename Container>
void sortStudentai(Container& studentai, int RusiavimoPasirinkimas, int DuomenuKiekis) {
    if (RusiavimoPasirinkimas == 1) { // pagal varda
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVardas() < b.getVardas();
        });
    } else if (RusiavimoPasirinkimas == 2) { // pagal pavarde
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde();
        });
    } else if (RusiavimoPasirinkimas == 3 && DuomenuKiekis == 0) { // pagal vidurki
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.getGalutinisBalasVidurkis() > b.getGalutinisBalasVidurkis();
        });
    } else if (RusiavimoPasirinkimas == 4 && DuomenuKiekis == 1) { // pagal mediana
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.getGalutinisBalasMediana() > b.getGalutinisBalasMediana();
        });
    }
}
template void sortStudentai<ManoVektorius<Studentas>>(ManoVektorius<Studentas>& studentai, int RusiavimoPasirinkimas, int DuomenuKiekis);
template void sortStudentai<std::vector<Studentas>>(std::vector<Studentas>& studentai, int RusiavimoPasirinkimas, int DuomenuKiekis);
template void sortStudentai<std::deque<Studentas>>(std::deque<Studentas>& studentai, int RusiavimoPasirinkimas, int DuomenuKiekis);

void sortStudentaiList(std::list<Studentas>& studentai, int RusiavimoPasirinkimas) {
    if (RusiavimoPasirinkimas == 1) { // pagal varda
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.getVardas() < b.getVardas();
        });
    } else if (RusiavimoPasirinkimas == 2) { // pagal pavarde
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde();
        });
    } else if (RusiavimoPasirinkimas == 3) { // pagal vidurki
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.getGalutinisBalasVidurkis() > b.getGalutinisBalasVidurkis();
        });
    } else if (RusiavimoPasirinkimas == 4) { // pagal mediana
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.getGalutinisBalasMediana() > b.getGalutinisBalasMediana();
        });
    }
}

void generateFile(int numStudents) {
    std::string filename = "SugeneruotiStudentai" + std::to_string(numStudents) + ".txt";
    std::ofstream file(filename);

    std::ios::sync_with_stdio(false);

    int pazymiuSkaicius = generateRandomNumber(5, 15);

    file << std::left << std::setw(25) << "Vardas"
         << std::setw(25) << "Pavarde";

    for (int i = 1; i <= pazymiuSkaicius; i++) {
        file << std::setw(6) << "ND" + std::to_string(i);
    }
    file << std::setw(6) << "Egz." << "\n";

    for (int i = 1; i <= numStudents; i++) {
        std::string name = "Vardas" + std::to_string(i);
        std::string surname = "Pavarde" + std::to_string(i);

        file << std::left << std::setw(25) << name
             << std::setw(25) << surname;

        for (int j = 0; j < pazymiuSkaicius + 1; j++) {
            file << std::setw(6) << generateRandomNumber(1, 10);
        }

        file << "\n";
    }

    file.close();
}

std::string getExecutableDir() {
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    return std::filesystem::path(path).parent_path().string();
}