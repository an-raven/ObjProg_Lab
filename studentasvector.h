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

class Person
{
protected:
    std::string vardas, pavarde;
public:
    explicit Person()
    {
        vardas="";
        pavarde="";
    }
    explicit Person(const std::string &_vardas, const std::string& _pavarde)
    {
        vardas= _vardas;
        pavarde= _pavarde;
    }

    virtual const std::string &getFirstName() const=0;
    virtual const std::string &getLastName() const=0;

};

class Studentas : public Person
{ 
    private:

    double egz;
    std::vector <int> nd;

    public:
    Studentas(): egz(0){}

    ~Studentas();
    Studentas(const Studentas& stud);
    Studentas&operator=(const Studentas& stud);
    Studentas(std::string vardas, std::string pavarde, std::vector<int> _nd, int _egz);


    const std::string &getFirstName() const override;
    const std::string &getLastName() const override;

    double getMedian();
    double getAverage();
    double getFinal();

    void input();

    void output(bool borders);
    void fileOutput(std::string outputFile, bool borders);

    bool operator < (const Studentas& str) const;
};

#endif