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
#include <list>

using namespace std;
using namespace std::chrono;


bool operator<(const Student& a, const Student& b) {
    if (a.pavarde != b.pavarde)
        return a.pavarde < b.pavarde;
    return a.vardas < b.vardas;
}

double mediana(std::list<int>& balai) {
    if (balai.empty()) return 0;

    balai.sort();

    size_t n = balai.size();
    auto it = balai.begin();

    if (n % 2 == 1) {
        std::advance(it, n / 2);
        return *it;
    } else {
        auto it2 = it;
        std::advance(it,  n/2 - 1);
        std::advance(it2, n/2);
        return (*it + *it2) / 2.0;
    }
}

double skaiciuoti_galutini(Student& student, std::list<int>& balai) {
    if (balai.size() < 2) return 0.0;

    int exam = balai.back();
    balai.pop_back();

    int suma = 0;
    for (int b : balai) suma += b;

    student.galutinisVid = ((suma / (double)balai.size()) * 0.4) + (exam * 0.6);

    balai.sort();
    student.galutinisMed = mediana(balai);

    return student.galutinisVid;
}

void ivedimas(list<Student>& studentai, list<list<int>>& NamuDarbuBalai, int KiekisStudentu){
    
    if (KiekisStudentu == 0) return;

    auto itStudent = studentai.begin();
    auto itBalai = NamuDarbuBalai.begin();
    std::advance(itStudent, KiekisStudentu - 1);
    std::advance(itBalai, KiekisStudentu - 1);

    cout << "\nStudento pažymių konteinerio adresas atmintyje: " << &(*itBalai) << "\n";

    int EmptyCount = 0, balas;
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

        itBalai->push_back(balas);
    }

    if (itBalai->size() < 2) {
        cout << "\nReikia bent vieno namų darbo pažymio ir egzamino pažymio.\n";
        return;
    }
    
    skaiciuoti_galutini(*itStudent, *itBalai); 
}


void duomenys_is_failo(list<Student>& studentai, list<list<int>>& NamuDarbuBalai, int& KiekisStudentu, const string& failoVardas) {
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
        auto balaiIt = prev(NamuDarbuBalai.end());
        int balas;

        studentai.emplace_back(v, p, 0.0, 0.0);
        auto studentIt = prev(studentai.end());

        while (ss >> balas) balaiIt->push_back(balas);

        if (balaiIt->size() < 2) {
            NamuDarbuBalai.pop_back();
            studentai.pop_back();
            continue;
        }

        skaiciuoti_galutini(*studentIt, *balaiIt);
        KiekisStudentu++;
    }

    auto endRead = high_resolution_clock::now();
    cout << "Failo nuskaitymo laikas: " << duration<double>(endRead - startRead).count() << " s\n";
}

void atsitiktiniai_pazymiai(list<Student>& studentai, list<list<int>>& NamuDarbuBalai, int KiekisStudentu) {
    if (KiekisStudentu == 0) return;
    
    auto itStudent = studentai.begin();
    auto itBalai   = NamuDarbuBalai.begin();
    advance(itStudent, KiekisStudentu - 1);
    advance(itBalai,   KiekisStudentu - 1);

    itBalai->clear();

    int kiekis = rand() % 10 + 1;
    int suma = 0;

    for (int j = 0; j < kiekis; ++j) {
        int balas = rand() % 10 + 1;
        itBalai->push_back(balas);
        suma += balas;
    }

    int egzaminas = rand() % 10 + 1;
    itBalai->push_back(egzaminas);

    skaiciuoti_galutini(*itStudent, *itBalai);
}

void rezultatas(const list<Student>& studentai)
{
    cout << "\nPavardė       Vardas        Galutinis (Vid.)   Galutinis (Med.)\n";
    cout << "----------------------------------------------------------------\n";

    list<Student> sorted = studentai;
    sorted.sort([](const Student& a, const Student& b) {
        if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
        else return a.vardas < b.vardas;
    });

    list<Student> NeTokieProtingi, protingi;
    kategorijos(sorted, NeTokieProtingi, protingi);

     for (const auto& s : sorted) {
        cout << setw(14) << left << s.pavarde
             << setw(14) << left << s.vardas
             << fixed << setprecision(2) 
             << setw(19) << left << s.galutinisVid
             << setw(16) << left << s.galutinisMed << endl;
    }
}

void kategorijos(const list<Student>& studentai, list<Student>& NeTokieProtingi, list<Student>& protingi) {
    
    auto startSort = high_resolution_clock::now();

    NeTokieProtingi.clear();
    protingi.clear();

    for (const auto& s : studentai) {
        if (s.galutinisVid >= 5.0)  protingi.push_back(s);
        else NeTokieProtingi.push_back(s);
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

void kategorijos2(std::list<Student>& studentai, std::list<Student>& vargsiukai) {
    using namespace std::chrono;
    auto startSort = high_resolution_clock::now();

    vargsiukai.clear();

    for (auto it = studentai.begin(); it != studentai.end(); ) {
        auto cur = it++;
        if (cur->galutinisVid < 5.0) {
            vargsiukai.splice(vargsiukai.end(), studentai, cur);
        }
    }

    auto endSort = high_resolution_clock::now();
    cout << "Rūšiavimo į kategorijas laikas: " << duration<double>(endSort - startSort).count() << " s\n";

    auto startWrite = high_resolution_clock::now();
    ofstream OutMaziau("maziau.txt");
    ofstream OutDaugiau("protingi.txt");
    OutMaziau << "Pavardė Vardas Galutinis (Vid.) Galutinis (Med.)\n" << string(62,'-') << "\n";
    for (const auto& s : vargsiukai){
        OutMaziau << left << setw(14) << s.pavarde 
            << setw(14) << s.vardas
            << fixed << setprecision(2) 
            << setw(19) << s.galutinisVid
            << setw(16) << s.galutinisMed << '\n';
        }
    OutDaugiau << "Pavardė Vardas Galutinis (Vid.) Galutinis (Med.)\n" << string(62,'-') << "\n";
    for (const auto& s : studentai){
        OutDaugiau << left << setw(14) << s.pavarde 
            <<setw(14) << s.vardas
            << fixed << setprecision(2) 
            << setw(19) << s.galutinisVid
            << setw(16) << s.galutinisMed << '\n';
        }
    auto endWrite = high_resolution_clock::now();
    cout << "Įrašymo į failus laikas: " << duration<double>(endWrite - startWrite).count() << " s\n";
}
