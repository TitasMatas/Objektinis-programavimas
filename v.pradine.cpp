#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

double mediana(const vector<int>& Balai);
void ivedimas(vector<string>& vardas, vector<string>& pavarde,vector<vector<int>>& NamuDarbuBalai,vector<double>& Vidurkis, vector<double>& Mediana,int KiekisStudentu);

int main() {
    int KiekisStudentu;
    cout << "Kiek studentų: ";
    cin >> KiekisStudentu;

    vector<string> vardas(KiekisStudentu);
    vector<string> pavarde(KiekisStudentu);
    vector<vector<int>> NamuDarbuBalai(KiekisStudentu);
    vector<double> Vidurkis(KiekisStudentu);
    vector<double> Mediana(KiekisStudentu);

    ivedimas(vardas, pavarde, NamuDarbuBalai, Vidurkis, Mediana, KiekisStudentu);

    cout << "\nVardas       Pavardė       Vidurkis   Mediana\n";
    cout << "----------------------------------------------\n";


    for (int j = 0; j < KiekisStudentu; ++j) {
        cout << setw(12) << left << vardas[j] << setw(14) << left << pavarde[j] << fixed << setprecision(2) << setw(10) << right << Vidurkis[j] << setw(10) << right << Mediana[j] << endl;
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



void ivedimas(vector<string>& vardas, vector<string>& pavarde,vector<vector<int>>& NamuDarbuBalai,vector<double>& Vidurkis, vector<double>& Mediana,int KiekisStudentu)
{
    int balas, suma = 0;

    for(int i = 0; i < KiekisStudentu; ++i) {
        cout << "Iveskite savo vardą ir pavardę: ";
        cin >> vardas[i];
        cin >> pavarde[i];

        cout << "Iveskite pažymius. Norit baigti ('Enter' du kartus): \n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string eilute;
        int suma = 0, kiekis = 0;

        while (true) {
            cout << "Pažymys: ";
            getline(cin, eilute);

            if (eilute.empty()) break;

            stringstream ss(eilute);
            int balas;
            if (!(ss >> balas) || balas <= 0) {
                cout << "Neteisingas pažymys. Įveskite sveiką skaičių > 0.\n";
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
}