#include "Header.h"
#include "Funkcijos.h"

const int oneK = 1000;
const int tenK = 10000;
const int hundredK = 100000;
const int oneMill = 1000000;
const int tenMill = 10000000;

int main()
{
    string input;
    string inputGenerate;
    string eil;
    string name, surname;
    vector<Student> student;
    int inputInt;
    int inputStudentSize;

    cout << "Ar norite nuskaityti pazymius is failo (Y)?\nPaspaudzius (N) reikes pazymius ivesti\n";
    cin >> input;

    do {
    if (input == "Y" || input == "y") {
        cout << "Ar norite atsitiktinai sugeneruoti faila (Y)?\nPaspaudzius (N) programa skaitys is pasirinkto jau esamo failo\n";
        cin >> inputGenerate;

        do {
            if (inputGenerate == "Y" || inputGenerate == "y") {
                cout << "Pasirinkite studentu kieki generavimui:\n";
                cout << "1. 1000 (1 tukst.)\n";
                cout << "2. 10000 (10 tukst.)\n";
                cout << "3. 100000 (100 tukst.)\n";
                cout << "4. 1000000 (1 milijonas)\n";
                cout << "5. 10000000 (10 milijonu)\n";
                cout << "6. Generuoti visus failus (pasirinkus si varianta studentai NEBUS surusiuoti)\n";
                cin >> inputStudentSize;

                do {
                    if (inputStudentSize == 1) {
                        randomFileGenerator("studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinners("studentai1000 (random).txt", "losers.txt", "winners.txt", student);
                        exit(0);
                    }
                    else if (inputStudentSize == 2) {
                        randomFileGenerator("studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinners("studentai10000 (random).txt", "losers.txt", "winners.txt", student);
                        exit(0);
                    }
                    else if (inputStudentSize == 3) {
                        randomFileGenerator("studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinners("studentai100000 (random).txt", "losers.txt", "winners.txt", student);
                        exit(0);
                    }
                    else if (inputStudentSize == 4) {
                        randomFileGenerator("studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinners("studentai1000000 (random).txt", "losers.txt", "winners.txt", student);
                        exit(0);
                    }
                    else if (inputStudentSize == 5) {
                        randomFileGenerator("studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinners("studentai10000000 (random).txt", "losers.txt", "winners.txt", student);
                        exit(0);
                    }
                    else if (inputStudentSize == 6) {
                        randomFileGenerator("studentai1000 (random).txt", oneK, student);
                        randomFileGenerator("studentai10000 (random).txt", tenK, student);
                        randomFileGenerator("studentai100000 (random).txt", hundredK, student);
                        randomFileGenerator("studentai1000000 (random).txt", oneMill, student);
                        randomFileGenerator("studentai10000000 (random).txt", tenMill, student);
                        exit(0);
                    }
                    else {
                        cout << "Klaida. Bandykite dar karta\n";
                        cout << "Pasirinkite studentu kieki generavimui:\n";
                        cout << "1. 1000 (1 tukst.)\n";
                        cout << "2. 10000 (10 tukst.)\n";
                        cout << "3. 100000 (100 tukst.)\n";
                        cout << "4. 1000000 (1 milijonas)\n";
                        cout << "5. 10000000 (10 milijonu)\n";
                        cin >> inputStudentSize;
                    }
                } while (inputStudentSize != 1 || inputStudentSize != 2 || inputStudentSize != 3 || inputStudentSize != 4 || inputStudentSize != 5);
            }
            else if (inputGenerate == "N" || inputGenerate == "n") {
                cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
                cout << "1. studentai10000.txt\n";
                cout << "2. studentai100000.txt\n";
                cout << "3. studentai1000000.txt\n";
                cin >> inputInt;

                do {
                    if (inputInt == 1) {
                        nuskaitymas("studentai10000.txt", "studentai10000_rez.txt", "losers.txt", "winners.txt", student);
                        break;
                    }
                    else if (inputInt == 2) {
                        nuskaitymas("studentai100000.txt", "studentai100000_rez.txt", "losers.txt", "winners.txt", student);
                        break;
                    }
                    else if (inputInt == 3) {
                        nuskaitymas("studentai1000000.txt", "studentai1000000_rez.txt", "losers.txt", "winners.txt", student);
                        break;
                    }
                    else {
                        cout << "Klaida. Bandykite dar karta\n";
                        cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
                        cout << "1. studentai10000.txt\n";
                        cout << "2. studentai100000.txt\n";
                        cout << "3. studentai1000000.txt\n";
                        cin >> inputInt;
                    }
                } while (inputInt != 1 || inputInt != 2 || inputInt != 3);

                break;
            }
            else {
                cout << "Klaida. Bandykite dar karta\n";
                cout << "Ar norite sukurti nauja faila (Y)?\nPaspaudzius (N) programa skaitys is jau esamo failo\n";
                cin >> inputGenerate;
            }
        } while (inputGenerate != "Y" || inputGenerate != "y" || inputGenerate != "N" || inputGenerate != "n");
            break;
    }
    else if (input == "N" || input == "n") {
        skaiciavimas();
        break;
    }
    else {
        cout << "Klaida. Bandykite dar karta\n";
        cout << "Ar norite nuskaityti pazymius is failo (Y)?\nPaspaudzius (N) reikes pazymius ivesti\n";
        cin >> input;
    }
    } while (input != "Y" || input != "y" || input != "N" || input != "n");
}