#pragma once
#include "Header.h"

void nuskaitymas(string fileRead, string fileWrite, string fileSortLosers, string fileSortWinners, vector<Student>& student);
void skaiciavimas();
void randomFileGenerator(string fileWrite, int studentSize, vector<Student>& student);
void sortLosersAndWinners(string fileRead, string fileSortLosers, string fileSortWinners, vector<Student>& student);
