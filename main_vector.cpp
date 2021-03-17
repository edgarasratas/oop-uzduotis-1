#include "Header.h"
#include "Funkcijos.h"

int main()
{
    string input;
    string eil;
    string name, surname;
    vector<Student> student;
    int inputInt;

    cout << "Ar norite nuskaityti pazymius is failo (Y)?\nPaspaudzius (N) reikes pazymius ivesti\n";
    cin >> input;

    do {
    if (input == "Y" || input == "y") {
        cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
        cout << "1. studentai10000.txt\n";
        cout << "2. studentai100000.txt\n";
        cout << "3. studentai1000000.txt\n";
        cin >> inputInt;

        do {
            if (inputInt == 1) {
                nuskaitymas("studentai10000.txt", "studentai10000_rez.txt", student);
                break;
            }
            else if (inputInt == 2) {
                nuskaitymas("studentai100000.txt", "studentai100000_rez.txt", student);
                break;
            }
            else if (inputInt == 3) {
                nuskaitymas("studentai1000000.txt", "studentai1000000_rez.txt", student);
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