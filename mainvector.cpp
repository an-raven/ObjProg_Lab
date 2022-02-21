#include <iostream>
#include <iomanip>
#include "studentasvector.h"

using namespace std;

void output(vector<Studentas> A)
{
    cout << left <<setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid)" << setw(15) << "Galutinis (med)" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i=0; i < A.size(); i++)
        cout << left <<setw(15) <<A[i].vardas << setw(15) << A[i].pavarde << setw(15) << setprecision(3)
            << A[i].GalutinisPaz(A[i].vid) << setw(15) << setprecision(3) << A[i].GalutinisPaz(A[i].med) << endl;
}
void input(vector<Studentas>& A)
{   
    for (int i=0; i<A.size(); i++)
    {
        string v, p;
        int egz, pazymys;
        int sk=0, brk;

        int masyvas[100];

        cout << "Iveskite studento varda" << endl;
        cin >> v;
        cout << "Iveskite studento pavarde" << endl;
        cin >> p;

        cout << "Iveskite studento namu darbu pazymius" << endl;
        cout << "Irasykite -1 jeigu jau baigete" << endl;

        while (1)
        {
            while (!(cin >> pazymys))
            {
                cout << "Blogai ivestas skaicius, iveskite dar karta" << endl;
                cin.clear();
                cin.ignore();
            }
            if (pazymys==-1) break;
            else if (pazymys>10 || pazymys<-1)
            { 
                cout << "Pazymys ivestas neteisingai" << endl;
                continue;
            }
            masyvas[sk]=pazymys;
            sk++;
        }

        cout << "Iveskite studento egzamino rezultata" << endl;
        while (!(cin >> egz))
            {
                cout << "Blogai ivestas skaicius, iveskite dar karta" << endl;
                cin.clear();
                cin.ignore();
            }
        while (egz >10 || egz<0)
        {
            cout << "Blogai ivestas egzamino rezultatas, iveskite dar karta" << endl;
            cin >> egz;
        }

        A[i].vardas = v;
        A[i].pavarde = p;
        A[i].egz= egz;
        A[i].nd.resize(sk);
        for(int j=0; j < A[i].nd.size() ; j++)
            A[i].nd[j]= (masyvas[j]);
    }
}

int main()
{
    string yn;
    vector <Studentas> A;
    int n;
    cout << "Iveskite studentu skaiciu" << endl;
    cin >> n;
    A.resize(n);
    cout << A.size() << endl;
    input(A);

    for (int i=0; i < A.size(); i++)
    {
        A[i].SkaiciuotiVid();
        A[i].SkaiciuotiMed();
    }
    output(A);
}