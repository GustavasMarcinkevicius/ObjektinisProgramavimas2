#include "Includes.h"
#include "ManoVektorius.hpp"

int main(){

// Pradėti v1 užpildymo laiko matavimą

std::chrono::high_resolution_clock::time_point MatavimoPradzia = std::chrono::high_resolution_clock::now();
unsigned int sz = 100000000; // 10000, 100000, 1000000, 10000000, 100 000 000

 

std::vector<int> v1;

 

for (int i = 1; i <= sz; ++i) {

v1.push_back(i);
}
 

// Baigti v1 užpildymo laiko matavimą
std::chrono::high_resolution_clock::time_point MatavimoPabaiga = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> MatavimoLaikas = MatavimoPabaiga - MatavimoPradzia;
cout << "v1 laikas: " << MatavimoLaikas.count() << " sekundes" << endl;
 

// Pradėti v2 užpildymo laiko matavimą

std::chrono::high_resolution_clock::time_point MatavimoPradzia2 = std::chrono::high_resolution_clock::now(); 

ManoVektorius<int> v2;

 

for (int i = 1; i <= sz; ++i) {
    v2.push_back(i);
}
 

// Baigti v2 užpildymo laiko matavimą

std::chrono::high_resolution_clock::time_point MatavimoPabaiga2 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> MatavimoLaikas2 = MatavimoPabaiga2 - MatavimoPradzia2;
cout << "v2 laikas: " << MatavimoLaikas2.count() << " sekundes" << endl;
return 0;
}