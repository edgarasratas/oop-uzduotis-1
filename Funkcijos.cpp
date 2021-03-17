#include "Funkcijos.h"

FILE* fin, * fout;

bool compareByLastName(const Student& a, const Student& b) {
    return a.name < b.name;
}

void nuskaitymas(string fileRead, string fileWrite, vector<Student>& student) {
    string eil;
    vector<string> myVector;
    stringstream my_buffer;
    stringstream buffer2;
    Student temp;
    int temp2;
    int sum = 0;
    float vid = 0;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    ifstream fin(fileRead, std::ios::binary);

    try {
        if (fin.fail()) {
            throw std::exception("Tokio failo nera...");
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << endl;
        std::exit(EXIT_FAILURE);
    }

    cout << "Failas skaitomas..." << endl;

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff1.count() << " s\n";
    cout << "Skaiciuojama..." << endl;

    start = std::chrono::high_resolution_clock::now();

    while (my_buffer) {
        if (!my_buffer.eof()) {
            getline(my_buffer, eil);

            buffer2 << eil;

            buffer2 >> temp.name >> temp.surname;
            while (!buffer2.eof()) {
                buffer2 >> temp2;
                temp.grade.push_back(temp2);
            }
            
            buffer2.clear();
            temp.examGrade = temp.grade[temp.grade.size() - 1];
            temp.grade.pop_back();
            temp.grade.shrink_to_fit();
            temp.numOfGrades = temp.grade.size();
            student.push_back(temp);
            temp = {};
        }
        else {
            break;
        }
    }
    my_buffer.clear();

    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start;

    start = std::chrono::high_resolution_clock::now();
    string output = "";

    for (string& a : myVector) (a.compare(*myVector.rbegin()) != 0) ? output += a + "\n" : output += a;
    myVector.clear();

    start = std::chrono::high_resolution_clock::now();
    ofstream fout(fileWrite);

    sort(student.begin(), student.end(), compareByLastName);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < student.size(); i++) {
        student[i].examFinal = 0.6 * student[i].examGrade;
            fout << student[i].surname << string(16 - student.at(i).surname.length(), ' ') << student[i].name << string(13 - student.at(i).name.length(), ' ') << "\t\t";

        for (int j = 0; j < student[i].numOfGrades - 1; j++) {
            sort(student[i].grade.begin(), student[i].grade.end() - 1);
            sum += student[i].grade[j];
            try {
                if (student[i].grade[j] < 1 || student[i].grade[j] > 10 || student[i].examGrade < 1 || student[i].examGrade > 10) {
                    throw std::exception("Ivestas netinkamas pazymys...");
                }
            }
            catch (std::exception& e) {
                std::cerr << e.what() << endl;
                std::exit(EXIT_FAILURE);
            }
        }
        int gradeNr = student[i].numOfGrades - 1;
        vid = (double) sum / gradeNr;

        student[i].final = 0.4 * vid + student[i].examFinal;

        sum = 0;

        if (student[i].numOfGrades % 2 == 0) {
            student[i].median = (student[i].grade[student[i].numOfGrades / 2] + student[i].grade[(student[i].numOfGrades / 2) - 1]) / 2.00;
        }
        else {
            student[i].median = student[i].grade[student[i].numOfGrades / 2];
        }
        student[i].medFinal = (0.4 * student[i].median) + (0.6 * student[i].examGrade);
        fout << fixed << setprecision(2) << student[i].final;

        fout.fill(' ');
        fout.width(20);

        fout << fixed << setprecision(2) << student[i].medFinal << endl;
    }
    cout << "Buferio padalijimas i eiluciu vektoriu uztruko: " << diff2.count() << " s\n";

    fin.close();
    fout.close();

    diff2 = std::chrono::high_resolution_clock::now() - st;
    cout << "Visas sugaistas laikas: " << diff2.count() << " s\n\n";
}

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

    cout << endl;

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

                cout << endl;

                cout << endl;
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

                cout << endl;
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
    cout << endl;
    }
    cout << "Ar norite, kad atspausdintu galutinio pazymio vidurki (y) ar mediana? (n)\n";
    cin >> input;
    cout << endl;

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
