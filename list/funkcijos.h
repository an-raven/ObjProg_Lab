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

void output(std::list<Studentas> A);
void input(std::list<Studentas>& A);
void fileInput(std::list<Studentas>& A);
void fileOutput(std::list<Studentas>& A, std::string outputFile);
int randomNum(int min, int max);
void randomGen(int n);

#endif