#include "studentascarray.h"

Studentas::Studentas(){}
Studentas::~Studentas()
{
    delete[] nd;
}

void Studentas::SukurtiMasyva()
{
    nd= new int[ndSk];
}

void Studentas::SkaiciuotiVid()
{
    int sum=0;
        for (int i=0; i <ndSk; i++)
        {
            sum+=nd[i];
        }
        if (ndSk!=0) vid= (sum/(double)ndSk);
        else vid=0;
}
void Studentas::SkaiciuotiMed()
{
    std::sort(nd, nd+ndSk);
    if (ndSk==0) med=0;
    else if (ndSk % 2 !=0)
        med = (double)nd[ndSk/2];
    else med= (double)( nd[(ndSk-1) / 2] + nd[ndSk / 2] ) / 2.0;
}
double Studentas::GalutinisPaz(double a)
{
    return a*0.4 + egz*0.6;
}