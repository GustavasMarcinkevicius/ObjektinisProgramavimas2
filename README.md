# ObjektinisProgramavimas
v3.0 README:

Instaliacijos instrukcija:    
Norėdami naudotis programa, ją iš pradžių reikia instaliuoti (MySetup.exe failas). Instaliacija yra įprasta, labai siūloma palikti varnelę "create dekstop shrotcut" pažymėtą, tuomet programa naudotis bus žymiai lengviau. Norint programą išinstaliuoti, reikia nueiti į "C:\Program Files\VU\Gustavas-Marcinkevicius" (jeigu keitėte instaliacijos direktoriją, tai tenais), ir paspausti uninstall.exe failą.

(šią varnelę paliktį pažymėtą)     
![image](https://github.com/user-attachments/assets/e03f353c-27a3-43b9-aa57-a27ab3ff6e21)

(norint išinstaliuoti programą:)     
![image](https://github.com/user-attachments/assets/5e3d66d3-1263-4f81-94cd-0b083d798cca)


Naudojimosi instrukcija:

Iš pradžių suinstaliavus failą, jį galime paleisti paspaudę ant ,,Studentai" darbalaukyje. Norint skaityti iš failų, programa jau turi kelis pavyzdinius failus. Norint įkelti savo failus, lengviausia tai yra padaryti paspaudus dešinį klavišą ant Studentai piktogramos, tada ,,Open file location". Ten galima įkelti savo txt failus.

Paprasto vektoriaus (v1) ir mano sukurto vektoriaus (v2) testavimo laikai, naudojant push_back(i) funkcija:

| Vektoriaus dydis: | 10 000 | 100 000 | 1000 000 | 10 000 000 | 100 000 000 |
|:-----------------:|--------|---------|----------|------------|-------------|
| v1 laikas(s):     | 0.0002 | 0.0007  | 0.007    | 0.081      | 0.65        |
| v2 laikas(s):     | 0.0002 | 0.0005  | 0.004    | 0.077      | 0.56        |

kelių sukurto vektoriaus funkcijų naudojimo pavyzdžiai:  
1. push_back(const T& value)  
   
🔹 Paskirtis: Prideda naują elementą į vektoriaus galą.  

🔹 Kaip veikia:  

Jei nebėra vietos (sz >= cap), iškviečia reallocate, kuri padidina talpą.  
Tada nauja reikšmė įrašoma į data[sz], ir sz padidinamas.   
v.push_back(10); // Prideda 10 į galą  

2. pop_back()  
   
🔹 Paskirtis: Pašalina paskutinį elementą.  

🔹 Kaip veikia:    
Tiesiog sumažina sz vienetu (jei sz > 0), bet neatlaisvina atminties.   
v.pop_back(); // Pašalina paskutinį elementą  

3. resize(size_t new_size, const T& default_value = T())  
   
🔹 Paskirtis: Pakeičia vektoriaus dydį  .

🔹 Kaip veikia:  
Jei reikia padidinti dydį, paskirsto daugiau vietos (reserve) ir naujus elementus užpildo default_value.  
Jei reikia sumažinti — tiesiog sumažina sz.  
v.resize(100, 0); // Dabar vektorius turi 100 elementų, jei elementų trūko – prideda nulius  

4. clear()   
🔹 Paskirtis: Išvalo visus elementus.

🔹 Kaip veikia:
Nustato sz = 0, bet palieka cap tą patį (atmintis neišvaloma).
v.clear(); // v.size() taps 0

5. operator[](size_t index)  
🔹 Paskirtis: Leidžia pasiekti elementą pagal indeksą kaip masyve.

🔹 Kaip veikia:  
Grąžina nuorodą į data[index], leidžia skaityti ir rašyti.  
v[0] = 42; // Pirmas elementas bus 42  
________________________________________________________________________________________________________________

v1.5 README: 

Klases Studentas testas:

![image](https://github.com/user-attachments/assets/0e788b2b-31b4-4817-87a3-9a00958c9d47)

Abstrakcios klases zmogus testas:

![image](https://github.com/user-attachments/assets/7fbefaa8-909b-4665-b4ba-064f0e849504)


v1.2 README:

Studentas klasę galima rasti "Struktura.h" faile

Įvestis/Išvestis iš Studentas klasės: readFromConsole metodas (Įvesties metodas iš konsolės):

Pirmiausia, naudojamas std::cin norint nuskaityti studento vardą ir pavardę. Po to, vartotojas prašomas įvesti studento pažymius, kol nebus įvestas -1 (tai bus ženklas, kad įvedimas baigiasi). Galiausiai, prašoma įvesti egzamino pažymį, kuris bus paskutinis įvestas duomenų taškas.

readFromFile metodas (Įvesties metodas iš failo):

Šis metodas skaito informaciją iš failo. Failo struktūra turi būti tokia, kad kiekvienas studento įrašas būtų eilutėje su vardu, pavarde ir pažymiais.

Veikimas:

Pirmiausia, metodas nuskaitys studento vardą ir pavardę. Tada jis nuskaitys visus pažymius ir įrašys juos į pazymiai vektorių. Paskutinis nuskaitytas pažymys bus laikomas egzamino pažymiu, ir jis bus išimtas iš pažymių sąrašo (naudojant pop_back).

Išvedimo operatorius <<: Šis operatorius (operator<<) naudojamas objektų Studentas duomenų išvedimui tiek į konsolę, tiek į failą. Šis operatorius priima std::ostream tipo srautą (tai gali būti tiek std::cout (konsolė), tiek std::ofstream (failas)) ir formatuoja išvedimą pagal nurodytus reikalavimus.

1.1 README:


Class vs Struct

![image](https://github.com/user-attachments/assets/aca65c9c-95d2-4e38-9506-5cfc84383d36)

Kompiliavimo flag'ų palyginimas (greitis)

![image](https://github.com/user-attachments/assets/75d7c63d-c7cc-4cc6-bdb9-ed1008372c70)

Kompiliavimo flagų palyginias (dydis)

![image](https://github.com/user-attachments/assets/4a77aaed-b073-4042-81ff-855cc24cc1b9)










1.0 README:

Pagrindiniai programos naudojimo aspektai:

Ši programa leidžia efektyviai atlikti tam tikrus veiksmus su studentų sąrašu (juos išrūšiuoti, išsskirstyti į skirtingus failus, jiems generuoti vardus, pažymius ir pnš). Taip pat šia programa galima stebėti skirtingų konteinerių, tokių kaip vector, deque ar list veikimo efektyvumą, taip pat ir skirtingų algoritmų pritaikymą. Programa tu MakeLists.txt failą, kuris leidžia lengvai sugeneruoti naudojamą failą. 

Programos veikimo laikas, lyginant vector, list ir deque:

Testavimo sistemos parametrai:
CPU - i5-1335u (10 cores, 12 threads, 12M Cache, up to 4.60 GHz)

RAM - DDR4 8GB, 2667 MHz

DISK - NVMe SSD, read speed up to 3500 MB/s, write speed up to 1625 MB/s

![image](https://github.com/user-attachments/assets/d4af7e2b-11e0-4d19-aa95-e91ce4db606f)


detalūs lyginimo duomenys:

Su vektoriais:

![image](https://github.com/user-attachments/assets/a90a4545-2a6c-49e7-9844-03ae8bde7642)
![image](https://github.com/user-attachments/assets/2358a037-0d81-4684-9930-2b4fd6e5d243)
![image](https://github.com/user-attachments/assets/32b248e8-098d-4cf2-a7ad-8688943f128f)
![image](https://github.com/user-attachments/assets/3ce041e5-6ef8-4396-8a55-f823c6249ed7)
![image](https://github.com/user-attachments/assets/70487f60-8f98-47f1-a9bc-3507d6328785)

Su Listais: 

![image](https://github.com/user-attachments/assets/e346fb24-076a-45cd-ba4d-be1efd2114ce)
![image](https://github.com/user-attachments/assets/845ba315-f94d-4a18-899d-d14304b19460)
![image](https://github.com/user-attachments/assets/f8a8c2fa-8f6b-4dc7-93a0-632584fdfeaa)
![image](https://github.com/user-attachments/assets/549d5a41-cbcc-48bd-a0e2-23849617226a)
![image](https://github.com/user-attachments/assets/4c993f6a-9174-41e0-8d13-9eee5f67f539)

Su Deque:

![image](https://github.com/user-attachments/assets/2627ab80-94db-41ba-a33a-0ad71bbb02b8)
![image](https://github.com/user-attachments/assets/ce591698-efba-4743-8d72-0e91fe6c9255)
![image](https://github.com/user-attachments/assets/220e4ec8-3899-464a-80ff-279ccbcf4332)
![image](https://github.com/user-attachments/assets/53eba47e-107b-48df-9513-f5259d69d217)
![image](https://github.com/user-attachments/assets/bb18bd31-1ac9-47f8-8927-4edda6f97007)


STRATEGIJŲ PALYGINIMAS: 

Pirma strategija - Vektoriaus išskaidymas į du atskirus vektorius

Antra strategija - Dalis vektoriaus perkeliama į kitą, tada ištrinama iš pirmos (Dažni trynimai buvo itin skausmingi programos efektyvimui, todėl ji buvo lėčiausia)

Trečia strategija - Optimizuota pirma strategija

![image](https://github.com/user-attachments/assets/e6bb2515-f22f-4ece-9bcb-e544eba606be)









