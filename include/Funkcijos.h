#pragma once
#include "Header.h"

void nuskaitymasVector(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student);
void nuskaitymasDeque(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, deque<Student>& studentD);
void nuskaitymasList(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, list<Student>& studentL);

void skaiciavimas();

void randomFileGenerator(string dir, string fileWrite, int studentSize, vector<Student>& student);

void sortLosersAndWinnersVector(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student, int strategy);
void sortLosersAndWinnersDeque(string fileRead, string fileSortLosers, string fileSortWinners, deque<Student>& studentD, int strategy);
void sortLosersAndWinnersList(string fileRead, string fileSortLosers, string fileSortWinners, list<Student>& studentL, int strategy);

int createDir(string folderName);

bool compareByLastName(const Student& a, const Student& b);

bool sortBadStudents(const Student& a, const Student& b);
bool isBad(const Student& a);

void strategyOneV(vector<Student>& student, vector<Student>& losers, vector<Student>& winners, string fileSortLosers, string fileSortWinners);
void strategyTwoV(vector<Student>& student, vector<Student>& losers, string fileSortLosers, string fileSortWinners);
void strategyOneD(deque<Student>& studentD, deque<Student>& losers, deque<Student>& winners, string fileSortLosers, string fileSortWinners);
void strategyTwoD(deque<Student>& studentD, deque<Student>& losers, string fileSortLosers, string fileSortWinners);
void strategyOneL(list<Student>& studentL, list<Student>& losers, list<Student>& winners, string fileSortLosers, string fileSortWinners);
void strategyTwoL(list<Student>& studentL, list<Student>& losers, string fileSortLosers, string fileSortWinners);