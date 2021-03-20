#include "Funkcijos.h"

void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student) {
	stringstream buffer;
    stringstream buffer2;
    Student temp;
    string eil;
    int temp2;
    int sum{ 0 };
    float vid;

    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

	ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << endl;
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
                std::cerr << e.what() << endl;
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

    foutLosers << "Vardas";
    foutLosers.fill(' ');
    foutLosers.width(17);
    foutLosers << "Pavarde";
    foutLosers.fill(' ');
    foutLosers.width(26);
    foutLosers << "Galutinis (vid.)" << endl;

    foutWinners << "Vardas";
    foutWinners.fill(' ');
    foutWinners.width(16);
    foutWinners << "Pavarde";
    foutWinners.fill(' ');
    foutWinners.width(26);
    foutWinners << "Galutinis (vid.)" << endl;

    for (int i = 0; i < student.size(); i++) {
        if (student[i].final < 5) {
            foutLosers << student[i].name << string(16 - student.at(i).name.length(), ' ') << student[i].surname << string(16 - student.at(i).surname.length(), ' ');
            foutLosers.fill(' ');
            foutLosers.width(10);
            foutLosers << fixed << setprecision(2) << student[i].final << endl;
            diff = std::chrono::high_resolution_clock::now() - start;
        }
        else if (student[i].final >= 5) {
            foutWinners << student[i].name << string(16 - student.at(i).name.length(), ' ') << student[i].surname << string(16 - student.at(i).surname.length(), ' ');
            diff = std::chrono::high_resolution_clock::now() - start;
            foutWinners.fill(' ');
            foutWinners.width(10);
            foutWinners << fixed << setprecision(2) << student[i].final << endl;
            diff = std::chrono::high_resolution_clock::now() - start;
        }
    }
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}