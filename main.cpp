
#include "functions.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <list>
#include <limits>
using namespace std;
using namespace std::chrono;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "lt_LT.UTF-8");

    // List strategijos konteineriai
    list<Student> studentai;
    list<list<int>> NamuDarbuBalai;
    list<Student> NeTokieProtingi, protingi;
    int KiekisStudentu = 0;

    // Vector strategijos konteineriai
    vector<Student> studentaiV;
    vector<vector<int>> NamuDarbuBalaiV;
    vector<Student> NeTokieProtingiV, protingiV;
    int KiekisStudentuV = 0;

    while (true) {
        int pasirinkimas;
        cout << "\nPasirinkimai:\n"
             << "0 - Naujas studentas (LIST)\n"
             << "1 - Įvesti pažymius ranka (LIST)\n"
             << "2 - Įvedami atsitiktiniai pažymiai (LIST)\n"
             << "3 - Įvedami duomenys iš failo (LIST)\n"
             << "4 - Laiko testas \"1 Strategija\" - LIST\n"
             << "5 - Laiko testas \"1 Strategija\" - VECTOR\n"
             << "6 - Spausdinti rezultatus (LIST)\n"
             << "9 - Išeiti\n"
             << "Pasirinkimas: ";
        if (!(cin >> pasirinkimas)) return 0;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pasirinkimas == 0) {
            string v, p;
            cout << "\nĮveskite vardą ir pavardę: ";
            getline(cin, v, ' ');
            getline(cin, p);
            studentai.emplace_back(v, p, 0.0, 0.0);
            NamuDarbuBalai.emplace_back();
            cout << "\nStudentas (LIST) pridėtas.\n";
            KiekisStudentu++;
        }
        else if (pasirinkimas == 1) {
            if (KiekisStudentu == 0) {
                cout << "\nNėra studentų. Pirmiausia pridėkite studentą.\n";
            } else {
                ivedimas(studentai, NamuDarbuBalai, KiekisStudentu);
            }
        }
        else if (pasirinkimas == 2) {
            atsitiktiniai_pazymiai(studentai, NamuDarbuBalai, KiekisStudentu);
        }
        else if (pasirinkimas == 3) {
            string file;
            cout << "\nĮveskite failo vardą: ";
            getline(cin, file);
            duomenys_is_failo(studentai, NamuDarbuBalai, KiekisStudentu, file);
        }
        else if (pasirinkimas == 4) {
            vector<string> files = {
                "studentai10.txt", "studentai100.txt", "studentai1000.txt",
                "studentai10000.txt", "studentai100000.txt"
            }; 
            for (const auto& file : files) {
                cout << "\n[Test LIST] Failas: " << file << "\n";
                list<Student> testStudentai;
                list<list<int>> testBalai;
                int testKiekis = 0;
                auto startTotal = high_resolution_clock::now();
                duomenys_is_failo(testStudentai, testBalai, testKiekis, file);
                kategorijos(testStudentai, NeTokieProtingi, protingi);
                auto endTotal = high_resolution_clock::now();
                cout << "Bendras laikas (LIST): "
                     << duration<double>(endTotal - startTotal).count()
                     << " s\n";
            }
        }
        else if (pasirinkimas == 5) {
            vector<string> files = {
                "studentai10.txt", "studentai100.txt", "studentai1000.txt",
                "studentai10000.txt", "studentai100000.txt"
            };
            for (const auto& file : files) {
                cout << "\n[Test VECTOR] Failas: " << file << "\n";
                vector<Student> testStudentai;
                vector<vector<int>> testBalai;
                int testKiekis = 0;
                auto startTotal = high_resolution_clock::now();
                duomenys_is_failo(testStudentai, testBalai, testKiekis, file);
                kategorijos(testStudentai, NeTokieProtingiV, protingiV);
                auto endTotal = high_resolution_clock::now();
                cout << "Bendras laikas (VECTOR): "
                     << duration<double>(endTotal - startTotal).count()
                     << " s\n";
            }
        }
        else if (pasirinkimas == 6) {
            rezultatas(studentai);
        }
        else if (pasirinkimas == 9) {
            break;
        }
        else {
            cout << "\nNeteisingas pasirinkimas. Bandykite dar kartą.\n";
        }
    }
    return 0;
}
