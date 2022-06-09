#include "funkcijos.h"

using namespace std;

void output(vector<Studentas> A)
{
    sort(A.begin(), A.end());
    cout << left <<setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid)" << setw(15) << "Galutinis (med)" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (Studentas out: A)
    {
        out.output(false);
    }
}
void input(vector<Studentas>& A)
{   
    char stop;
    Studentas temp;

    while(1)
    {
        temp.input();
        A.push_back(temp);
        cout << "Jei norite prideti daugiau studentu? (Y/N)" << endl;
        cin >> stop;
        if (stop == 'Y' || stop=='y') continue;
        else break;
    }
}
void fileInput(vector<Studentas>& A)
{
    fstream input;
    input.open(inputfile, ios::in);

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
            if (tVardas[0] == '\0') continue;
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
void fileOutput(vector<Studentas>& A, string outputFile)
{
    std::fstream output;
    output.open(outputFile, std::ios::out);

    output << left <<setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid)" << setw(15) << "Galutinis (med)" << endl;
    output << "---------------------------------------------------------------------" << endl;

    for (Studentas in: A)
    {
        in.fileOutput(outputFile, false);
    }

    output.close();
}
int randomNum(int min, int max)
{
    return min + rand() % ( (max + 1) - min);
}
void randomGen(int n)
{
    fstream output;
    output.open("studentai.txt", ios::out);

    int pazSk= randomNum(5, 15);

    output << "Vardas " << "Pavarde ";
    for (int i=1; i <= pazSk; i++)
        output << "ND" + to_string(i) << " ";
    output << "Egz" << endl;

    for (int i=1; i <= n; i++)
    {
        output << "Vardas" + to_string(i) << " " << "Pavarde" + to_string(i) << " ";
        for (int j=0; j<pazSk; j++)
        {
            output << randomNum(1, 10) << " ";
        }
        output << randomNum(1, 10) << endl;
    }

    output.close();
}