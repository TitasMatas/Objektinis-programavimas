#include "functions.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <tuple>
#include <chrono>

using namespace std;
using namespace std::chrono;


bool operator<(const Student& a, const Student& b) {
    if (a.pavarde != b.pavarde)
        return a.pavarde < b.pavarde;
    return a.vardas < b.vardas;
}

double mediana(vector<int> Balai)  {
    int n = Balai.size();
    if (n == 0) return 0.0;

    sort(Balai.begin(), Balai.end());

    if (n % 2 == 0) {
        return (Balai[n / 2 - 1] + Balai[n / 2]) / 2.0;
    } else {
        return Balai[n / 2];
    }
}

void ivedimas(vector<Student>& studentai, vector<vector<int>>& NamuDarbuBalai, int KiekisStudentu){
    
    if (KiekisStudentu == 0) return;

    int i = KiekisStudentu - 1;

    int balas, suma = 0, EmptyCount = 0;
    string eilute;

    cout << "\nĮveskite pažymius. Norit baigti ('Enter' du kartus): \n";   

    while (true) {
        cout << "Pažymys: ";
        getline(cin, eilute);


        if (eilute.empty()) {
            EmptyCount++;
            if (EmptyCount == 2) break;
            continue;
        }
        EmptyCount = 0;

        stringstream ss(eilute);
        int balas;
        if (!(ss >> balas) || balas <= 0 || balas > 10) {
            cout << "\nNeteisingas pažymys. Įveskite sveiką skaičių nuo 0 iki 10.\n";
            continue;
        }

        NamuDarbuBalai[i].push_back(balas);
    }

    if (NamuDarbuBalai[i].size() < 2) {
        cout << "\nReikia bent vieno namų darbo pažymio ir egzamino pažymio.\n";
        return;
    }
    
    int exam = NamuDarbuBalai[i].back();
    NamuDarbuBalai[i].pop_back();

    for (int j = 0; j < NamuDarbuBalai[i].size(); ++j) {
        suma += NamuDarbuBalai[i][j];
    }

    studentai[i].galutinisVid = ((suma / NamuDarbuBalai[i].size()) * 0.4) + (exam * 0.6);

    sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
    studentai[i].galutinisMed= mediana(NamuDarbuBalai[i]);   
}

void meniu(vector<Student>& studentai, vector<vector<int>>& NamuDarbuBalai, int& KiekisStudentu){
   
    int pasirinkimas;
    cout << "\nPasirinkimai:\n"
         << "0 - Naujas studentas\n"
         << "1 - Įvesti pažymius ranka\n"
         << "2 - Įvedami atsitiktiniai pažymiai\n"
         //<< "3 - Įvedami duomenys iš failo\n"
         << "4 - Spausdinti rezultatus\n"
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
    //else if (pasirinkimas == 3) {
    //    duomenys_is_failo(studentai, NamuDarbuBalai, KiekisStudentu);
    //}
    else if (pasirinkimas == 4) {
        rezultatas(studentai);
    }
    else if (pasirinkimas == 9) {
        exit(0);
    }
    else {
        cout << "\nNeteisingas pasirinkimas. Bandykite dar kartą.\n";
    }
}

void duomenys_is_failo(vector<Student>& studentai, vector<vector<int>>& NamuDarbuBalai, int& KiekisStudentu, const string& failoVardas) {
    auto startRead = high_resolution_clock::now();

    ifstream in(failoVardas);
    if (!in) {
        cout << "Nepavyko atidaryti failo: " << failoVardas << "\n";
        return;
    }

    string eilute;
    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string v, p;
        ss >> v >> p;

        NamuDarbuBalai.emplace_back();
        int i = KiekisStudentu;
        int suma = 0;
        int balas;

        while (ss >> balas) {
            NamuDarbuBalai[i].push_back(balas);
        }

        if (NamuDarbuBalai[i].size() < 2) {
            NamuDarbuBalai.pop_back();
            continue;
        }

        int exam = NamuDarbuBalai[i].back();
        NamuDarbuBalai[i].pop_back();

        for (int j = 0; j < NamuDarbuBalai[i].size(); ++j) {
            suma += NamuDarbuBalai[i][j];
        }

        studentai.emplace_back(v, p, 0.0, 0.0);
        studentai[i].galutinisVid = (((suma / NamuDarbuBalai[i].size()) * 0.4) + (exam * 0.6));
        sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
        studentai[i].galutinisMed = mediana(NamuDarbuBalai[i]);

        KiekisStudentu++;
    }

    auto endRead = high_resolution_clock::now();
    cout << "Failo nuskaitymo laikas: " << duration<double>(endRead - startRead).count() << " s\n";
}

