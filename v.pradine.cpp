#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int Balbai, KiekisBalu, KiekisStudentu;
    int n;

    cout << "Kiek studentų: ";
    cin >> KiekisStudentu;
    vector<string> vardas(KiekisStudentu);
    vector<string> pavarde(KiekisStudentu);
    vector<vector<int>> NamuDarbuBalai(KiekisStudentu);
    vector<double> Vidurkis(KiekisStudentu);
    vector<double> Mediana(KiekisStudentu);

    for(int i = 0; i < KiekisStudentu; ++i)
    {
        cout << "Iveskite savo vardą ir pavardę: ";
        cin >> vardas[i];
        cin >> pavarde[i];

        cout << "Iveskite kiek balų turite: ";
        cin >> KiekisBalu;

        for(int j = 0; j < KiekisBalu; ++j) {
            cout << "Iveskite " << j + 1 << " balą: ";
            cin >> Balbai;
            NamuDarbuBalai[i].push_back(Balbai);
            Vidurkis[i] += Balbai;
        }
        sort(NamuDarbuBalai[i].begin(), NamuDarbuBalai[i].end());

        n = NamuDarbuBalai[i].size();
        if (n % 2 == 0) {
            Mediana[i] = (NamuDarbuBalai[i][n/2 - 1] + NamuDarbuBalai[i][n/2]) / 2.0;
        } else {
            Mediana[i] = NamuDarbuBalai[i][n/2];
        }


        Vidurkis[i] /= KiekisBalu;
    }

cout << "\nVardas       Pavardė       Vidurkis   Mediana\n";
cout << "----------------------------------------------\n";


for (int j = 0; j < KiekisBalu; ++j) {
    cout << setw(12) << left << vardas[j] << setw(14) << left << pavarde[j] << fixed << setprecision(2) << setw(10) << right << Vidurkis[j] << setw(10) << right << Mediana[j] << endl;
}

    return 0;
}

