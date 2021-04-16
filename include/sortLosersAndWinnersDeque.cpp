#include "Funkcijos.h"

void sortLosersAndWinnersDeque(string fileRead, string fileSortLosers, string fileSortWinners, deque<Student>& studentD) {
    stringstream buffer;
    stringstream buffer2;
    Student temp;
    string eil;
    int temp2;
    int sum{ 0 };
    float vid;

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
        std::cerr << e.what() << endl;
        std::exit(EXIT_FAILURE);
    }

    getline(fin, eil);
    buffer << fin.rdbuf();

    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    studentD.clear();
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
            studentD.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    buffer.clear();

    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < studentD.size(); i++) {
        studentD[i].examFinal = 0.6 * studentD[i].examGrade;

        for (int j = 0; j < studentD[i].numOfGrades - 1; j++) {
            sort(studentD[i].grade.begin(), studentD[i].grade.end() - 1);
            sum += studentD[i].grade[j];
            try {
                if (studentD[i].grade[j] < 1 || studentD[i].grade[j] > 10 || studentD[i].examGrade < 1 || studentD[i].examGrade > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << endl;
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = studentD[i].numOfGrades - 1;
        vid = (double)sum / gradeNr;

        studentD[i].final = 0.4 * vid + studentD[i].examFinal;

        sum = 0;

        if (studentD[i].numOfGrades % 2 == 0) {
            studentD[i].median = (studentD[i].grade[studentD[i].numOfGrades / 2] + studentD[i].grade[(studentD[i].numOfGrades / 2) - 1]) / 2.00;
        }
        else {
            studentD[i].median = studentD[i].grade[studentD[i].numOfGrades / 2];
        }
        studentD[i].medFinal = (0.4 * studentD[i].median) + (0.6 * studentD[i].examGrade);
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

    for (int i = 0; i < studentD.size(); i++) {
        if (studentD[i].final < 5) {
            foutLosers << studentD[i].name << string(16 - studentD.at(i).name.length(), ' ') << studentD[i].surname << string(16 - studentD.at(i).surname.length(), ' ');
            foutLosers.fill(' ');
            foutLosers.width(10);
            foutLosers << fixed << setprecision(2) << studentD[i].final << endl;
            diff = std::chrono::high_resolution_clock::now() - start;
        }
        else if (studentD[i].final >= 5) {
            foutWinners << studentD[i].name << string(16 - studentD.at(i).name.length(), ' ') << studentD[i].surname << string(16 - studentD.at(i).surname.length(), ' ');
            diff = std::chrono::high_resolution_clock::now() - start;
            foutWinners.fill(' ');
            foutWinners.width(10);
            foutWinners << fixed << setprecision(2) << studentD[i].final << endl;
            diff = std::chrono::high_resolution_clock::now() - start;
        }
    }
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
}