#include "funkcijos.h"
#include "studentasvector.h"

using namespace std;

int main()
{
    vector <Studentas> A;

    A.reserve(1000000);

    char yn;
    cout << "Ar norite nuskaityti duomenis is failo? Y/N" << endl;
    cin >> yn;

    if (yn == 'Y' || yn == 'y') fileInput(A);
    else input(A);

    A.shrink_to_fit();

    for (int i=0; i < A.size(); i++)
    {
        A[i].SkaiciuotiVid();
        A[i].SkaiciuotiMed();
    }

    output(A);
}