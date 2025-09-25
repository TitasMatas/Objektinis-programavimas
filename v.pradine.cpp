#include <iostream>

using namespace std;

int main() {
    int Balbai, Kiekis;
    string vardas, pavarde;
    int Galutinis = 0;
    cout << "Iveskite savo vardą ir pavardę: ";
    cin >> vardas;
    cin >> pavarde;
    cout << "Iveskite kiek balų turite: ";
    cin >> Kiekis;

    for(int i = 0; i < Kiekis; ++i) {
        cout << "Iveskite " << i + 1 << " balą: ";
        cin >> Balbai;
        Galutinis += Balbai;
    }

    Galutinis = Galutinis / Kiekis;

    cout << "Vardas: " << vardas << " Pavardė: " << pavarde << " Galutinis balas: " << Galutinis << endl;

    
    return 0;
}

