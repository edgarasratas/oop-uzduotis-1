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
                cout << "6. Generuoti visus failus\n";

                cin >> inputStudentSize;
                do {
                    if (inputStudentSize == 1) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinners("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", student);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 2) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinners("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", student);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 3) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinners("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", student);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 4) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinners("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", student);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 5) {
                        auto start = std::chrono::high_resolution_clock::now();

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinners("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", student);

                        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
                        cout << "Visas sugaistas laikas: " << diff.count() << "s";

                        exit(0);
                    }
                    else if (inputStudentSize == 6) {
                        randomFileGenerator("Generated text files\\", "studentai1000 (random).txt", oneK, student);
                        sortLosersAndWinners("Generated text files\\studentai1000 (random).txt", "Losers and winners\\1000losers.txt", "Losers and winners\\1000winners.txt", student);

                        randomFileGenerator("Generated text files\\", "studentai10000 (random).txt", tenK, student);
                        sortLosersAndWinners("Generated text files\\studentai10000 (random).txt", "Losers and winners\\10000losers.txt", "Losers and winners\\10000winners.txt", student);

                        randomFileGenerator("Generated text files\\", "studentai100000 (random).txt", hundredK, student);
                        sortLosersAndWinners("Generated text files\\studentai100000 (random).txt", "Losers and winners\\100000losers.txt", "Losers and winners\\100000winners.txt", student);

                        randomFileGenerator("Generated text files\\", "studentai1000000 (random).txt", oneMill, student);
                        sortLosersAndWinners("Generated text files\\studentai1000000 (random).txt", "Losers and winners\\1000000losers.txt", "Losers and winners\\1000000winners.txt", student);

                        randomFileGenerator("Generated text files\\", "studentai10000000 (random).txt", tenMill, student);
                        sortLosersAndWinners("Generated text files\\studentai10000000 (random).txt", "Losers and winners\\10000000losers.txt", "Losers and winners\\10000000winners.txt", student);

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

                cin >> inputInt;

                do {
                    if (inputInt == 1) {
                        nuskaitymas("Text files\\studentai10000.txt", "Text files\\studentai10000_rez.txt",
                            "Losers and winners\\(Example file) 10000losers.txt", "Losers and winners\\(Example file) 10000winners.txt", student);
                        break;
                    }
                    else if (inputInt == 2) {
                        nuskaitymas("Text files\\studentai100000.txt", "Text files\\studentai100000_rez.txt",
                            "Losers and winners\\(Example file) 100000losers.txt", "Losers and winners\\(Example file) 100000winners.txt", student);
                        break;
                    }
                    else if (inputInt == 3) {
                        nuskaitymas("Text files\\studentai1000000.txt", "Text files\\studentai1000000_rez.txt",
                            "Losers and winners\\(Example file) 1000000losers.txt", "Losers and winners\\(Example file) 1000000winners.txt", student);
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