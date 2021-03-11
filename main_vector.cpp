#include "Header.h"

FILE* fin, * fout;

void nuskaitymas(string fileRead, string fileWrite, vector<Student>& student);
void skaiciavimas();

void nuskaitymas(string fileRead, string fileWrite, vector<Student>& student) {
    string eil;
    vector<string> myVector;
    stringstream my_buffer;
    stringstream buffer2;
    Student temp;
    int temp2;
    int examTemp;
    int test = 5;
    int sum = 0;
    float vid;

    cout << "Failas skaitomas..." << endl;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    ifstream fin(fileRead);

    getline(fin, eil);
    my_buffer << fin.rdbuf();

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Failo nuskaitymo trukme: " << diff.count() << " s\n";
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

    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Buferio padalijimas i eiluciu vektoriu uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    string output = "";

    for (string& a : myVector) (a.compare(*myVector.rbegin()) != 0) ? output += a + "\n" : output += a;
    myVector.clear();

    start = std::chrono::high_resolution_clock::now();
    ofstream fout(fileWrite);

    fout << "Pavarde\t\t\t" << "Vardas\t\t" << "Galutinis (Vid)\t\t" << "Galutinis (Med.)\n";
    fout << "------------------------------------------------------------------------\n";


    for (int i = 0; i < student.size(); i++) {
        student[i].examFinal = 0.6 * student[i].examGrade;

        if (i >= 9) {
            fout << student[i].surname << "\t\t" << student[i].name << "\t\t";
        }
        else {
            fout << student[i].surname << "\t\t" << student[i].name << "\t\t\t";
        }

        for (int j = 0; j < student[i].numOfGrades; j++) {
            sum += student[i].grade[j];
        }
        vid = sum / student[i].numOfGrades;

        student[i].final = 0.4 * vid + student[i].examFinal;

        sum = 0;

        if (student[i].numOfGrades % 2 == 0) {
            student[i].median = (student[i].grade[student[i].numOfGrades / 2] + student[i].grade[(student[i].numOfGrades / 2) - 1]) / 2.00;
        }
        else {
            student[i].median = student[i].grade[student[i].numOfGrades / 2];
        }
        student[i].medFinal = (0.4 * student[i].median) + (0.6 * student[i].examGrade);

        fout << student[i].final << "\t\t\t\t\t" << student[i].medFinal << endl;
    }

    fin.close();
    fout.close();

    diff = std::chrono::high_resolution_clock::now() - st;
    cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
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
    label: if (input == "Y" || input == "y") {

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
    }
    else {
        cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
        cout << "Ar zinomi studento pazymiai? (y/n)\n";
        cin >> input;
        goto label;
    }

    student[i].examFinal = 0.6 * student[i].examGrade;

    for (int j = 1; j < student[i].numOfGrades; j++) {
        student[i].final = 0.4 * (sum / (student[i].numOfGrades - 1)) + student[i].examFinal;
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

label2: if (input == "Y" || input == "y") {
    printf("Vardas\t\tPavarde\t\tGalutinis (vid.)\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t\t%s\t\t%0.2f\n", student[i].name.c_str(), student[i].surname.c_str(), student[i].final);
    }
}
else if (input == "N" || input == "n") {
    printf("Vardas\t\tPavarde\t\tGalutinis (med.)\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        sort(student[i].grade.begin(), student[i].grade.end());

        if (student[i].numOfGrades % 2 == 0) {
            student[i].median = (student[i].grade[student[i].numOfGrades / 2] + student[i].grade[(student[i].numOfGrades / 2) - 1]) / 2.00;
            printf("%s\t\t%s\t\t%0.2f\n", student[i].name.c_str(), student[i].surname.c_str(), student[i].median);
        }
        else {
            student[i].median = student[i].grade[student[i].numOfGrades / 2];
            printf("%s\t\t%s\t\t%0.2f\n", student[i].name.c_str(), student[i].surname.c_str(), student[i].median);
        }
        student[i].medFinal = (0.4 * student[i].median) + (0.6 * student[i].examGrade);
    }
}
else {
    cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
    cout << "Ar norite, kad atspausdintu vidurki galutinio pazymio ar mediana?\n";
    cin >> input;
    goto label2;
}
}

int main()
{
    string input;
    string eil;
    string name, surname;
    vector<Student> student;
    int inputInt;

    cout << "Ar norite nuskaityti pazymius is failo (Y)?\nPaspaudzius (N) reikes pazymius ivesti\n";
    cin >> input;

label3: if (input == "Y" || input == "y") {
    cout << "Pasirinkite koki faila noretumete nuskaityti: \n";
    cout << "1. studentai10000.txt\n";
    cout << "2. studentai100000.txt\n";
    cout << "3. studentai1000000.txt\n";
    cin >> inputInt;

    if (inputInt == 1) {
        nuskaitymas("studentai10000.txt", "studentai10000_rez.txt", student);
    }
    else if (inputInt == 2) {
        nuskaitymas("studentai100000.txt", "studentai100000_rez.txt", student);
    }
    else if (inputInt == 3) {
        nuskaitymas("studentai1000000.txt", "studentai1000000_rez.txt", student);
    }
}
    else if (input == "N" || input == "n") {
        skaiciavimas();
    }
    else {
        cout << "Klaida. Bandykite dar karta\n";
        cout << "Ar norite nuskaityti pazymius is failo (Y)?\nPaspaudzius (N) reikes pazymius ivesti\n";
        cin >> input;
        goto label3;
    }

    
}