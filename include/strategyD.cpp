#include "Funkcijos.h"

void strategyOneD(deque<Student>& studentD, deque<Student>& losers, deque<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < studentD.size(); i++) {
        if (studentD[i].final < 5) {
            losers.push_back(studentD[i]);
        }
        else if (studentD[i].final >= 5) {
            winners.push_back(studentD[i]);
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

void strategyTwoD(deque<Student>& studentD, deque<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (int i = 0; i < studentD.size(); i++) {
        if (studentD[i].final < 5) {
            losers.push_back(studentD[i]);
        }
    }

    studentD.erase(std::remove_if(studentD.begin(), studentD.end(), isBad), studentD.end());

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

    for (Student a : studentD) {
        foutWinners << a.name << std::setw(17) << a.surname << std::setw(17);
        foutWinners << fixed << setprecision(2) << a.final << '\n';
    }
}