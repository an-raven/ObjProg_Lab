#ifndef STUDENTASVECTOR_H
#define STUDENTASVECTOR_H
#include "person.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ostream>
#define inputfile "studentai.txt"

class Studentas : public Person
{ 
    private:

    double egz;
    std::vector <int> nd;

    public:

    std::string getFirstName() const {return vardas;};
    std::string getLastNAme() const {return pavarde;};
    virtual std::string addNames() {return vardas + pavarde;};

    Studentas();
    Studentas(const Studentas& stud);
    Studentas&operator=(Studentas& rhs);
    //Studentas(std::string _vardas, std::string _pavarde, std::vector<int> _nd, int _egz);
    Studentas(std::string vardas, std::string pavarde, std::vector<int> _nd, int _egz);
    
    ~Studentas();

    double getMedian();
    double getAverage();
    double getFinal();

    void input();

    void output(bool borders);
    void fileOutput(std::string outputFile, bool borders);

    bool operator < (const Studentas& str) const;
};

#endif