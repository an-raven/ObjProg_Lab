#ifndef STUDENTASVECTOR_H
#define STUDENTASVECTOR_H
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ostream>
#define inputfile "studentai.txt"

class Studentas
{ 
    private:

    std::string vardas, pavarde;
    double egz;
    std::vector <int> nd;

    public:

    Studentas();
    Studentas(std::string _vardas, std::string _pavarde, std::vector<int> _nd, int _egz);
    ~Studentas();

    std::string getFirstName() const {return vardas;}
    std::string getLastNAme() const {return pavarde;}

    double getMedian();
    double getAverage();
    double getFinal();

    void input();

    void output(bool borders);
    void fileOutput(std::string outputFile, bool borders);

    bool operator < (const Studentas& str) const;
};

#endif