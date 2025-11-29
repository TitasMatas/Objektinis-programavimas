#include "functions.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    setlocale(LC_ALL, "lt_LT.UTF-8");
    
    srand(time(NULL));

    int KiekisStudentu = 0;
    vector<Student> studentai;
    vector<vector<int>> NamuDarbuBalai;

    while (true) {
        meniu(studentai, NamuDarbuBalai, KiekisStudentu);
    }
    return 0;
}