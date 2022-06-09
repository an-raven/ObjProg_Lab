#include "funkcijos.h"
#include "studentasvector.h"
#include <chrono>

using namespace std;

void split2Two(list<Studentas>& A, list<Studentas>& B)
{
    A.sort();

    while (A.back().gal < 5)
    {
        B.push_back(A.back());
        A.pop_back();
    }
}
void split2Two2(list<Studentas>& A, list<Studentas>& B)
{
    for (auto const &it: A)
        if(it.gal >=5) B.push_back(it);

    A.erase(remove_if(A.begin(), A.end(), [](Studentas& a)
    {
        return a.gal < 5;
    }), A.end());
}

void split2Two(list<Studentas>& A, list<Studentas>& B, list<Studentas>& C)
{
    for (auto const &it : A)
    {
        if (it.gal >= 5) B.push_back(it);
        else C.push_back(it);
    }
}

int main(int argc, const char* argv[])
{
    srand(time(0));
    list <Studentas> A;
    list <Studentas> B;
    double visasLaikas=0;

    char yn;
    int sk;
    cout << "Ar norite sugeneruoti faila? Y/N" << endl;
    cin >> yn;

    if(yn == 'Y' || yn == 'y')
    {

        if(argc <= 1)
        {
            cout << "Kiek norite sugeneruoti?" << endl;
            cin >> sk;
            randomGen(sk);
        }
        else
        randomGen(stoi(argv[1]));

        {
        auto start = chrono::high_resolution_clock::now();
        fileInput(A);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Duomenu nuskaitymas: " << elapsed.count() << "s" << endl;
        visasLaikas+=elapsed.count();
        }

    }
    else
    {
        auto start = chrono::high_resolution_clock::now();
        fileInput(A);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Duomenu nuskaitymas: " << elapsed.count() << "s" << endl;
        visasLaikas+=elapsed.count();
    }

    for (auto & i: A)
    {
        i.SkaiciuotiVid();
        i.GalutinisPaz();
        i.SkaiciuotiMed();
    }

    list <Studentas> C;

    {
        auto start = chrono::high_resolution_clock::now();
        split2Two(A, B, C);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Padalijimas i dvi grupes: " << elapsed.count() << "s" << endl;
        visasLaikas+=elapsed.count();
    }

    fileOutput(A, "islaike.txt");
    fileOutput(B, "neislaike.txt");
}