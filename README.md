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

Container |   1000  |  10000  |  100000 | 1000000 | 10000000 |
----------|---------|---------|---------|---------|----------|
Vector    |    0s.  | 0.004s. | 0.047s. | 0.507s. |  5.449s. |
Deque     | 0.001s. | 0.002s. | 0.036s. | 0.445s. |  4.765s. |
List      |    0s.  | 0.004s. | 0.046s. |  0.5s.  |  4.823s. |


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
