#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
protected:
    std::string vardas, pavarde;
public:
    Person();
    Person(std::string, std::string);
    ~Person
();
    std::string getFirstName();
    std::string getLastName();
    virtual std::string addNames()=0;

};

#endif