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

*Failo sugeneravimas*
|   Konteineris       |       1000               |     10000             |         100000                  |         1000000           |        10000000           |
|---------------------|:------------------------:| :-------------------: | :-----------------------------: | :-----------------------: | :-----------------------: |
|      Vector         |       0.0069354          |     0.0639467         |         0.639467                |         6.45048           |        64.8593            |
|      Deque          |       0.0071586          |     0.0638999         |         0.653829                |         6.40456           |        64.467             |
|      List           |       0.0071375          |     0.0641405         |         0.680085                |         6.50146           |        64.6657            |

*Failo nuskaitymas*
|   Konteineris       |       1000               |     10000             |         100000                  |         1000000           |        10000000           |
|---------------------|:------------------------:| :-------------------: | :-----------------------------: | :-----------------------: | :-----------------------: |
|      Vector         |       0.0053973          |     0.0131165         |         0.104611                |         1.05806           |        10.3087            |
|      Deque          |       0.0084877          |     0.00131673        |         0.101035                |         1.05225           |        9.95386            |
|      List           |       0.0082369          |     0.0141655         |         0.113882                |         0.968885          |        9.88697            |

*Rūšiavimas ir išvedimas*
|   Konteineris       |       1000               |     10000             |         100000                  |         1000000           |        10000000           |
|---------------------|:------------------------:| :-------------------: | :-----------------------------: | :-----------------------: | :-----------------------: |
|      Vector         |       0.0096995          |     0.0894868         |         0.882452                |         8.73464           |        87.7903            |
|      Deque          |       0.0095864          |     0.0886832         |         0.893598                |         8.87006           |        88.7118            |
|      List           |       0.0095014          |     0.091438          |         0.942194                |         8.93144           |        88.7711            |

*Visas laikas*
|   Konteineris       |       1000               |     10000             |         100000                  |         1000000           |        10000000           |
|---------------------|:------------------------:| :-------------------: | :-----------------------------: | :-----------------------: | :-----------------------: |
|      Vector         |       0.0232172          |     0.169726          |         1.63146                 |         16.2717           |        163.192            |
|      Deque          |       0.0263459          |     0.168821          |         1.65352                 |         16.3515           |        163.363            |
|      List           |       0.025981           |     0.172687          |         1.74158                 |         16.4272           |        163.542            |
-----------------------------------------------------------------
