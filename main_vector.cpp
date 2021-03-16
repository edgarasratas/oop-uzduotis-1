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

label3: if (input == "Y" || input == "y") {
    cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
    cout << "1. studentai10000.txt\n";
    cout << "2. studentai100000.txt\n";
    cout << "3. studentai1000000.txt\n";
    cin >> inputInt;

    if (inputInt == 1) {
        nuskaitymas("studentai10000.txt", "studentai10000_rez.txt", student);
    }
    else if (inputInt == 2) {
        nuskaitymas("studentai100000.txt", "studentai100000_rez.txt", student);
    }
    else if (inputInt == 3) {
        nuskaitymas("studentai1000000.txt", "studentai1000000_rez.txt", student);
    }
    else {
        cout << "Klaida. Bandykite dar karta\n";
        cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
        cout << "1. studentai10000.txt\n";
        cout << "2. studentai100000.txt\n";
        cout << "3. studentai1000000.txt\n";
        cin >> inputInt;
        goto label3;
    }
}
    else if (input == "N" || input == "n") {
        skaiciavimas();
    }
    else {
        cout << "Klaida. Bandykite dar karta\n";
        cout << "Ar norite nuskaityti pazymius is failo (Y)?\nPaspaudzius (N) reikes pazymius ivesti\n";
        cin >> input;
        goto label3;
    }
}