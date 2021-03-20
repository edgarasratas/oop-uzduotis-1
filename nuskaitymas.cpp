#include "Header.h"

FILE* fin, * fout;

bool compareByLastName(const Student& a, const Student& b) {
    return a.name < b.name;
}

void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student) {
    string eil;
    vector<string> myVector;
    stringstream my_buffer;
    stringstream buffer2;
    Student temp;
    int temp2;
    int sum = 0;
    float vid = 0;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

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
            student.push_back(temp);
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

    for (string& a : myVector) (a.compare(*myVector.rbegin()) != 0) ? output += a + "\n" : output += a;
    myVector.clear();

    start = std::chrono::high_resolution_clock::now();
    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    sort(student.begin(), student.end(), compareByLastName);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < student.size(); i++) {
        student[i].examFinal = 0.6 * student[i].examGrade;
        fout << student[i].surname << string(16 - student.at(i).surname.length(), ' ') << student[i].name << string(13 - student.at(i).name.length(), ' ') << "\t\t";

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
        fout << fixed << setprecision(2) << student[i].final;

        fout.fill(' ');
        fout.width(20);

        fout << fixed << setprecision(2) << student[i].medFinal << endl;
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
        }
        else if (student[i].final >= 5) {
            foutWinners << student[i].name << string(16 - student.at(i).surname.length(), ' ') << student[i].surname << string(16 - student.at(i).surname.length(), ' ');
            foutWinners.fill(' ');
            foutWinners.width(10);
            foutWinners << fixed << setprecision(2) << student[i].final << endl;
        }
    }

    fin.close();
    fout.close();

    diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}