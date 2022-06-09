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

void output(std::deque<Studentas> A);
void input(std::deque<Studentas>& A);
void fileInput(std::deque<Studentas>& A);
void fileOutput(std::deque<Studentas>& A, std::string outputFile);
int randomNum(int min, int max);
void randomGen(int n);

#endif