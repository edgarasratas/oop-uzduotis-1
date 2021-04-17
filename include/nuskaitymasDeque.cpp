#include "Header.h"
#include "Funkcijos.h"

void nuskaitymasDeque(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, deque<Student>& studentD) {
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
            studentD.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();

    diff = std::chrono::high_resolution_clock::now() - start;

    string output = "";

    for (string& a : myDeque) (a.compare(*myDeque.rbegin()) != 0) ? output += a + "\n" : output += a;
    myDeque.clear();

    ofstream fout(fileWrite);
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    sort(studentD.begin(), studentD.end(), compareByLastName);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < studentD.size(); i++) {
        studentD[i].examFinal = 0.6 * studentD[i].examGrade;
        fout << studentD[i].surname << string(16 - studentD.at(i).surname.length(), ' ') << studentD[i].name << string(13 - studentD.at(i).name.length(), ' ') << "\t\t";

        for (int j = 0; j < studentD[i].numOfGrades - 1; j++) {
            sort(studentD[i].grade.begin(), studentD[i].grade.end() - 1);
            sum += studentD[i].grade[j];
            try {
                if (studentD[i].grade[j] < 1 || studentD[i].grade[j] > 10 || studentD[i].examGrade < 1 || studentD[i].examGrade > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << '\n';
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
        fout << fixed << setprecision(2) << studentD[i].final;

        fout.fill(' ');
        fout.width(20);

        fout << fixed << setprecision(2) << studentD[i].medFinal << '\n';
    }

    diff = std::chrono::high_resolution_clock::now() - start;

    cout << "Sugeneruotas rezultatu failas 'Text files' folderyje\n";
    cout << "Rezultatu failo generavimo trukme: " << diff.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();

    foutLosers << "Vardas";
    foutLosers.fill(' ');
    foutLosers.width(17);
    foutLosers << "Pavarde";
    foutLosers.fill(' ');
    foutLosers.width(26);
    foutLosers << "Galutinis (vid.)" << '\n';

    foutWinners << "Vardas";
    foutWinners.fill(' ');
    foutWinners.width(16);
    foutWinners << "Pavarde";
    foutWinners.fill(' ');
    foutWinners.width(26);
    foutWinners << "Galutinis (vid.)" << '\n';

    for (int i = 0; i < studentD.size(); i++) {
        if (studentD[i].final < 5) {
            foutLosers << studentD[i].name << string(16 - studentD.at(i).name.length(), ' ') << studentD[i].surname << string(16 - studentD.at(i).surname.length(), ' ');
            foutLosers.fill(' ');
            foutLosers.width(10);
            foutLosers << fixed << setprecision(2) << studentD[i].final << '\n';
        }
        else if (studentD[i].final >= 5) {
            foutWinners << studentD[i].name << string(16 - studentD.at(i).surname.length(), ' ') << studentD[i].surname << string(16 - studentD.at(i).surname.length(), ' ');
            foutWinners.fill(' ');
            foutWinners.width(10);
            foutWinners << fixed << setprecision(2) << studentD[i].final << '\n';
        }
    }
    fin.close();
    fout.close();

    diff = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Sugeneruotas failas 'Text files' folderyje\n";
    cout << "Sugeneruoti du surusiuotu studentu failai 'Losers and winners' folderyje\n";
    cout << "Studentu surusiavimas bei ju isvedimas i du atskirus failus uztruko: " << diff.count() << "s\n";
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}