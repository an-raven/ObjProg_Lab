#ifndef STUDENTASVECTOR_H
#define STUDENTASVECTOR_H
#include <string>
#include <algorithm>
#include <vector>

struct Studentas
{ 
    std::string vardas, pavarde;
    double vid, egz, med;
    std::vector <int> nd;

    Studentas();
    Studentas(std::string _vardas, std::string _pavarde, std::vector<int> _nd, int _egz);
    ~Studentas();

    void SkaiciuotiVid();
    void SkaiciuotiMed();
    double GalutinisPaz(double a);
    bool operator < (const Studentas& str) const;
};

#endif