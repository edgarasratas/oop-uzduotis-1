#include "Header.h"
#include "Funkcijos.h"

void nuskaitymasVector(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student) {
    string eil;
    vector<Student> losers;
    vector<Student> winners;
    stringstream my_buffer;
    stringstream buffer2;
    Student temp;
    int temp2;
    int sum = 0;
    float vid = 0;
    int strategy;
    int index = 0;

    do {
        index++;
        if (index != 1)
            cout << "Neteisinga ivestis. Bandykite dar karta.\n";

        cout << "Kokia strategija noretumet panaudoti? (1/2)\n";
        cin >> strategy;

        if (strategy == 1 || strategy == 2)
            break;
    } while (strategy != 1 || strategy != 2);

    student.reserve(10000000);
    losers.reserve(10000000);
    winners.reserve(10000000);

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

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
    cout << "Failas skaitomas..." << '\n';

    getline(fin, eil);
    my_buffer << fin.rdbuf();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
    cout << "Skaiciuojama..." << '\n';

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

    diff = std::chrono::high_resolution_clock::now() - start;

    string output = "";

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
        fout << fixed << setprecision(2) << student[i].final;

        fout.fill(' ');
        fout.width(20);

        fout << fixed << setprecision(2) << student[i].medFinal << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    //strategy 1

    if (strategy == 1) {
        strategyOneV(student, losers, winners, fileSortLosers, fileSortWinners);
    }

    //strategy 2

    else if (strategy == 2) {
        strategyTwoV(student, losers, fileSortLosers, fileSortWinners);
    }

    fin.close();
    fout.close();

    diff = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}