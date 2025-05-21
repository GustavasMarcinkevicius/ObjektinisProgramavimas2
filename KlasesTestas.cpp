#include <iostream>
#include <cassert>
#include "Struktura.h" 

void testDefaultConstructor() {
    Studentas s;
    assert(s.getVardas() == "");
    assert(s.getPavarde() == "");
    assert(s.getPazymiai().empty());
    assert(s.getEgzaminoPazimys() == 0);
    assert(s.getGalutinisBalasVidurkis() == 0);
    assert(s.getGalutinisBalasMediana() == 0);
    std::cout << "Default konstruktoriaus testas sekmingas!.\n";
}

void testSettersAndGetters() {
    Studentas s;
    s.setVardas("Jonas");
    s.setPavarde("Jonaitis");
    s.setEgzaminoPazimys(9.5);
    s.setGalutinisBalasVidurkis(8.0);
    s.setGalutinisBalasMediana(8.5);
    
    assert(s.getVardas() == "Jonas");
    assert(s.getPavarde() == "Jonaitis");
    assert(s.getEgzaminoPazimys() == 9.5);
    assert(s.getGalutinisBalasVidurkis() == 8.0);
    assert(s.getGalutinisBalasMediana() == 8.5);
    std::cout << "Setters ir getters testas sekmingas!\n";
}

void testCopyConstructor() {
    Studentas original;
    original.setVardas("Petras");
    original.setPavarde("Petraitis");
    original.getPazymiai().push_back(10);
    original.setEgzaminoPazimys(9);
    
    Studentas copy(original);
    assert(copy.getVardas() == "Petras");
    assert(copy.getPazymiai()[0] == 10);
    std::cout << "Copy konstruktoriaus testas sekmingas!\n";
}

void testMoveConstructor() {
    Studentas temp;
    temp.setVardas("Move");
    temp.getPazymiai().push_back(7);
    
    Studentas moved(std::move(temp));
    assert(moved.getVardas() == "Move");
    assert(moved.getPazymiai()[0] == 7);
    std::cout << "Move konstruktoriaus testas sekmingas!\n";
}

void testCopyAssignment() {
    Studentas s1;
    s1.setPavarde("Kebabas");
    
    Studentas s2;
    s2 = s1;
    assert(s2.getPavarde() == "Kebabas");
    std::cout << "Copy assignment testas sekmingas!\n";
}
void testMoveAssignment() {
    Studentas s1;
    s1.setVardas("Jonas");
    s1.setPavarde("Moved");
    s1.getPazymiai().push_back(8);
    s1.getPazymiai().push_back(9);
    s1.setEgzaminoPazimys(7.5);
    s1.setGalutinisBalasVidurkis(8.5);
    s1.setGalutinisBalasMediana(8.0);

    Studentas s2;
    s2 = std::move(s1);

    assert(s2.getVardas() == "Jonas");
    assert(s2.getPavarde() == "Moved");
    assert((s2.getPazymiai() == std::vector<int>{8, 9}));
    assert(s2.getEgzaminoPazimys() == 7.5);
    assert(s2.getGalutinisBalasVidurkis() == 8.5);
    assert(s2.getGalutinisBalasMediana() == 8.0);

    std::cout << "Move assignment testas sekmingas!\n";
}
int main() {
    testDefaultConstructor();
    testSettersAndGetters();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    
    std::cout << "\nAll tests passed!\n";
    return 0;
}
