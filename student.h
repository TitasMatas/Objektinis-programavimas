#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string vardas;
    std::string pavarde;
    double galutinisVid;
    double galutinisMed;

    Student() : vardas(""), pavarde(""), galutinisVid(0), galutinisMed(0) {}
    Student(std::string v, std::string p, double gv, double gm)
        : vardas(v), pavarde(p), galutinisVid(gv), galutinisMed(gm) {}
};

#endif