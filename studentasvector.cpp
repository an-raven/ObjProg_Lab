#include "studentasvector.h"

Studentas::Studentas(const Studentas& stud)
{
    vardas = stud.vardas;
    pavarde = stud.pavarde;
    egz = stud.egz;
    nd= stud.nd;
}
Studentas&Studentas::operator=(const Studentas& stud)
{
    if (&stud == this) return *this;

    vardas= stud.vardas;
    pavarde= stud.pavarde;
    egz= stud.egz;
    nd= stud.nd;

    return *this;
}

Studentas::Studentas(std::string vardas, std::string pavarde, std::vector<int> _nd, int _egz): Person(vardas, pavarde), nd(_nd), egz(_egz) {};

Studentas::~Studentas()= default;

const std::string &Studentas::getFirstName() const {return vardas;}
const std::string &Studentas::getLastName() const {return pavarde;}

double Studentas::getAverage()
{
    int sum=0;
    for (int i=0; i < nd.size(); i++)
    {
        sum+=nd[i];
    }
    if (nd.size()!=0) return (sum/(double)nd.size());
    else return 0;
}
double Studentas::getMedian()
{
    std::sort(nd.begin(), nd.end());
    if (nd.size()==0) return 0;
    else if (nd.size() % 2 !=0)
        return (double)nd[nd.size()/2];
    else return (double)( nd[(nd.size()-1) / 2] + nd[nd.size() / 2] ) / 2.0;

}
double Studentas::getFinal()
{
    return getAverage()*0.4 + egz*0.6;
}

void Studentas::input()
{
    char stop;

        while(1)
        {
            std::string v, p;
            int egzaminas, pazymys;
            nd.reserve(30);

            std::cout << "Iveskite studento varda" << std::endl;
            std::cin >> v;
            vardas = v;
            std::cout << "Iveskite studento pavarde" << std::endl;
            std::cin >> p;
            p = pavarde;

            std::cout << "Iveskite studento namu darbu pazymius" << std::endl;
            std::cout << "Irasykite -1 jeigu jau baigete" << std::endl;

            while (1)
            {
                while (!(std::cin >> pazymys))
                {
                    std::cout << "Blogai ivestas skaicius, iveskite dar karta" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
                if (pazymys==-1) break;
                else if (pazymys>10 || pazymys<-1)
                { 
                    std::cout << "Pazymys ivestas neteisingai" << std::endl;
                    continue;
                }
                nd.push_back(pazymys);
            }

            std::cout << "Iveskite studento egzamino rezultata" << std::endl;
            while (!(std::cin >> egzaminas))
                {
                    std::cout << "Blogai ivestas skaicius, iveskite dar karta" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
            while (egzaminas >10 || egzaminas<0)
            {
                std::cout << "Blogai ivestas egzamino rezultatas, iveskite dar karta" << std::endl;
                std::cin >> egzaminas;
                egz= egzaminas;
            }

            std::cout << "Jei norite prideti daugiau studentu? (Y/N)" << std::endl;
            std::cin >> stop;
            if (stop == 'Y' || stop=='y') continue;
            else break;
        }
}

void Studentas::output(bool borders)
{
    if (borders)
    {
        std::cout << std::left <<std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15) << "Galutinis (vid)" << std::setw(15) << "Galutinis (med)" << std::endl;
        std::cout << "---------------------------------------------------------------------" << std::endl;
    }
    else std::cout << std::left << std::setw(15) << vardas << std::setw(15) << pavarde << std::setw(15) << std::setprecision(3) << getFinal() << std::endl;
}
void Studentas::fileOutput(std::string outputFile, bool borders)
{
    std::fstream output;
    output.open(outputFile, std::ios::app);

    if (borders)
    {
        output << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15) << "Galutinis (vid)" << std::setw(15) << "Galutinis (med)" << std::endl;
        output << "---------------------------------------------------------------------" << std::endl;
    }
    else output << std::left << std::setw(15) << vardas << std::setw(15) << pavarde << std::setw(15) << std::setprecision(3) << getFinal() << std::endl;

    output.close();
}

bool Studentas::operator < (const Studentas& str) const
{
    return (vardas < str.vardas);
}