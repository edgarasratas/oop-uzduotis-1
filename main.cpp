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
    deque<Student> studentD;
    list<Student> studentL;
    int inputInt;
    int inputStudentSize;
    int inputContainer;
    string resultType;
    int index = 0;
    int strategy;

    do {
        index++;
        if (index != 1)
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";

        cout << "Pasirinkite konteinerio tipa: \n";
        cout << "1. Vector\n";
        cout << "2. Deque\n";
        cout << "3. List\n";
        cin >> inputContainer;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }

        if (inputContainer == 1 || inputContainer == 2 || inputContainer == 3) {
            index = 0;
            break;
        }
    } while (inputContainer != 1 || inputContainer != 2 || inputContainer != 3);

    if (inputContainer == 1)
        cout << "Naudojamas 'vector' tipo konteineris...\n";
    else if (inputContainer == 2)
        cout << "Naudojamas 'deque' tipo konteineris...\n";
    else if (inputContainer == 3)
        cout << "Naudojamas 'list' tipo konteineris...\n";

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
                cout << "6. Generuoti visus failus\n";
                cin >> inputStudentSize;

                do {
                    index++;
                    if (index != 1)
                        cout << "Neteisinga ivestis. Bandykite dar karta.\n";

                    cout << "Kokia strategija noretumet panaudoti? (1/2)\n";
                    cin >> strategy;

                    if (strategy == 1 || strategy == 2)
                        break;
                } while (strategy != 1 || strategy != 2);

                do {
                    if (inputStudentSize == 1 && inputContainer == 1) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", student, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 2 && inputContainer == 1) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", student, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 3 && inputContainer == 1) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", student, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 4 && inputContainer == 1) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", student, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 5 && inputContainer == 1) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", student, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 6 && inputContainer == 1) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", student, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", student, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();

                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", student, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", student, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinnersVector("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", student, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        exit(0);
                    }
                    else if (inputStudentSize == 1 && inputContainer == 2) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", studentD, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 2 && inputContainer == 2) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", studentD, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 3 && inputContainer == 2) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", studentD, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 4 && inputContainer == 2) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", studentD, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 5 && inputContainer == 2) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", studentD, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 6 && inputContainer == 2) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", studentD, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", studentD, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();

                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", studentD, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", studentD, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinnersDeque("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", studentD, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        exit(0);
                    }
                    else if (inputStudentSize == 1 && inputContainer == 3) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinnersList("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", studentL, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 2 && inputContainer == 3) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinnersList("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", studentL, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 3 && inputContainer == 3) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinnersList("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", studentL, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 4 && inputContainer == 3) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinnersList("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", studentL, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 5 && inputContainer == 3) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinnersList("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", studentL, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 6 && inputContainer == 3) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinnersList("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", studentL, strategy);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinnersList("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", studentL, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();

                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinnersList("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", studentL, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinnersList("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", studentL, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinnersList("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", studentL, strategy);

                        diff = std::chrono::high_resolution_clock::now() - start;
                        start = std::chrono::high_resolution_clock::now();
                        cout << "Visas sugaistas laikas: " << diff.count() << "s\n\n";

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
                        cout << "6. Generuoti visus failus\n";

                        cin >> inputStudentSize;
                    }
                } while (inputStudentSize != 1 || inputStudentSize != 2 || inputStudentSize != 3 || inputStudentSize != 4 || inputStudentSize != 5);
            }
            else if (inputGenerate == "N" || inputGenerate == "n") {
                cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
                cout << "1. studentai10000.txt\n";
                cout << "2. studentai100000.txt\n";
                cout << "3. studentai1000000.txt\n";
                cout << "4. studentai10000000.txt\n";

                cin >> inputInt;

                do {
                    if (inputInt == 1 && inputContainer == 1) {
                        nuskaitymasVector("Text files\\studentai10000.txt", "Text files\\studentai10000_rez.txt",
                            "Losers and winners\\(Example file) 10000losers.txt", "Losers and winners\\(Example file) 10000winners.txt", student);
                        break;
                    }
                    else if (inputInt == 1 && inputContainer == 2) {
                        nuskaitymasDeque("Text files\\studentai10000.txt", "Text files\\studentai10000_rez.txt",
                            "Losers and winners\\(Example file) 10000losers.txt", "Losers and winners\\(Example file) 10000winners.txt", studentD);
                        break;
                    }
                    else if (inputInt == 1 && inputContainer == 3) {
                        nuskaitymasList("Text files\\studentai10000.txt", "Text files\\studentai10000_rez.txt",
                            "Losers and winners\\(Example file) 10000losers.txt", "Losers and winners\\(Example file) 10000winners.txt", studentL);
                        break;
                    }
                    else if (inputInt == 2 && inputContainer == 1) {
                        nuskaitymasVector("Text files\\studentai100000.txt", "Text files\\studentai100000_rez.txt",
                            "Losers and winners\\(Example file) 100000losers.txt", "Losers and winners\\(Example file) 100000winners.txt", student);
                        break;
                    }
                    else if (inputInt == 2 && inputContainer == 2) {
                        nuskaitymasDeque("Text files\\studentai100000.txt", "Text files\\studentai100000_rez.txt",
                            "Losers and winners\\(Example file) 100000losers.txt", "Losers and winners\\(Example file) 100000winners.txt", studentD);
                        break;
                    }
                    else if (inputInt == 2 && inputContainer == 3) {
                        nuskaitymasList("Text files\\studentai100000.txt", "Text files\\studentai100000_rez.txt",
                            "Losers and winners\\(Example file) 100000losers.txt", "Losers and winners\\(Example file) 100000winners.txt", studentL);
                        break;
                    }
                    else if (inputInt == 3 && inputContainer == 1) {

                        nuskaitymasVector("Text files\\studentai1000000.txt", "Text files\\studentai1000000_rez.txt",
                            "Losers and winners\\(Example file) 1000000losers.txt", "Losers and winners\\(Example file) 1000000winners.txt", student);
                        break;
                    }
                    else if (inputInt == 3 && inputContainer == 2) {
                        nuskaitymasDeque("Text files\\studentai1000000.txt", "Text files\\studentai1000000_rez.txt",
                            "Losers and winners\\(Example file) 1000000losers.txt", "Losers and winners\\(Example file) 1000000winners.txt", studentD);
                        break;
                    }
                    else if (inputInt == 3 && inputContainer == 3) {
                        nuskaitymasList("Text files\\studentai1000000.txt", "Text files\\studentai1000000_rez.txt",
                            "Losers and winners\\(Example file) 1000000losers.txt", "Losers and winners\\(Example file) 1000000winners.txt", studentL);
                        break;
                    }
                    else if (inputInt == 4 && inputContainer == 1) {

                        nuskaitymasVector("Text files\\studentai10000000.txt", "Text files\\studentai10000000_rez.txt",
                            "Losers and winners\\(Example file) 10000000losers.txt", "Losers and winners\\(Example file) 10000000winners.txt", student);
                        break;
                    }
                    else if (inputInt == 4 && inputContainer == 2) {
                        nuskaitymasDeque("Text files\\studentai10000000.txt", "Text files\\studentai10000000_rez.txt",
                            "Losers and winners\\(Example file) 10000000losers.txt", "Losers and winners\\(Example file) 10000000winners.txt", studentD);
                        break;
                    }
                    else if (inputInt == 4 && inputContainer == 3) {
                        nuskaitymasList("Text files\\studentai10000000.txt", "Text files\\studentai10000000_rez.txt",
                            "Losers and winners\\(Example file) 10000000losers.txt", "Losers and winners\\(Example file) 10000000winners.txt", studentL);
                        break;
                    }
                    else {
                        cout << "Klaida. Bandykite dar karta\n";
                        cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
                        cout << "1. studentai10000.txt\n";
                        cout << "2. studentai100000.txt\n";
                        cout << "3. studentai1000000.txt\n";
                        cout << "4. studentai10000000.txt\n";

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