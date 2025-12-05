
#include "functions.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <list>
using namespace std;
using namespace std::chrono;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "lt_LT.UTF-8");

    list<Student> studentai;
    list<list<int>> NamuDarbuBalai;
    list<Student> NeTokieProtingi, protingi;
    int KiekisStudentu = 0;

    while (true) {
        int pasirinkimas;
        cout << "\nPasirinkimai:\n"
             << "0 - Naujas studentas\n"
             << "1 - Įvesti pažymius ranka\n"
             << "2 - Įvedami atsitiktiniai pažymiai\n"
             << "3 - Įvedami duomenys iš failo\n" 
             << "4 - Laiko testas\n"
             << "5 - Spausdinti rezultatus\n" 
             << "9 - Išeiti\n"
             << "Pasirinkimas: ";
        cin >> pasirinkimas;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pasirinkimas == 0) {
            string v, p;
            cout << "\nĮveskite vardą ir pavardę: ";
            getline(cin, v, ' ');
            getline(cin, p);

            studentai.emplace_back(v, p, 0.0, 0.0);
            NamuDarbuBalai.emplace_back();

            cout << "\nStudentas pridėtas.\n";
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
        else if (pasirinkimas == 4)  {
            vector<string> files = {
                "studentai10.txt", "studentai100.txt", "studentai1000.txt",
                "studentai10000.txt", "studentai100000.txt"
            };
            for (const auto& file : files) {
                cout << "\nTestuojamas failas: " << file << "\n";

                list<Student> testStudentai;
                list<list<int>> testBalai;
                int testKiekis = 0;

                auto startTotal = high_resolution_clock::now();
                duomenys_is_failo(testStudentai, testBalai, testKiekis, file);
                kategorijos(testStudentai, NeTokieProtingi, protingi);
                auto endTotal = high_resolution_clock::now();

                cout << "Bendras laikas: "
                     << duration<double>(endTotal - startTotal).count()
                     << " s\n";
            }
        }
        else if (pasirinkimas == 5) {
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
