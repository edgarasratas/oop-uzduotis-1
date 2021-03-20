#include "Funkcijos.h"

const int gradeNr = 10;

void randomFileGenerator(string fileWrite, int studentSize, vector<Student>& student) {
    vector<int> randomGrade;
    Student temp;
    int temp2;
    stringstream buffer;
    string eil;
    string name = "Vardas";
    string surname;
    int grade;
    int examGrade;
    
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    cout << "Generuojama...\n";
    ofstream fout1(fileWrite);

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

        buffer << name;
        buffer >> temp.name;

        buffer.clear();

        buffer << surname;
        buffer >> temp.surname;

        buffer.clear();
        for (int j = 0; j < gradeNr; j++) {
            temp.grade.reserve(gradeNr);
            grade = rand() % 10 + 1;
            buffer << grade;
            buffer >> temp2;
            temp.grade.push_back(temp2);
            buffer.clear();
        }

        examGrade = rand() % 10 + 1;
        buffer << examGrade;
        buffer >> temp.examGrade;
        buffer.clear();

        student.push_back(temp);
        temp = {};

        fout1 << student[i].name << std::setw(20) << std::right << student[i].surname << std::setw(20) << std::right;
        for (int j = 0; j < gradeNr; j++) {

            fout1 << student[i].grade[j] << std::setw(12) << std::right;
        }
        fout1 << std::setw(12);
        if (i == studentSize - 1) {
            fout1 << student[i].examGrade;
        }
        else {
            fout1 << student[i].examGrade << endl;
        }
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Faila sugeneravo per " << diff.count() << "s\n";
    cout << "Sugeneruotas failas '" << fileWrite << "'\n";
}