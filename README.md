# Užduotis "Pažymių skaičiuoklė"
[v0.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.1)
-----------------------------------------------------------------
Šioje programoje galima įrašyti studentų vardus, pavardes bei pažymius (egzamino bei namų darbų).
Ji automatiškai suskaičiuoja vidurkį ar medianą, priklausomai nuo vartotojo noro.
Taip pat, jeigu nėra žinomi studento pažymiai, galima pasirinkti, kad programa juos automatiškai sugeneruotų.
-----------------------------------------------------------------
![image](https://user-images.githubusercontent.com/73912309/108605204-64abee80-73bb-11eb-90ff-9720a407bc53.png)
-----------------------------------------------------------------
[v0.1.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.1)
-----------------------------------------------------------------
Sutvarkytas vektorių failas.
-----------------------------------------------------------------
[v0.2](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.2)
-----------------------------------------------------------------
Pridėta galimybė skaityti iš failų bei rezultatus išvesti rezultatų faile.
-----------------------------------------------------------------
![image](https://user-images.githubusercontent.com/73912309/110829317-a6380700-82a0-11eb-854d-c8891dc0ad22.png)
-----------------------------------------------------------------
![image](https://user-images.githubusercontent.com/73912309/110829401-bf40b800-82a0-11eb-88e4-b5ee4a18c51b.png)
-----------------------------------------------------------------
[v0.3](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.3)
-----------------------------------------------------------------
Programa papildyta dvejais "Try/Catch" papildymais tam, kad galima būtų patikrinti ar failas egzistuoja bei ar visi suvesti pažymiai yra teisingi.
-----------------------------------------------------------------
[v0.3.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.3)
-----------------------------------------------------------------
1. Studentai yra surikiuojami pagal vardus rezultatų faile
2. Patobulintas kodas, ištrintos nereikalingos eilutės
3. Programa suoptimizuota
4. Pataisytas rezultatų failuose lygiavimas
-----------------------------------------------------------------
[v0.4](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.4)
-----------------------------------------------------------------
1. Programa gali sugeneruoti papildomus .txt failus priklausomai nuo vartotojo pasirinkimo
2. Studentai yra surūšiuojami į dvi grupes: tie, kurie išlaikė s bei tie, kurie neišlaikė
3. Programa išveda failų sukūrimo bei studentų rūšiavimo laikus
![image](https://user-images.githubusercontent.com/73912309/112353997-f2d60600-8cd4-11eb-8010-ee423ec766d5.png)
-----------------------------------------------------------------
|   Studentų kiekis |   Sugeneravimo trūkmė    |   Nuskaitymo trukmė   |   Studentų surūšiavimo trūkmė   |  Visas sugaištas laikas   |
|--------------|:-------------:      | :-------------------: | :-----------------------------: | :-----------------------: |
|      1000         |       0.013385s          |     0.0010931s        |         0.0115191s              |         0.0259972         |
|      10000        |     0.127771s            |     0.0106337s        |         0.0880599s              |         0.2264646         |
|      100000       |        1.28625s          |     0.0976294s        |         0.882631s               |         2.2665104         |
|      1000000      |       12.7196s           |     0.987103s         |         8.64162s                |         22.348323         |
|      10000000     |         125.735s         |     9.76024s          |         86.515s                 |         222.01024         |
-----------------------------------------------------------------
[v0.4.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.4)
-----------------------------------------------------------------
Patobulinimai bei klaidų taisymas. Taip pat .txt failams saugoti yra sukuriami folderiai.
-----------------------------------------------------------------
[v0.5](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.5)
-----------------------------------------------------------------
Įdėta galimybė pasirinkti norimą konteinerio tipą:
1. Vector
2. Deque
3. List

Programos veikimo laikai priklausomai nuo konteinerio pasirinkimo bei studentų kiekio (sekundėmis):

*Failo nuskaitymas*
|   Konteineris       |         10000                  |         100000             |        1000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|
|      Vector         |         0.0097385              |         0.137411            |       0.685214          |
|      Deque          |         0.0097405              |         0.140276            |       0.697253          |
|      List           |         0.009782               |         0.1389939           |       0.693967          |

*Rezultatu failo generavimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|
|      Vector         |         0.0679942              |         1.00796            |        5.9101            |
|      Deque          |         0.0861038              |         1.04751            |        6.16688           |
|      List           |         0.0692834              |         0.999789           |        5.877352          |

*Rūšiavimas ir išvedimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|
|      Vector         |         0.0105147              |         0.104326           |        1.02452           |
|      Deque          |         0.0109866              |         0.114482           |        1.09572           |
|      List           |         0.0106121              |         0.107204           |        1.04673           |

*Visas laikas*
|   Konteineris       |         10000                  |         100000             |        1000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|
|      Vector         |         0.089016               |         1.25055            |        7.62065           |
|      Deque          |         0.10761                |         1.30315            |        7.96067           |
|      List           |         0.090639               |         1.24674            |        7.6152            |
-----------------------------------------------------------------
Sistemos parametrai naudojami testavimui:
* CPU: AMD Ryzen 5 3600 6-Core
* RAM: 16 GB DDR4 3200 MHz
* SSD: Samsung 970 Evo Plus M.2 NVMe (r: 3500 MB/s, w: 3300 MB/s) 
