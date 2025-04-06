#include "Includes.h"

void SuListais(int StrategijosPasirinkimas){
    std::chrono::high_resolution_clock::time_point KietekuPabaiga;
    std::chrono::duration<double> KietekuLaikas;
    int StudentuKiekis;
    int Rusiavimas;
    std::ostringstream output;
    std::list<Studentas> studentai;
    std::list<Studentas> kietekai;  
    std::list<Studentas> vargsiukai;  

    cout << "Irasykite studentu kieki: "; cin >> StudentuKiekis;
    cout << "Pasirinkite rusiavimo tipa:" << endl;
    cout << "Pagal galutini pazymi (nuo Vidurkio) - 1" << endl;
    cout << "Pagal galutini pazymi (nuo Medianos) - 2" << endl;
    cin >> Rusiavimas;
    Rusiavimas = Rusiavimas+2; // +2, nes atmesti rusiavimai pagal varda ir pavarde, kurie buvo 1 ir 2
    std::string directory = "C:\\Users\\gusta\\Desktop\\Objektinis Github\\SugeneruotiFailai";
    std::string filename = directory + "\\SugeneruotiStudentai" + std::to_string(StudentuKiekis) + ".txt";

    namespace fs = std::filesystem;

    std::ifstream InputFile(filename, std::ios::in);
    std::ofstream OutputFile1("Kietekai.txt", std::ios::trunc);
    std::ofstream OutputFile2("Vargsiukai.txt", std::ios::trunc);

    std::chrono::high_resolution_clock::time_point Readingstart = std::chrono::high_resolution_clock::now();

    string header;
    getline(InputFile, header);

    string line;
    while (getline(InputFile, line)) {
        std::istringstream lineStream(line);
        Studentas naujasStudentas;

        string vardas, pavarde;
        lineStream >> vardas >> pavarde;  
        naujasStudentas.setVardas(vardas); 
        naujasStudentas.setPavarde(pavarde);
        int pazymys;
        while (lineStream >> pazymys) {
            naujasStudentas.getPazymiai().push_back(pazymys);
        }
int examGrade = naujasStudentas.getPazymiai().back();
naujasStudentas.setEgzaminoPazimys(examGrade);
naujasStudentas.getPazymiai().pop_back();
        studentai.push_back(naujasStudentas);
    }

    InputFile.close();

    std::chrono::high_resolution_clock::time_point Readingend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> Readingduration = Readingend - Readingstart;

    std::chrono::high_resolution_clock::time_point RikiavimoPradzia = std::chrono::high_resolution_clock::now();

    for  (auto& studentas : studentai) {
        double Vidurkis = 0, Mediana = 0;
        studentas.setGalutinisBalasVidurkis(0);
        studentas.setGalutinisBalasMediana(0);

        for (int pazymys : studentas.getPazymiai()) {
            Vidurkis += pazymys;
        }

        if (!studentas.getPazymiai().empty()) {
            Vidurkis /= studentas.getPazymiai().size();
        }

        std::vector<int> sortedPazymiai = studentas.getPazymiai();
        sort(sortedPazymiai.begin(), sortedPazymiai.end());

        if (!sortedPazymiai.empty()) {
            int n = sortedPazymiai.size();
            if (n % 2 == 0) {
                Mediana = (sortedPazymiai[n / 2 - 1] + sortedPazymiai[n / 2]) / 2.0;
            } else {
                Mediana = sortedPazymiai[n / 2];
            }
        }
       
        studentas.setGalutinisBalasMediana(0.4 * Mediana + 0.6 * studentas.getEgzaminoPazimys()); 
        studentas.setGalutinisBalasVidurkis(0.4 * Vidurkis + 0.6 * studentas.getEgzaminoPazimys()); 
    }; 
    
    sortStudentaiList(studentai, Rusiavimas);

    std::chrono::high_resolution_clock::time_point RikiavimoPabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> RikiavimoLaikas = RikiavimoPabaiga - RikiavimoPradzia;

    
    std::chrono::high_resolution_clock::time_point RusiavimoPradzia = std::chrono::high_resolution_clock::now();

if(StrategijosPasirinkimas == 1){

    for  (auto& studentas : studentai) {
        if (Rusiavimas == 3) { 
            if (studentas.getGalutinisBalasVidurkis() >= 5) {
                kietekai.push_back(studentas);
            } else {
                vargsiukai.push_back(studentas); 
            }
        } else if (Rusiavimas == 4) {  
            if (studentas.getGalutinisBalasMediana() >= 5) {
                kietekai.push_back(studentas);  
            } else {
                vargsiukai.push_back(studentas);
            }
        }
    }

}


else if (StrategijosPasirinkimas == 2){
        if (Rusiavimas == 3) {
            for (auto it = studentai.begin(); it != studentai.end(); ) {
            if (it->getGalutinisBalasVidurkis() < 5) {
                vargsiukai.push_back(*it);
                it = studentai.erase(it);  
            } else {
                ++it;
            };
            }
        }
        if (Rusiavimas == 4) {
            for (auto it = studentai.begin(); it != studentai.end(); ) {
            if (it->getGalutinisBalasMediana() < 5) {
                vargsiukai.push_back(*it);
                it = studentai.erase(it);  
            } else {
                ++it;
            };
            }
        }
    }

// else if (StrategijosPasirinkimas == 2) {

//     if (Rusiavimas == 3) {
    
//         while (!studentai.empty() && studentai.back().GalutinisBalasVidurkis < 5) {
//             vargsiukai.push_back(studentai.back());
//             studentai.pop_back(); 
//         }
//     }

//     if (Rusiavimas == 4) {
//         while (!studentai.empty() && studentai.back().GalutinisBalasMediana < 5) {
//             vargsiukai.push_back(studentai.back()); 
//             studentai.pop_back();  
//         }
//     }

// }

    std::chrono::high_resolution_clock::time_point RusiavimoPabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> RusiavimoLaikas = RusiavimoPabaiga - RusiavimoPradzia;

    std::chrono::high_resolution_clock::time_point KietekuPradzia = std::chrono::high_resolution_clock::now();
    OutputFile1 << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)\n";
    OutputFile1 << "--------------------------------------------------------------------------\n";

