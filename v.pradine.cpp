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

using namespace std;

double mediana(const vector<int>& Balai);
void ivedimas(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai, int KiekisStudentu);
void meniu(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai,int& KiekisStudentu);
void duomenys_is_failo(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai, int& KiekisStudentu);
void atsitiktiniai_pazymiai(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai, int KiekisStudentu);
void rezultatas(const vector<tuple<string, string, double, double>>& studentai);

int main() {
    int KiekisStudentu = 0;

    vector<tuple<string, string, double, double>> studentai;
    vector<vector<int>> NamuDarbuBalai;

    while (true) {
        meniu(studentai, NamuDarbuBalai, KiekisStudentu);
    }
    return 0;
}

double mediana(const vector<int>& Balai) {
    int n = Balai.size();
    if (n == 0) return 0.0;

    if (n % 2 == 0) {
        return (Balai[n / 2 - 1] + Balai[n / 2]) / 2.0;
    } else {
        return Balai[n / 2];
    }
}

void ivedimas(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai, int KiekisStudentu){
    
    if (KiekisStudentu == 0) return;

    int i = KiekisStudentu - 1;

    int balas, suma = 0, emptyCount = 0;
    string eilute;

    cout << "\nIveskite pažymius. Norit baigti ('Enter' du kartus): \n";   

    while (true) {
        cout << "Pažymys: ";
        getline(cin, eilute);


        if (eilute.empty()) {
            emptyCount++;
            if (emptyCount == 2) break;
            continue;
        }
        emptyCount = 0;

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

    get<2>(studentai[i]) = ((suma / NamuDarbuBalai[i].size()) * 0.4) + (exam * 0.6);

    sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
    get<3>(studentai[i]) = mediana(NamuDarbuBalai[i]);   
}

void meniu(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai,int& KiekisStudentu){
   
    int pasirinkimas;
    cout << "\nPasirinkimai:\n"
         << "0 - Naujas studentas\n"
         << "1 - Įvesti pažymius ranka\n"
         << "2 - Įvedami atsitiktiniai pažymiai\n"
         << "3 - Įvedami duomenys iš failo\n"
         << "4 - Spausdinti rezultatus\n"
         << "9 - Išeiti\n"
         << "Pasirinkimas: ";
    cin >> pasirinkimas;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (pasirinkimas == 0) {
        string v, p;
        cout << "Įveskite vardą ir pavardę: ";
        getline(cin, v, ' ');
        getline(cin, p);

        studentai.emplace_back(p, v, 0.0, 0.0);
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
        duomenys_is_failo(studentai, NamuDarbuBalai, KiekisStudentu);
    }
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

void duomenys_is_failo(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai, int& KiekisStudentu) {
   
    string failoVardas = "kursiokai.txt";
    cout << "Duomenys iš failo kursiokai.txt: ";

    ifstream in(failoVardas);
    if (!in) {
        cout << "Nepavyko atidaryti failo.\n";
        return;
    }

    string eilute;
    
    while (getline(in, eilute)) {
        stringstream ss(eilute);
        string v, p;
        ss >> v >> p;
        

        NamuDarbuBalai.emplace_back();
        int i = KiekisStudentu;
        int  suma = 0;
        int balas;
        
        while (ss >> balas) {
            NamuDarbuBalai[i].push_back(balas);
        }

        if (NamuDarbuBalai[i].size() < 2) {
            cout << "Studentui " << v << " " << p << " trūksta pažymių.\n";
            NamuDarbuBalai.pop_back();
            continue;
        }

        int exam = NamuDarbuBalai[i].back();
        NamuDarbuBalai[i].pop_back();

        for (int j = 0; j < NamuDarbuBalai[i].size(); ++j) {
            suma += NamuDarbuBalai[i][j];        
        }


        studentai.emplace_back(p, v, 0.0, 0.0);
        get<2>(studentai[i]) = (((suma / NamuDarbuBalai[i].size()) * 0.4) + (exam * 0.6));
        sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
        get<3>(studentai[i]) = (mediana(NamuDarbuBalai[i]));   

        KiekisStudentu++;
    }
}

void atsitiktiniai_pazymiai(vector<tuple<string, string, double, double>>& studentai, vector<vector<int>>& NamuDarbuBalai, int KiekisStudentu) {
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

    get<2>(studentai[i]) = ((suma / kiekis) * 0.4) + (egzaminas * 0.6);

    sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
    get<3>(studentai[i]) = mediana(NamuDarbuBalai[i]);    
}

void rezultatas(const vector<tuple<string, string, double, double>>& studentai)
{
    cout << "\nPavardė       Vardas        Galutinis (Vid.)   Galutinis (Med.)\n";
    cout << "----------------------------------------------------------------\n";

    vector<tuple<string, string, double, double>> sorted = studentai;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < sorted.size(); ++i) {
        cout << setw(14) << left << get<1>(sorted[i]) << setw(14) << left << get<0>(sorted[i]) << fixed << setprecision(2) << setw(19) << right << get<2>(sorted[i]) << setw(16) << right << get<3>(sorted[i]) << endl;
    }
}