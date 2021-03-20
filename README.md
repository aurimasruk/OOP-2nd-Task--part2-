# Pažymių skaičiuoklė #

Programa yra skirta apskaičiuoti pažymių vidurkį arba medianą.

# Veikimo principas #

Paleidus programą yra prašoma pasirinkti duomenų įvedimo būdą.

Pasirinkus įvesti duomenis rankiniu būdu, programa prašo įvesti:

* Studento vardą bei pavardę;
* Namų darbų kiekį;
* Namų darbų bei egzamino rezultatus.

> Taip pat programa suteikia galimybę sugeneruoti atsitiktinius namų darbų bei egzamino rezultatus.
> Galutiniai duomenys lentelėje yra automatiškai išrūšiuojami pagal studentų vardus.

# Programos veikimo pavyzdžiai #

### Programos veikimo greičio (spartos) analizė: ###

```
Ar norite atlikti programos veikimo (greicio) analize? (Y/N): y

Ar norite apskaiciuoti mediana(1), vidurki(2)? 2

Failas kursiokai1000.txt
Failo kurimas uztruko: 11ms.
Duomenu nuskaitymas is failo uztruko: 6ms.    
Studentu rusiavimas i dvi grupes uztruko: 1ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 15ms.


Failas kursiokai10000.txt
Failo kurimas uztruko: 46ms.
Duomenu nuskaitymas is failo uztruko: 44ms.
Studentu rusiavimas i dvi grupes uztruko: 4ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 60ms.


Failas kursiokai100000.txt
Failo kurimas uztruko: 394ms.
Duomenu nuskaitymas is failo uztruko: 438ms.
Studentu rusiavimas i dvi grupes uztruko: 48ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 461ms.


Failas kursiokai1000000.txt
Failo kurimas uztruko: 4245ms.
Duomenu nuskaitymas is failo uztruko: 4717ms.
Studentu rusiavimas i dvi grupes uztruko: 545ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 4443ms.


Failas kursiokai10000000.txt
Failo kurimas uztruko: 41256ms.
Duomenu nuskaitymas is failo uztruko: 47466ms.
Studentu rusiavimas i dvi grupes uztruko: 4961ms.
Surusiuotu studentu isvedimas i du naujus failus uztruko: 44019ms.
```

### Programos veikimas neaptikus tekstinio failo ir duomenis įvedus rankiniu būdu: ###

```
Failas nerastas. Duomenys privalo buti ivesti rankiniu budu. 

Iveskite studento varda: Matas

Iveskite studento pavarde: Matulionis

Ar zinote atliktu namu darbu kieki? (Y/N): n

Sugeneruotas atliktu namu darbu kiekis: 18

Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): y

Sugeneruoti studento pazymiai: 6 10 4 4 9 4 4 6 8 5 8 4 1 2 1 9 6 9
Egzamino rezultatas: 1
Ar norite prideti dar viena studenta? (Y/N) Y
Iveskite studento varda: Aidas

Iveskite studento pavarde: Aidauskas

Ar zinote atliktu namu darbu kieki? (Y/N): y

Iveskite atliktu namu darbu kieki: 4

Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): n

Iveskite atliktu namu darbu pazymius:
4 8 6 5

Iveskite egzamino pazymi: 8

Ar norite prideti dar viena studenta? (Y/N) n

Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? 3





Vardas         Pavarde        Galutinis (vid.)  Galutinis (med.)
----------------------------------------------------------------
Aidas          Aidauskas      7.10              6.80
Matas          Matulionis     2.82              2.60
```

### Programos veikimas įvedant duomenis iš failo: ###
```
File 'kursiokai.txt' detected.

Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): y

Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? b
Wrong input. Try again.
3





Vardas         Pavarde        Galutinis (vid.)  Galutinis (med.)
----------------------------------------------------------------
Agne           Agnaityte      9.52              9.60
Audrius        Audraitis      4.92              4.60
Birute         Birutyte       7.76              7.60
Jonas          Jonaitis       6.60              6.60
Juozas         Juozaitis      6.21              6.00
Lukas          Lukaitis       4.23              4.20
Monika         Monikaityte    4.72              4.80
Pranas         Pranaitis      7.33              7.20
Toma           Tomaityte      7.27              7.00
```

# Programos įdiegimas ir naudojimasis #

* Atsisiųskite vieną programos versijų iš [Releases](https://github.com/aurimasruk/OOP-2nd-Task/releases) aplanko ir ją išarchyvuokite.
* Komandinėje eilutėje įveskite `g++ -o main main.cpp functions.cpp` ir `./main`.
* Pradėjus veikti programai, įveskite reikalaujamus duomenis.
 
# Releases #

* [v0.1](https://github.com/aurimasruk/OOP-2nd-Task/releases/tag/v0.1) : pirminė programos versija.

* [v0.2](https://github.com/aurimasruk/OOP-2nd-Task/releases/tag/v0.2) :
  * Pridėta galimybė nuskaityti duomenis iš failo.
  * Pridėta galimybė spausdinti vidurkį ir medianą kartu.
  * Studentai yra automatiškai išrūšiuojami pagal jų vardus.

* [v0.3](https://github.com/aurimasruk/OOP-2nd-Task/releases/tag/v0.3) :
  * Sukurtas `functions.cpp` failas, kuriame yra sudėtos visos programoje naudojamos funkcijos.
  * Sukurtas `functions.hpp` header failas, kuriame yra saugoma studentų struct.

* [v0.3.1](https://github.com/aurimasruk/OOP-2nd-Task/releases/tag/v0.3.1) :
  * Sutvarkytas išimčių valdymas ([Exception Handling](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm)).

* [v0.4](https://github.com/aurimasruk/OOP-2nd-Task/releases/tag/v0.4) :
  * Sukurta funkcija leidžianti atlikti programos veikimo greičio (spartos) analizę.
  * Sukurta funkcija leidžianti sugeneruoti atsitiktinius studentų sarašų failus (1000, 10000, 100000, 1000000, 10000000 įrašų).
  * Sukurtas studentų rūšiavimas į dvi grupes pagal pagal galutinį balą.
  * Sugrupuoti studentai yra atitinkamai išvedami į du skirtingus failus.
