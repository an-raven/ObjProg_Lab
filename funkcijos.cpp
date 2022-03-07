#include "funkcijos.h"

using namespace std;

void output(vector<Studentas> A)
{
    sort(A.begin(), A.end());

    cout << left <<setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid)" << setw(15) << "Galutinis (med)" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i=0; i < A.size(); i++)
        cout << left <<setw(15) <<A[i].vardas << setw(15) << A[i].pavarde << setw(15) << setprecision(3)
            << A[i].GalutinisPaz(A[i].vid) << setw(15) << setprecision(3) << A[i].GalutinisPaz(A[i].med) << endl;
}
void input(vector<Studentas>& A)
{   
    char stop;

    while(1)
    {
        string v, p;
        int egz, pazymys;
        vector<int> tNd;

        tNd.reserve(30);

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
            tNd.push_back(pazymys);
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

        A.push_back(Studentas(v, p, tNd, egz));

        cout << "Jei norite prideti daugiau studentu? (Y/N)" << endl;
        cin >> stop;
        if (stop == 'Y' || stop=='y') continue;
        else break;
    }
}
void fileInput(vector<Studentas>& A)
{
    fstream input;
    input.open("kursiokai.txt", ios::in);

    if (!input) std::cerr << "Nepavyko atidaryti failo" << endl;

    else
    {
        string temp;
        input >> temp >> temp;
    
        int counter=0;
        input >> temp;

        while (temp[0] == 'N')
        {
            input >> temp;
            counter++;
        }

        while(!input.eof())
        {
            string tVardas, tPav;
            int tEgz;
            vector <int> tNd;
            tNd.reserve(counter);

            input >> tVardas >> tPav;
            for(int i=0; i < counter; i++)
            {
                int temp;
                input >> temp;
                tNd.push_back(temp);
            }
            input >> tEgz;

            A.push_back(Studentas(tVardas, tPav, tNd, tEgz));
        }

    input.close();
    }
}