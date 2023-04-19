#pragma once
#include <string>
#include <vector>

std ::vector<std ::string> dataFromFile(std ::string path);
void StrChek(std ::string str, double prmtrs[]);
double perimter(double r);
double area(double r);
int intersect(double** prmtrs, int i, int j);
int IsFingCircle(std ::string str, unsigned int& i);
int IsFingLeftBracket(std ::string str, unsigned int& i);
int IsFingFirstDigit1(std ::string str, unsigned int& i, std ::string& point1);
int IsFingSecDigit2(std ::string str, unsigned int& i, std ::string& point2);
int IsFingLeftComma(std ::string str, unsigned int& i);
int IsFingLeftDigit3(std ::string str, unsigned int& i, std ::string& radius);
int IsFingRightBracket(std ::string str, unsigned int& i);
int UnexToken(std ::string str, unsigned int& i);
