#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "student.h"
#include <list>

bool operator<(const Student& a, const Student& b);

double mediana(std::list<int>& balai);
double skaiciuoti_galutini(Student& s, std::list<int>& balai);
void ivedimas(std::list<Student>& studentai, std::list<std::list<int>>& NamuDarbuBalai, int KiekisStudentu);
void duomenys_is_failo(std::list<Student>& studentai, std::list<std::list<int>>& NamuDarbuBalai, int& KiekisStudentu, const std::string& failoVardas);
void atsitiktiniai_pazymiai(std::list<Student>& studentai, std::list<std::list<int>>& NamuDarbuBalai, int KiekisStudentu);
void rezultatas(const std::list<Student>& studentai);
void kategorijos(const std::list<Student>& studentai, std::list<Student>& NeTokieProtingi, std::list<Student>& protingi);

#endif