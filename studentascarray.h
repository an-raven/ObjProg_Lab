#ifndef STUDENTASCARRAY_H
#define STUDENTASCARRAY_H
#include <string>
#include <algorithm>

class Studentas
{
    public: 
    std::string vardas, pavarde;
    double vid, egz, med;
    int ndSk;
    int *nd;

    Studentas();
    ~Studentas();

    void SukurtiMasyva();
    void SkaiciuotiVid();
    void SkaiciuotiMed();
    double GalutinisPaz(double a);
};

#endif