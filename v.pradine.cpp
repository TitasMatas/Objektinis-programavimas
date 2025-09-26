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


using namespace std;

double mediana(const vector<int>& Balai);
void ivedimas(vector<vector<int>>& NamuDarbuBalai, vector<int>& Vidurkis, vector<double>& Mediana, int KiekisStudentu);
void meniu(vector<string>& vardas, vector<string>& pavarde, vector<vector<int>>& NamuDarbuBalai, vector<int>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu);
void duomenys_is_failo(vector<string>& vardas, vector<string>& pavarde, vector<vector<int>>& NamuDarbuBalai, vector<int>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu);
void atsitiktiniai_pazymiai(vector<vector<int>>& NamuDarbuBalai, vector<int>& Vidurkis, vector<double>& Mediana, int KiekisStudentu);
void rezultatas(const vector<string>& vardas, const vector<string>& pavarde, const vector<int>& Vidurkis, const vector<double>& Mediana, int KiekisStudentu);

int main() {
    int KiekisStudentu = 0;

    vector<string> vardas;
    vector<string> pavarde;
    vector<vector<int>> NamuDarbuBalai;
    vector<int> Vidurkis;
    vector<double> Mediana;

    while (true) {
        meniu(vardas, pavarde, NamuDarbuBalai, Vidurkis, Mediana, KiekisStudentu);
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

void ivedimas(vector<vector<int>>& NamuDarbuBalai,vector<int>& Vidurkis, vector<double>& Mediana, int KiekisStudentu){
    
    if (KiekisStudentu == 0) return;

    int i = KiekisStudentu - 1;

    int balas, suma = 0, emptyCount = 0;
    string eilute;

    cout << "Iveskite pažymius. Norit baigti ('Enter' du kartus): \n";   

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
        if (!(ss >> balas) || balas <= 0) {
            cout << "\nNeteisingas pažymys. Įveskite sveiką skaičių > 0.\n";
            continue;
        }

        NamuDarbuBalai[i].push_back(balas);
    }

    if (NamuDarbuBalai[i].size() < 2) {
        cout << "Reikia bent vieno namų darbo pažymio ir egzamino pažymio.\n";
        return;
    }
    
    int exam = NamuDarbuBalai[i].back();
    NamuDarbuBalai[i].pop_back();

    for (int j = 0; j < NamuDarbuBalai[i].size(); ++j) {
        suma += NamuDarbuBalai[i][j];
    }

    Vidurkis[i] = ((suma / NamuDarbuBalai[i].size()) * 0.4) + (exam * 0.6);

    sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
    Mediana[i] = mediana(NamuDarbuBalai[i]);   
}

void meniu(vector<string>& vardas, vector<string>& pavarde, vector<vector<int>>& NamuDarbuBalai, vector<int>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu){
   
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

        vardas.push_back(v);
        pavarde.push_back(p);
        NamuDarbuBalai.emplace_back();
        Vidurkis.push_back(0.0);
        Mediana.push_back(0.0);

        cout << "Studentas pridėtas.\n";
        KiekisStudentu++;
    }
    else if (pasirinkimas == 1) {
        if (KiekisStudentu == 0) {
            cout << "Nėra studentų. Pirmiausia pridėkite studentą.\n";
        } else {
            ivedimas(NamuDarbuBalai, Vidurkis, Mediana, KiekisStudentu);
        }
    }
    else if (pasirinkimas == 2) {
        atsitiktiniai_pazymiai(NamuDarbuBalai, Vidurkis, Mediana, KiekisStudentu);
    }
    else if (pasirinkimas == 3) {
        duomenys_is_failo(vardas, pavarde, NamuDarbuBalai, Vidurkis, Mediana, KiekisStudentu);
    }
    else if (pasirinkimas == 4) {
        rezultatas(vardas, pavarde, Vidurkis, Mediana, KiekisStudentu);
    }
    else if (pasirinkimas == 9) {
        exit(0);
    }
    else {
        cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
    }
}

void duomenys_is_failo(vector<string>& vardas, vector<string>& pavarde, vector<vector<int>>& NamuDarbuBalai, vector<int>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu) {
   
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
        vardas.push_back(v);
        pavarde.push_back(p);

        NamuDarbuBalai.emplace_back();
        int i = KiekisStudentu;
        int  suma = 0;
        int balas;
        
        while (ss >> balas) {
            NamuDarbuBalai[i].push_back(balas);
        }

        if (NamuDarbuBalai[i].size() < 2) {
            cout << "Studentui " << v << " " << p << " trūksta pažymių.\n";
            vardas.pop_back();
            pavarde.pop_back();
            NamuDarbuBalai.pop_back();
            continue;
        }

        int exam = NamuDarbuBalai[i].back();
        NamuDarbuBalai[i].pop_back();

        for (int j = 0; j < NamuDarbuBalai[i].size(); ++j) {
            suma += NamuDarbuBalai[i][j];        
        }

        Vidurkis.push_back(((suma / NamuDarbuBalai[i].size()) * 0.4) + (exam * 0.6));
        sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
        Mediana.push_back(mediana(NamuDarbuBalai[i]));   

        KiekisStudentu++;
    }

}

void atsitiktiniai_pazymiai(vector<vector<int>>& NamuDarbuBalai, vector<int>& Vidurkis, vector<double>& Mediana, int KiekisStudentu) {
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

    Vidurkis[i] = ((suma / kiekis) * 0.4) + (egzaminas * 0.6);

    sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
    Mediana[i] = mediana(NamuDarbuBalai[i]);    
}

void rezultatas(const vector<string>& vardas, const vector<string>& pavarde, const vector<int>& Vidurkis, const vector<double>& Mediana, int KiekisStudentu)
{
    cout << "\nVardas       Pavardė       Vidurkis   Mediana\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < KiekisStudentu; ++i) {
        cout << setw(12) << left << vardas[i] << setw(14) << left << pavarde[i] << fixed << setprecision(2) << setw(10) << right << Vidurkis[i] << setw(10) << right << Mediana[i] << endl;
    }
}