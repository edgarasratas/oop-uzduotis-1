#include "Funkcijos.h"

void sortLosersAndWinnersVector(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student, int strategy) {
	stringstream buffer;
    stringstream buffer2;
    vector<Student> losers;
    vector<Student> winners;
    Student temp;
    string eil;
    int temp2;
    int sum{ 0 };
    float vid;
    int index = 0;

    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

    createDir("Losers and winners");

	ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }

    getline(fin, eil);
    buffer << fin.rdbuf();

    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    student.clear();
    while (buffer) {
        if (!buffer.eof()) {
            getline(buffer, eil);

            buffer2 << eil;

            buffer2 >> temp.name >> temp.surname;
            while (!buffer2.eof()) {
                buffer2 >> temp2;
                temp.grade.push_back(temp2);
            }
            buffer2.clear();
            temp.examGrade = temp.grade[temp.grade.size() - 1];
            temp.grade.pop_back();
            temp.grade.shrink_to_fit();
            temp.numOfGrades = temp.grade.size();
            student.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    buffer.clear();

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < student.size(); i++) {
        student[i].examFinal = 0.6 * student[i].examGrade;

        for (int j = 0; j < student[i].numOfGrades - 1; j++) {
            sort(student[i].grade.begin(), student[i].grade.end() - 1);
            sum += student[i].grade[j];
            try {
                if (student[i].grade[j] < 1 || student[i].grade[j] > 10 || student[i].examGrade < 1 || student[i].examGrade > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << '\n';
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = student[i].numOfGrades - 1;
        vid = (double)sum / gradeNr;

        student[i].final = 0.4 * vid + student[i].examFinal;

        sum = 0;

        if (student[i].numOfGrades % 2 == 0) {
            student[i].median = (student[i].grade[student[i].numOfGrades / 2] + student[i].grade[(student[i].numOfGrades / 2) - 1]) / 2.00;
        }
        else {
            student[i].median = student[i].grade[student[i].numOfGrades / 2];
        }
        student[i].medFinal = (0.4 * student[i].median) + (0.6 * student[i].examGrade);
    }

    //strategy 1

    if (strategy == 1) {
        strategyOneV(student, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwoV(student, losers, fileSortLosers, fileSortWinners);
    }

    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}