void atsitiktiniai_pazymiai(vector<Student>& studentai, vector<vector<int>>& NamuDarbuBalai, int KiekisStudentu) {
    if (KiekisStudentu == 0) return;
    
    int i = KiekisStudentu - 1;

    NamuDarbuBalai[i].clear();
    int kiekis = rand() % 10 + 1;
    int suma = 0;

    for (int j = 0; j < kiekis; ++j) {
        int balas = rand() % 10 + 1;
        NamuDarbuBalai[i].push_back(balas);
        suma += balas;
    }

    int egzaminas = rand() % 10 + 1;
    NamuDarbuBalai[i].push_back(egzaminas);

    studentai[i].galutinisVid = ((suma / kiekis) * 0.4) + (egzaminas * 0.6);

    sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
    studentai[i].galutinisMed = mediana(NamuDarbuBalai[i]);    
}

void rezultatas(const vector<Student>& studentai)
{
    cout << "\nPavardė       Vardas        Galutinis (Vid.)   Galutinis (Med.)\n";
    cout << "----------------------------------------------------------------\n";

    vector<Student> sorted = studentai;
    sort(sorted.begin(), sorted.end());

    vector<Student> NeTokieProtingi, protingi;
    kategorijos(sorted, NeTokieProtingi, protingi);

     for (const auto& s : sorted) {
        cout << setw(14) << left << s.pavarde
             << setw(14) << left << s.vardas
             << fixed << setprecision(2) 
             << setw(19) << left << s.galutinisVid
             << setw(16) << left << s.galutinisMed << endl;
    }
}

void kategorijos(const vector<Student>& studentai, vector<Student>& NeTokieProtingi, vector<Student>& protingi) {
    
    auto startSort = high_resolution_clock::now();

    NeTokieProtingi.clear();
    protingi.clear();

    for (const auto& s : studentai) {
        if (s.galutinisVid >= 5.0)  protingi.emplace_back(s);
        else NeTokieProtingi.emplace_back(s);
    }

    auto endSort = high_resolution_clock::now();
    cout << "Rūšiavimo į kategorijas laikas: " << duration<double>(endSort - startSort).count() << " s\n";

    auto startWrite = high_resolution_clock::now();
    ofstream outMaziau("maziau.txt");
    ofstream outProtingi("protingi.txt");

    outProtingi << "Pavardė       Vardas        Galutinis (Vid.)   Galutinis (Med.)\n";
    outProtingi << "----------------------------------------------------------------\n";
    for (const auto& s : protingi) {
        outProtingi << setw(14) << left << s.pavarde
             << setw(14) << left << s.vardas
             << fixed << setprecision(2)
             << setw(19) << left << s.galutinisVid
             << setw(16) << left << s.galutinisMed << endl;
    }
    outProtingi.close();

    outMaziau << "Pavardė       Vardas        Galutinis (Vid.)   Galutinis (Med.)\n";
    outMaziau << "----------------------------------------------------------------\n";
    for (const auto& s : NeTokieProtingi) {
        outMaziau << setw(14) << left << s.pavarde
             << setw(14) << left << s.vardas
             << fixed << setprecision(2)
             << setw(19) << left << s.galutinisVid
             << setw(16) << left << s.galutinisMed << endl;
    }
    outMaziau.close();
    
    auto endWrite = high_resolution_clock::now();
    cout << "Įrašymo į failus laikas: " << duration<double>(endWrite - startWrite).count() << " s\n";

}
