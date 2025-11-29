
#include "functions.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "lt_LT.UTF-8");

    vector<string> files = {
        "studentai10.txt", "studentai100.txt", "studentai1000.txt",
        "studentai10000.txt", "studentai100000.txt"
    };

    for (const auto& file : files) {
        cout << "\nTestuojamas failas: " << file << "\n";

        int KiekisStudentu = 0;
        vector<Student> studentai;
        vector<vector<int>> NamuDarbuBalai;
        vector<Student> NeTokieProtingi, protingi;

        auto startTotal = high_resolution_clock::now();

        duomenys_is_failo(studentai, NamuDarbuBalai, KiekisStudentu, file);
        kategorijos(studentai, NeTokieProtingi, protingi);

        auto endTotal = high_resolution_clock::now();
        cout << "Bendras laikas: " << duration<double>(endTotal - startTotal).count() << " s\n";
    }

    return 0;
}
