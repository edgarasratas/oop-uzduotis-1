#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct student {
    string name, surname;
    int numOfGrades;
    vector<int> grade;
    float final;
    int examGrade;
};

int main()
{
    float sum{ 0 };
    float average, median;
    int n;
    int nTemp;

    cout << "How many students will you need?\n";
    cin >> n;

    vector<student> studentX;

    for (int i = 0; i < n; i++) {
        studentX.push_back(student());

        cout << "Enter the name of a student: ";
        cin >> studentX[i].name;

        cout << "Enter the surname of a student: ";
        cin >> studentX[i].surname;

        cout << "Enter the exam grade: ";
        cin >> studentX[i].examGrade;

        cout << "Enter the number of grades the student has: ";
        cin >> studentX[i].numOfGrades;

        for (int j = 0; j < studentX[i].numOfGrades; j++) {
            cout << "Enter " << j + 1 << " grade: ";
            cin >> nTemp;

            studentX[i].grade.push_back(nTemp);

            sum += studentX[i].grade[j];
        }
        studentX[i].final = 0.4 * (sum / studentX[i].numOfGrades) + 0.6 * studentX[i].examGrade;

        sum = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%s      %s      %0.2f\n", studentX[i].name.c_str(), studentX[i].surname.c_str(), studentX[i].final);
    }
}