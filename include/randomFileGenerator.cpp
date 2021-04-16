#include "Funkcijos.h"

const int gradeNr = 10;

void randomFileGenerator(string dir, string fileWrite, int studentSize, vector<Student>& student) {
    Student temp;
    int temp2;
    stringstream buffer;
    string eil;
    string name = "Vardas";
    string surname;
    int grade;
    int examGrade;
    
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    dir = "Generated text files\\";

    createDir("Generated text files");

    cout << "Generuojama...\n";
    ofstream fout1(dir + fileWrite);

    srand(time(NULL));

    fout1 << "Vardas" << std::setw(20) << std::right;
    fout1 << "Pavarde" << std::setw(20) << std::right;

    for (int i = 0; i < gradeNr + 1; i++) {
        if (i < gradeNr) {
            fout1 << "ND" << i + 1 << std::setw(9) << std::internal;
        }
        else if (i == gradeNr)
        {
            fout1 << std::setw(9) << "Egz.";
        }
    }
    fout1 << endl;

    for (int i = 0; i < studentSize; i++) {
        name = ("Vardas" + std::to_string(i + 1));
        surname = ("Pavarde" + std::to_string(i + 1));

        fout1 << name << std::setw(20) << surname << std::setw(20);

        for (int j = 0; j < gradeNr; j++) {

            fout1 << rand() % 10 + 1 << std::setw(12) << std::right;
        }
        fout1 << std::setw(12);
        if (i == studentSize - 1) {
            fout1 << rand() % 10 + 1;
        }
        else {
            fout1 << rand() % 10 + 1 << endl;
        }
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Faila sugeneravo per " << diff.count() << "s\n";
    cout << "Sugeneruotas failas '" << fileWrite << "' 'Generated text files' folderyje\n";
}