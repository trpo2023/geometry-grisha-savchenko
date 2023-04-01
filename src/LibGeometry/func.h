#pragma once
#include <fstream>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

vector<string> dataFromFile(string path);
int SpaceSkeeper(string str, int i);
int Skeeper(string str, int i);
void StrChek(string str, double prmtrs[]);
double perimter(double r);
double area(double r);
double intersect(double **prmtrs, int i, int j);
