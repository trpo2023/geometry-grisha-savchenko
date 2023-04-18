#include <fstream>
#include <func.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

std ::vector<std ::string>
dataFromFile(std ::string path) // записываем данные из файла в массив строк
{
    std ::string line = "";
    int index = 0;
    int dataSize = 0;

    std ::ifstream checkLines(path);
    if (checkLines.is_open()) {
        while (getline(checkLines, line))
            dataSize++;
    } else
        std ::cout << "Файл не удалось открыть" << std ::endl;
    checkLines.close();

    line = "";
    std ::vector<std ::string> data(dataSize);

    std ::ifstream in(path);
    if (in.is_open()) {
        while (getline(in, line)) {
            data[index] = line;
            index++;
        }
    } else
        std ::cout << "Файл не удалось открыть" << std ::endl;
    in.close();
    return data;
}

int SpaceSkeeper(std ::string str, int i)
{
    if (str[i] != ' ')
        return i;
    return SpaceSkeeper(str, ++i);
}

int Skeeper(std ::string str, int i)
{
    if (str[i] == ' ')
        return i;
    return Skeeper(str, ++i);
}

int IsFingCircle(std ::string str, unsigned int& i)
{
    if (str.find("circle", i) != i) {
        std ::cout << "Error at column " << i << ": expected 'circle'"
                   << std ::endl;
        return -1;
    } else {
        std ::string cstr = "circle";
        i += cstr.size();
        return 0;
    }
}

int IsFingLeftBracket(std ::string str, unsigned int& i)
{
    if (str[i] != '(') {
        std ::cout << "Error at column " << i << ": ('" << std ::endl;
        return -1;
    }
    return 0;
}

int IsFingFirstDigit1(std ::string str, unsigned int& i, std ::string& point1)
{
    int dotc = 0;
    do {
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return -1;
        }
        if (str[i] == '.') {
            dotc++;
            if (dotc > 2)
                std ::cout << "Error at column " << i << ": expected 'double'"
                           << std ::endl;
        }
        point1.append(str, i, 1);
        i++;
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return -1;
        }
    } while (isdigit(str[i]) || (str[i] == '.'));
    std ::cout << point1 << std ::endl;
    return 0;
}

int IsFingSecDigit2(std ::string str, unsigned int& i, std ::string& point2)
{
    int dotc = 0;
    do {
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && ((str[i] != ','))) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return -1;
        }
        if (str[i] == '.') {
            dotc++;
            if (dotc > 2)
                std ::cout << "Error at column " << i << ": expected 'double'"
                           << std ::endl;
            ;
        }
        point2.append(str, i, 1);
        i++;
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && ((str[i] != ','))) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return -1;
        }
    } while (isdigit(str[i]) || (str[i] == '.'));
    std ::cout << point2 << std ::endl;
    return 0;
}

int IsFingLeftComma(std ::string str, unsigned int& i)
{
    if (str[i] != ',') {
        std ::cout << "Error at column " << i << ": expected ','" << std ::endl;
        return -1;
    }
    return 0;
}

int IsFingLeftDigit3(std ::string str, unsigned int& i, std ::string& radius)
{
    int dotc = 0;
    if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
        std ::cout << "Error at column " << i << ": expected 'double'"
                   << std ::endl;
        return -1;
    }
    do {
        if (str[i] == '.') {
            dotc++;
            if (dotc > 2)
                std ::cout << "Error at column " << i << ": expected 'double'"
                           << std ::endl;
            ;
        }
        radius.append(str, i, 1);
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ')')) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return -1;
        }
        i++;
    } while ((isdigit(str[i]) || (str[i] == '.') || (i < str.length()))
             && str[i] != ')');
    std ::cout << radius << std ::endl;
    return 0;
}

int IsFingRightBracket(std ::string str, unsigned int& i)
{
    if (str.find(")", i) != i) {
        std ::cout << "Error at column " << i << ": expected ')'" << std ::endl;
        return -1;
    }
    return 0;
}

int UnexToken(std ::string str, unsigned int& i)
{
    while (i < str.size()) {
        if (str[i] != ' ') {
            std ::cout << "Error at column " << i << ": unexpecteble token"
                       << std ::endl;
            return -1;
        }
        i++;
    }
    return 0;
}

void StrChek(std ::string str, double prmtrs[])
{
    unsigned int i = 0;

    std ::string point1 = "";
    std ::string point2 = "";
    std ::string radius = "";

    i = SpaceSkeeper(str, i);

    IsFingCircle(str, i);

    i = SpaceSkeeper(str, i);

    IsFingLeftBracket(str, i);

    i += 1;

    IsFingFirstDigit1(str, i, point1);

    i++;

    IsFingSecDigit2(str, i, point2);

    IsFingLeftComma(str, i);
    i++;
    if (str[i] == ' ')
        i++;

    IsFingLeftDigit3(str, i, radius);

    IsFingRightBracket(str, i);
    i += 1;
    SpaceSkeeper(str, i);

    UnexToken(str, i);
    prmtrs[0] = stod(point1);
    prmtrs[1] = stod(point2);
    prmtrs[2] = stod(radius);
    return;
}

double perimter(double r)
{
    return 2 * r * 3.14;
}

double area(double r)
{
    return r * r * 3.14;
}

int intersect(double** prmtrs, int i, int j)
{
    int verdict = 1;
    if (sqrt(pow((prmtrs[i][0] - prmtrs[j][0]), 2)
             + pow((prmtrs[i][1] - prmtrs[j][1]), 2))
        > (prmtrs[i][2] + prmtrs[j][2])) {
        verdict = 0;
    }

    return verdict;
}
