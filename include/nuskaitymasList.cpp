#include "Header.h"
#include "Funkcijos.h"

void nuskaitymasList(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, list<Student>& studentL) {
    string eil;
    deque<string> myDeque;
    stringstream my_buffer;
    stringstream buffer2;
    Student temp;
    int temp2;
    int sum = 0;
    float vid = 0;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

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

    cout << "Failas skaitomas..." << endl;

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff1.count() << " s\n";
    cout << "Skaiciuojama..." << endl;

    start = std::chrono::high_resolution_clock::now();
    while (my_buffer) {
        if (!my_buffer.eof()) {
            getline(my_buffer, eil);

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
            studentL.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();

    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start;

    start = std::chrono::high_resolution_clock::now();
    string output = "";

    for (string& a : myDeque) (a.compare(*myDeque.rbegin()) != 0) ? output += a + "\n" : output += a;
    myDeque.clear();

    start = std::chrono::high_resolution_clock::now();

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";
    for (auto student : studentL) {
        student.examFinal = 0.6 * student.examGrade;
        fout << student.surname << string(16 - student.surname.length(), ' ') << student.name << string(13 - student.name.length(), ' ') << "\t\t";

        for (int j = 0; j < student.numOfGrades - 1; j++) {
            sort(student.grade.begin(), student.grade.end() - 1);
            sum += student.grade[j];
            try {
                if (student.grade[j] < 1 || student.grade[j] > 10 || student.examGrade < 1 || student.examGrade > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << endl;
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = student.numOfGrades - 1;
        vid = (double)sum / gradeNr;

        student.final = 0.4 * vid + student.examFinal;

        sum = 0;

        if (student.numOfGrades % 2 == 0) {
            student.median = (student.grade[student.numOfGrades / 2] + student.grade[(student.numOfGrades / 2) - 1]) / 2.00;
        }
        else {
            student.median = student.grade[student.numOfGrades / 2];
        }
        student.medFinal = (0.4 * student.median) + (0.6 * student.examGrade);
        fout << fixed << setprecision(2) << student.final;

        fout.fill(' ');
        fout.width(20);

        fout << fixed << setprecision(2) << student.medFinal << endl;
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

    for (auto student : studentL) {
        if (student.final < 5) {
            foutLosers << student.name << string(16 - student.name.length(), ' ') << student.surname << string(16 - student.surname.length(), ' ');
            foutLosers.fill(' ');
            foutLosers.width(10);
            foutLosers << fixed << setprecision(2) << student.final << endl;
        }
        else if (student.final >= 5) {
            foutWinners << student.name << string(16 - student.surname.length(), ' ') << student.surname << string(16 - student.surname.length(), ' ');
            foutWinners.fill(' ');
            foutWinners.width(10);
            foutWinners << fixed << setprecision(2) << student.final << endl;
        }
    }

    cout << "Testing again...\n";

    fin.close();
    fout.close();

    diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Sugeneruotas failas 'Text files' folderyje\n";
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}