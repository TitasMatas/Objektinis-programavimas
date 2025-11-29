#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "student.h"
#include <vector>

bool operator<(const Student& a, const Student& b);

double mediana(std::vector<int> Balai);
void ivedimas(std::vector<Student>& studentai, std::vector<std::vector<int>>& NamuDarbuBalai, int KiekisStudentu);
void meniu(std::vector<Student>& studentai, std::vector<std::vector<int>>& NamuDarbuBalai, int& KiekisStudentu);
void duomenys_is_failo(std::vector<Student>& studentai, std::vector<std::vector<int>>& NamuDarbuBalai, int& KiekisStudentu);
void atsitiktiniai_pazymiai(std::vector<Student>& studentai, std::vector<std::vector<int>>& NamuDarbuBalai, int KiekisStudentu);
void rezultatas(const std::vector<Student>& studentai);
void kategorijos(const std::vector<Student>& studentai, std::vector<Student>& NeTokieProtingi, std::vector<Student>& protingi);

#endif