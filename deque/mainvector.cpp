#include "funkcijos.h"
#include "studentasvector.h"
#include <chrono>

using namespace std;

void split2Two(deque<Studentas>& A, deque<Studentas>& B)
{
    sort(A.begin(), A.end(), [](const Studentas& lhs, const Studentas& rhs)
    {
        return lhs.gal > rhs.gal;
    });

    while (A.back().gal < 5)
    {
        B.push_back(A.back());
        A.pop_back();
    }
}

int main(int argc, const char* argv[])
{
    srand(time(0));
    deque <Studentas> A;
    deque <Studentas> B;
    double visasLaikas=0;

    char yn;
    int sk;
    cout << "Ar norite sugeneruoti faila? Y/N" << endl;
    cin >> yn;

    if(yn == 'Y' || yn == 'y')
    {
        {
        auto start = chrono::high_resolution_clock::now();
        if(argc <= 1)
        {
            cout << "Kiek norite sugeneruoti?" << endl;
            cin >> sk;
            randomGen(sk);
        }
        else
        randomGen(stoi(argv[1]));

        auto finish = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = finish - start;
        cout << "Sugeneravimas: " << elapsed.count() << " s" << endl;
        visasLaikas+=elapsed.count();
        }

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

    A.shrink_to_fit();
    B.shrink_to_fit();

    fileOutput(A, "islaike.txt");
    fileOutput(B, "neislaike.txt");
}