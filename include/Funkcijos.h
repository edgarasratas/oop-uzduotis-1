#pragma once
#include "Header.h"

void nuskaitymasVector(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student);
void nuskaitymasDeque(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, deque<Student>& studentD);
void nuskaitymasList(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, list<Student>& studentL);

void skaiciavimas();

void randomFileGenerator(string dir, string fileWrite, int studentSize, vector<Student>& student);

void sortLosersAndWinnersVector(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student);
void sortLosersAndWinnersDeque(string fileRead, string fileSortLosers, string fileSortWinners, deque<Student>& studentD);
void sortLosersAndWinnersList(string fileRead, string fileSortLosers, string fileSortWinners, list<Student>& studentL);

int createDir(string folderName);

bool compareByLastName(const Student& a, const Student& b);