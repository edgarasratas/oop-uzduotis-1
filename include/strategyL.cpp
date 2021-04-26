#include "Funkcijos.h"

void strategyOneL(list<Student>& studentL, list<Student>& losers, list<Student>& winners, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto &student : studentL) {
        if (student.final < 5) {
            losers.push_back(student);
        }
        else if (student.final >= 5) {
            winners.push_back(student);
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

    for (Student &a : losers) {
        foutLosers << a.name << std::setw(17) << a.surname << std::setw(17);
        foutLosers << fixed << setprecision(2) << a.final << '\n';
    }

    for (Student &a : winners) {
        foutWinners << a.name << std::setw(17) << a.surname << std::setw(17);
        foutWinners << fixed << setprecision(2) << a.final << '\n';
    }
}

void strategyTwoL(list<Student>& studentL, list<Student>& losers, string fileSortLosers, string fileSortWinners) {
    ofstream foutLosers(fileSortLosers);
    ofstream foutWinners(fileSortWinners);

    for (auto &student : studentL) {
        if (student.final < 5) {
            losers.push_back(student);
        }
    }

    studentL.erase(std::remove_if(studentL.begin(), studentL.end(), isBad), studentL.end());

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

    for (Student &a : losers) {
        foutLosers << a.name << std::setw(17) << a.surname << std::setw(17);
        foutLosers << fixed << setprecision(2) << a.final << '\n';
    }

    for (Student &a : studentL) {
        foutWinners << a.name << std::setw(17) << a.surname << std::setw(17);
        foutWinners << fixed << setprecision(2) << a.final << '\n';
    }
}