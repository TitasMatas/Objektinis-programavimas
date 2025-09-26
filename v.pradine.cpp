#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

double mediana(const vector<int>& Balai);
void ivedimas(vector<vector<int>>& NamuDarbuBalai, vector<double>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu);
void meniu(vector<string>& vardas, vector<string>& pavarde, vector<vector<int>>& NamuDarbuBalai, vector<double>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu);
void rezultatas(const vector<string>& vardas, const vector<string>& pavarde, const vector<double>& Vidurkis, const vector<double>& Mediana, int KiekisStudentu);

int main() {
    int KiekisStudentu = 0;

    vector<string> vardas;
    vector<string> pavarde;
    vector<vector<int>> NamuDarbuBalai;
    vector<double> Vidurkis;
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



void ivedimas(vector<vector<int>>& NamuDarbuBalai,vector<double>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu){
    
    if (KiekisStudentu == 0) return;

    int i = KiekisStudentu - 1;

    int balas, suma = 0, kiekis = 0, emptyCount = 0;
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
        suma += balas;
        kiekis++;
    }

    sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());
    Mediana[i] = mediana(NamuDarbuBalai[i]);

    Vidurkis[i] = suma / kiekis;
}



void meniu(vector<string>& vardas, vector<string>& pavarde, vector<vector<int>>& NamuDarbuBalai, vector<double>& Vidurkis, vector<double>& Mediana, int& KiekisStudentu){
   
    int pasirinkimas;
    cout << "\nPasirinkimai:\n"
         << "0 - Naujas studentas\n"
         << "1 - Įvesti pažymius ranka\n"
         << "2 - Spausdinti rezultatus\n"
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
        rezultatas(vardas, pavarde, Vidurkis, Mediana, KiekisStudentu);
    }
    else if (pasirinkimas == 9) {
        exit(0);
    }
    else {
        cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
    }
}



void rezultatas(const vector<string>& vardas, const vector<string>& pavarde, const vector<double>& Vidurkis, const vector<double>& Mediana, int KiekisStudentu)
{
    cout << "\nVardas       Pavardė       Vidurkis   Mediana\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < KiekisStudentu; ++i) {
        cout << setw(12) << left << vardas[i] << setw(14) << left << pavarde[i] << fixed << setprecision(2) << setw(10) << right << Vidurkis[i] << setw(10) << right << Mediana[i] << endl;
    }
}