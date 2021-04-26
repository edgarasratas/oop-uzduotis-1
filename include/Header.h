#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <chrono>
#include <sstream>
#include <time.h>
#include <Windows.h>
#include <direct.h>

#define GetCurrentDir _getcwd

using std::cout;
using std::cin;
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
using std::deque;
using std::list;
using std::find_if;

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