#include "funkcijos.h"
#include "studentasvector.h"
#include <chrono>

using namespace std;

void split2Two(vector<Studentas>& A, vector<Studentas>& B)
{
    sort(A.begin(), A.end(), [](const Studentas& lhs, const Studentas& rhs)
    {
        return lhs.gal > rhs.gal;
    });

    while (A.back().gal < 5)
    {
        B.push_back(A.back());
        A.erase(A.end());
    }
}

int main()
{
    srand(time(0));
    vector <Studentas> A;
    vector <Studentas> B;
    A.reserve(10000000);
    double visasLaikas=0;

    {
    auto start = chrono::high_resolution_clock::now();
    randomGen(10000000);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Sugeneravimas: " << elapsed.count() << " s" << endl;
    visasLaikas+=elapsed.count();
    }

    /*char yn;
    cout << "Ar norite nuskaityti duomenis is failo? Y/N" << endl;
    cin >> yn;*/

    //if (yn == 'Y' || yn == 'y')
    //{
        {
        auto start = chrono::high_resolution_clock::now();
        fileInput(A);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Duomenu nuskaitymas: " << elapsed.count() << "s" << endl;
        visasLaikas+=elapsed.count();
        }
    //} 
    //else input(A);

    A.shrink_to_fit();

    for (int i=0; i < A.size(); i++)
    {
        A[i].SkaiciuotiVid();
        A[i].GalutinisPaz();
        A[i].SkaiciuotiMed();
    }

    for (int i=0; i < A.size(); i++)
    {
        A[i].nd.clear();
        A[i].nd.shrink_to_fit();
    }

    {
        auto start = chrono::high_resolution_clock::now();
        split2Two(A, B);
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Padalijimas i dvi grupes: " << elapsed.count() << "s" << endl;
        visasLaikas+=elapsed.count();
    }
    system("pause");
    A.shrink_to_fit();
    B.shrink_to_fit();

    {
        auto start = chrono::high_resolution_clock::now();
        fileOutput(A, "pirma grupe.txt");
        fileOutput(B, "antra grupe.txt");
        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Irasyti abu failus: " << elapsed.count() << "s" << endl;
        visasLaikas+=elapsed.count();
    }

    cout << "Programa uztruko: " << visasLaikas << "s" << endl;
}