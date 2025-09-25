#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int Balbai, KiekisBalu, KiekisStudentu;
    string vardas, pavarde;
   

    cout << "Kiek studentų: ";
    cin >> KiekisStudentu;

    float Galutinis[KiekisStudentu] = {0};

    for(int i = 0; i < KiekisStudentu; ++i)
    {
        cout << "Iveskite savo vardą ir pavardę: ";
        cin >> vardas;
        cin >> pavarde;

        cout << "Iveskite kiek balų turite: ";
        cin >> KiekisBalu;

        for(int j = 0; j < KiekisBalu; ++j) {
            cout << "Iveskite " << j + 1 << " balą: ";
            cin >> Balbai;
            Galutinis[i] += Balbai;
        }
        Galutinis[i] /= KiekisBalu;
    }

   
cout << "\nVardas       Pavardė       Galutinis balas\n";
cout << "------------------------------------------\n";

for (int j = 0; j < KiekisBalu; ++j) {
    cout << setw(12) << left << vardas << setw(14) << left << pavarde << fixed << setprecision(2) << setw(6) << right << Galutinis[j] << endl;
}

    return 0;
}

