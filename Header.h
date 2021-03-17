#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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
using std::fixed;
using std::setprecision;
using std::fill;

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