if (StrategijosPasirinkimas == 1){

    for (const auto& studentas : kietekai) {
        OutputFile1 << left << setw(20) << studentas.getVardas()
                   << left << setw(20) << studentas.getPavarde()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasVidurkis()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasMediana()
                   << '\n';
    }
    
  KietekuPabaiga = std::chrono::high_resolution_clock::now();
  KietekuLaikas = KietekuPabaiga - KietekuPradzia;

    
    std::chrono::high_resolution_clock::time_point VargsiukuPradzia = std::chrono::high_resolution_clock::now();
    OutputFile2 << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)\n";
    OutputFile2 << "--------------------------------------------------------------------------\n";
    for (const auto& studentas : vargsiukai) {
        OutputFile2 << left << setw(20) << studentas.getVardas()
                   << left << setw(20) << studentas.getPavarde()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasVidurkis()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasMediana()
                   << '\n';
    }
}

if (StrategijosPasirinkimas == 2){

    for (const auto& studentas : studentai) {
        OutputFile1 << left << setw(20) << studentas.getVardas()
                   << left << setw(20) << studentas.getPavarde()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasVidurkis()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasMediana()
                   << '\n';
    }
    
  KietekuPabaiga = std::chrono::high_resolution_clock::now();
  KietekuLaikas = KietekuPabaiga - KietekuPradzia;

    
    std::chrono::high_resolution_clock::time_point VargsiukuPradzia = std::chrono::high_resolution_clock::now();
    OutputFile2 << "Vardas              Pavarde             Galutinis (Vid.)/ Galutinis (Med.)\n";
    OutputFile2 << "--------------------------------------------------------------------------\n";
    for (const auto& studentas : vargsiukai) {
        OutputFile2 << left << setw(20) << studentas.getVardas()
                   << left << setw(20) << studentas.getPavarde()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasVidurkis()
                   << left << setw(18) << fixed << setprecision(2) << studentas.getGalutinisBalasMediana()
                   << '\n';
    }
}

    std::chrono::high_resolution_clock::time_point VargsiukuPabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> VargsiukuLaikas = KietekuPabaiga - KietekuPradzia;
    std::chrono::high_resolution_clock::time_point ProgramEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> ProgramDuration = ProgramEnd - Readingstart;
    cout << "Failo su " << StudentuKiekis << " studentu nuskaitymo laikas: " << Readingduration.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu isskirstymas didejimo tvarka: " << RikiavimoLaikas.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu isskirstymo i kietekus ir vargsiukus laikas: " << RusiavimoLaikas.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu kieteku irasymo laikas: " << KietekuLaikas.count() << " sekundes" << endl;
    cout << StudentuKiekis << " Studentu vargsiuku irasymo laikas: " << VargsiukuLaikas.count() << " sekundes" << endl;
    cout << "Visos programos veikimo laikas: " << ProgramDuration.count() << " sekundes" << endl;
}
