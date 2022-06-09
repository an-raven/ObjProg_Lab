#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#define inputfile "studentai.txt"

#include "studentasvector.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void output(std::vector<Studentas> A);
void input(std::vector<Studentas>& A);
void fileInput(std::vector<Studentas>& A);
void fileOutput(std::vector<Studentas>& A, std::string outputFile);

int randomNum(int min, int max);
void randomGen(int n);

#endif