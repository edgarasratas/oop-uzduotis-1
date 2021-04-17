#include "Funkcijos.h"

void skaiciavimas() {
    float sum{ 0 };
    float average;
    int n;
    string input;
    int inputInt;
    int randomNumber, randomExamGrade;
    int temp;
    vector<Student> student;

    cout << "Iveskite reikiama studentu skaiciu: \n";
    cin >> n;

    if (n >= 1) {
    }
    else {
        cout << "Klaidingas ivedimas. Studentu skaicius turi buti bent 1. Bandykite dar karta\n";
    }

    cout << '\n';

    for (int i = 0; i < n; i++) {
        student.push_back(Student());

        cout << i + 1 << " studentas\n";
        cout << "Iveskite studento varda: ";
        cin >> student[i].name;

        cout << "Iveskite studento pavarde: ";
        cin >> student[i].surname;

        cout << "Iveskite studento nd pazymiu kieki: ";
        cin >> student[i].numOfGrades;

        cout << "Ar zinomi studento pazymiai? (y/n)\n";
        cin >> input;

        do {
            if (input == "Y" || input == "y") {

                cout << "Iveskite egzamino pazymi: ";
                cin >> student[i].examGrade;

                for (int j = 0; j < student[i].numOfGrades; j++) {

                    cout << "Iveskite " << j + 1 << " nd pazymi: ";
                    cin >> temp;

                    student[i].grade.push_back(temp);

                    sum += student[i].grade[j];
                }

                cout << '\n';

                cout << '\n';
                break;
            }
            else if (input == "N" || input == "n") {
                srand(time(NULL));

                randomExamGrade = rand() % 10 + 1;

                student[i].examGrade = randomExamGrade;


                for (int j = 0; j < student[i].numOfGrades; j++) {
                    randomNumber = rand() % 10 + 1;

                    student[i].grade.push_back(randomNumber);

                    sum += student[i].grade[j];
                }

                cout << "Egzamino pazymys: " << student[i].examGrade << "\nNd pazymiai: ";

                for (int j = 0; j < student[i].numOfGrades; j++) {
                    cout << student[i].grade[j] << " ";
                }

                cout << '\n';
                break;
            }
            else {
                cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
                cout << "Ar zinomi studento pazymiai? (y/n)\n";
                cin >> input;
            }
        } while (input != "Y" || input != "y" || input != "N" || input != "n");

    student[i].examFinal = 0.6 * student[i].examGrade;

    for (int j = 1; j < student[i].numOfGrades; j++) {
        student[i].final = 0.4 * (sum / (student[i].numOfGrades)) + student[i].examFinal;
    }

    sum = 0;

    sort(student[i].grade.begin(), student[i].grade.end());

    for (int j = 0; j < student[i].numOfGrades; j++) {
    }
    cout << '\n';
    }
    cout << "Ar norite, kad atspausdintu galutinio pazymio vidurki (y) ar mediana? (n)\n";
    cin >> input;
    cout << '\n';

    do {
        if (input == "Y" || input == "y") {
            printf("Vardas\t\tPavarde\t\tGalutinis (vid.)\n");
            printf("-----------------------------------------------------\n");

            for (int i = 0; i < n; i++) {
                printf("%s\t\t%s\t\t%0.2f\n", student[i].name.c_str(), student[i].surname.c_str(), student[i].final);
            }
            break;
        }
        else if (input == "N" || input == "n") {
            printf("Vardas\t\tPavarde\t\tGalutinis (med.)\n");
            printf("-----------------------------------------------------\n");

            for (int i = 0; i < n; i++) {
                sort(student[i].grade.begin(), student[i].grade.end());

                if (student[i].numOfGrades % 2 == 0) {
                    student[i].median = (student[i].grade[student[i].numOfGrades / 2] + student[i].grade[(student[i].numOfGrades / 2) - 1]) / 2.00;
                }
                else {
                    student[i].median = student[i].grade[student[i].numOfGrades / 2];
                }
                student[i].medFinal = (0.4 * student[i].median) + (0.6 * student[i].examGrade);
                printf("%s\t\t%s\t\t%0.2f\n", student[i].name.c_str(), student[i].surname.c_str(), student[i].medFinal);
            }
            break;
        }
        else {
            cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
            cout << "Ar norite, kad atspausdintu galutinio pazymio vidurki (y) ar mediana? (n)\n";
            cin >> input;
        }
    } while (input != "Y" || input != "y" || input != "N" || input != "n");
}