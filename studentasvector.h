#ifndef STUDENTASVECTOR_H
#define STUDENTASVECTOR_H
#include <string>
#include <algorithm>
#include <vector>

class Studentas
{
    public: 
    std::string vardas, pavarde;
    double vid, egz, med;
    std::vector <int> nd;

    Studentas();
    ~Studentas();

    void SkaiciuotiVid();
    void SkaiciuotiMed();
    double GalutinisPaz(double a);
};

#endif