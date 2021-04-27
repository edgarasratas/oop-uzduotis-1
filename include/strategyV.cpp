#include "Funkcijos.h"

void strategyOneV(vector<Student> &student, vector<Student> & losers, vector<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

        for (int i = 0; i < student.size(); i++) {
            if (student[i].final < 5) {
                losers.push_back(student[i]);
            }
            else if (student[i].final >= 5) {
                winners.push_back(student[i]);
            }
        }

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

        for (Student a : losers) {
            foutLosers << a.name << std::setw(17) << a.surname << std::setw(17);
            foutLosers << fixed << setprecision(2) << a.final << '\n';
        }

        for (Student a : winners) {
            foutWinners << a.name << std::setw(17) << a.surname << std::setw(17);
            foutWinners << fixed << setprecision(2) << a.final << '\n';
        }
}

void strategyTwoV(vector<Student>& student, vector<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < student.size(); i++) {
        if (student[i].final < 5) {
            losers.push_back(student[i]);
        }
    }

    student.erase(std::remove_if(student.begin(), student.end(), isBad), student.end());

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

    for (Student a : losers) {
        foutLosers << a.name << std::setw(17) << a.surname << std::setw(17);
        foutLosers << fixed << setprecision(2) << a.final << '\n';
    }

    for (Student a : student) {
        foutWinners << a.name << std::setw(17) << a.surname << std::setw(17);
        foutWinners << fixed << setprecision(2) << a.final << '\n';
    }
}