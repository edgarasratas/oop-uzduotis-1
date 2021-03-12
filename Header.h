#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <chrono>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::sort;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::chrono::high_resolution_clock;
using std::getline;
using std::stringstream;
using std::setw;
using std::fixed;
using std::istreambuf_iterator;

struct Student {
    string name, surname;
    int numOfGrades;
    float final;
    float examFinal;
    float medFinal;
    float median = 0;
    int examGrade;
    vector<int> grade;
};