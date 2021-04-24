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


# Spartos analizė #

Spartos analizėje buvo lyginami skirtingi konteinerių tipai ir skirtingo dydžio failai.

Spartos analizei buvo panaudotas kompiuteris su šiomis specifikacijomis:

* AMD Ryzen 5 4600H  3.00GHz
* 16GB RAM DDR4
* NVMe 1TB SSD


### Duomenų nuskaitymas ###

Container |   1000  |  10000  |  100000 | 1000000 | 10000000 |
----------|---------|---------|---------|---------|----------|
Vector    | 0.005s. | 0.048s. | 0.425s. | 4.513s. | 45.762s. |
Deque     | 0.006s. | 0.048s. | 0.499s. | 5.022s. | 51.287s. |
List      | 0.012s. | 0.064s. | 0.649s. | 5.304s. | 52.835s. |

### Duomenų grupavimas ###

#### 1 strategija ####

Bendro studentai konteinerio (`vector`, `list` ir `deque` tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: `"Winner"` ir `"Loser"`. 

Container |   1000  |  10000  |  100000 | 1000000 | 10000000 |
----------|---------|---------|---------|---------|----------|
Vector    |    0s.  | 0.003s. | 0.038s. | 0.436s. |  4.035s. |
Deque     |    0s.  | 0.003s. | 0.034s. |  0.37s. |  5.015s. |
List      |    0s.  | 0.004s. | 0.043s. | 0.522s. |  6.977s. |

#### 2 strategija ####

Bendro studentų konteinerio (`vector`, `list` ir `deque`) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: `"Loser"`. 

Container |   1000  |  10000  |  100000 | 1000000 | 10000000 |
----------|---------|---------|---------|---------|----------|
Vector    |    0s.  | 0.004s. | 0.032s. | 0.354s. |  3.557s. |
Deque     |    0s.  | 0.004s. | 0.041s. | 0.426s. |  4.376s. |
List      |    0s.  | 0.005s. |  0.05s. | 0.524s. |  5.351s. |

#### Optimizuotas vektorius (naudojant 2 strategiją) ####

Optimizuotas vektorius yra aprašytas kaip `3` pasirinkimas tarp pasirenkamų strategijų.

Container |   1000  |  10000  |  100000 | 1000000 | 10000000 |
----------|---------|---------|---------|---------|----------|
Vector    |    0s.  | 0.002s. | 0.026s. |  0.28s. |  3.027s. |

#### Struct ir Class palyginimas ####

Lentelėje pavaizduoti bendri programos veikimo laikai.

Container |   1000  |  10000  |  100000 |  1000000  |
----------|---------|---------|---------|-----------|
struct    | 0.021s. | 0.198s. | 2.388s. | 30.785s.  |
class     | 0.098s. | 1.451s. | 18.056s.| 331.039s. |
class -O1 | 0.075s. | 1.072s. | 13.544s.| 265.945s. |
class -O2 | 0.012s. | 0.113s. | 1.285s. | 17.605s.  |
class -O3 | 0.013s. | 0.117s. | 1.275s. | 17.482s.  |


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
  * Sukurta funkcija leidžianti sugeneruoti atsitiktinius studentų sarašų failus (1'000, 10'000, 100'000, 1'000'000, 10'000'000 įrašų).
  * Sukurtas studentų rūšiavimas į dvi grupes pagal pagal galutinį balą.
  * Sugrupuoti studentai yra atitinkamai išvedami į du skirtingus failus.

* [v0.5](https://github.com/aurimasruk/OOP-2nd-Task/releases/tag/v0.5) :
  * Sukurta konteinerių testavimo funkcija, kuri leidžia išmatuoti programos veikimo spartą priklausomai nuo naudojamo vieno iš trijų konteinerių.

* [v1.0](https://github.com/aurimasruk/OOP-2nd-Task/releases/tag/v1.0) :
  * Sukurta testavimo funkcija, leidžianti pasirinkti testavimo strategijos būdą.
  * Sukurta funkcija, leidžianti palyginti testavimo rezultatus tarp paprasto ir optimizuoto vektoriaus.

* [v1.1](https://github.com/aurimasruk/OOP-2nd-Task--part2-/releases/tag/v1.1) :
  * `Studentai` struktūra pakeista į klasę.
  * Atliktas spartos palyginimas tarp `struct` ir `class`.
  * Atlikta eksperimentinė analizė tarp skirtingų optimizavimo lygių, nurodomų flag'ais (`-O1`, `-O2`, `-O3`).
