#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::sort;

const int temp = 100;

struct student {
    string name, surname;
    int numOfGrades;
    int* grade;
    float final;
    float examFinal;
    float median = 0;
    int examGrade;
    int a[temp];
};

int main()
{
    float sum{ 0 };
    float average;
    int n;
    string input;
    int randomNumber, randomExamGrade;

    cout << "Iveskite reikiama studentu skaiciu: \n";
    cin >> n;

    if (n >= 1) {
    }
    else {
        cout << "Klaidingas ivedimas. Studentu skaicius turi buti bent 1. Bandykite dar karta\n";
        return 0;
    }

    cout << endl;

    student* studentX;
    studentX = new student[n];

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " studentas\n";
        cout << "Iveskite studento varda: ";
        cin >> studentX[i].name;

        cout << "Iveskite studento pavarde: ";
        cin >> studentX[i].surname;

        cout << "Iveskite studento pazymiu kieki (egzamino + namu darbu): ";
        cin >> studentX[i].numOfGrades;

        cout << "Ar zinomi studento pazymiai? (y/n)\n";
        cin >> input;
    label: if (input == "Y" || input == "y") {

        studentX[i].grade = new int[studentX[i].numOfGrades];

        for (int j = 0; j < studentX[i].numOfGrades; j++) {
            if (j == 0) {
                cout << "Iveskite egzamino pazymi: ";
                cin >> studentX[i].grade[j];
                do {
                    if ((studentX[i].grade[j] > 10) || (studentX[i].grade[j] < 1)) {
                        cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta\n";
                        cout << "Iveskite egzamino pazymi: ";
                        cin >> studentX[i].grade[j];
                    }
                } while ((studentX[i].grade[j] > 10) || (studentX[i].grade[j] < 1));
            }
            else {
                cout << "Iveskite " << j << " namu darbu pazymi: ";
                cin >> studentX[i].grade[j];
                do {
                    if ((studentX[i].grade[j] > 10) || (studentX[i].grade[j] < 1)) {
                        cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta\n";
                        cout << "Iveskite " << j << " namu darbu pazymi: ";
                        cin >> studentX[i].grade[j];
                    }
                } while ((studentX[i].grade[j] > 10) || (studentX[i].grade[j] < 1));
                sum += studentX[i].grade[j];
            }

            studentX[i].a[j] = studentX[i].grade[j];
        }

        cout << endl;

        cout << endl;
    }
    else if (input == "N" || input == "n") {
        srand (time(NULL));

        randomExamGrade = rand() % 10 + 1;
        studentX[i].examGrade = randomExamGrade;

        for (int j = 0; j < studentX[i].numOfGrades; j++) {
            randomNumber = rand() % 10 + 1;
            studentX[i].a[j] = randomNumber;

            if (j == 0) {
                studentX[i].a[j] = studentX[i].examGrade;
                cout << "Egzamino pazymys: " << studentX[i].a[j] << endl << "ND pazymiai: ";
            }
            else {
                cout << studentX[i].a[j] << " ";
                sum += studentX[i].a[j];
            }
        }
        cout << endl;
    }
    else {
        cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
        cout << "Ar zinomi studento pazymiai? (y/n)\n";
        cin >> input;
        goto label;
    }

    for (int j = 0; j < studentX[i].numOfGrades; j++) {
        if (j == 0) {
            studentX[i].examFinal = 0.6 * studentX[i].a[j];
        }
        studentX[i].final = 0.4 * (sum / (studentX[i].numOfGrades - 1)) + studentX[i].examFinal;
    }

    sum = 0;

    sort(studentX[i].a, studentX[i].a + studentX[i].numOfGrades);

    for (int j = 0; j < studentX[i].numOfGrades; j++) {
        cout << studentX[i].a[j] << " ";
    }

    cout << endl;
    }
    cout << "Ar norite, kad atspausdintu galutinio pazymio vidurki (y) ar mediana? (n)\n";
    cin >> input;
    cout << endl;

    label2: if (input == "Y" || input == "y") {
        printf("Vardas\t\tPavarde\t\tGalutinis (vid.)\n");
        printf("-----------------------------------------------------\n");

        for (int i = 0; i < n; i++) {
            printf("%s\t\t%s\t\t%0.2f\n", studentX[i].name.c_str(), studentX[i].surname.c_str(), studentX[i].final);
        }
    }
    else if (input == "N" || input == "n") {
        printf("Vardas\t\tPavarde\t\tGalutinis (med.)\n");
        printf("-----------------------------------------------------\n");

        for (int i = 0; i < n; i++) {
            if (studentX[i].numOfGrades % 2 == 0) {
                studentX[i].median = (studentX[i].a[studentX[i].numOfGrades / 2] + studentX[i].a[(studentX[i].numOfGrades / 2) - 1]) / 2.00;
                printf("%s\t\t%s\t\t%0.2f\n", studentX[i].name.c_str(), studentX[i].surname.c_str(), studentX[i].median);
            }
            else {
                studentX[i].median = studentX[i].a[studentX[i].numOfGrades / 2];
                printf("%s\t\t%s\t\t%0.2f\n", studentX[i].name.c_str(), studentX[i].surname.c_str(), studentX[i].median);
            }
        }
    }
    else {
        cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
        cout << "Ar norite, kad atspausdintu vidurki galutinio pazymio ar mediana?\n";
        cin >> input;
        goto label2;
    }
    return 0;
}
