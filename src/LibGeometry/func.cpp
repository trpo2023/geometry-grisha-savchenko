#include <LibGeometry/func.h>
#include <fstream>
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

void StrChek(std ::string str, double prmtrs[])
{
    int dotc = 0;
    unsigned int i = 0;

    std ::string point1 = "";
    std ::string point2 = "";
    std ::string radius = "";

    i = SpaceSkeeper(str, i);

    if (str.find("circle", i) != i) {
        std ::cout << "Error at column " << i << ": expected 'circle'"
                   << std ::endl;
        return;
    } else {
        std ::string cstr = "circle";
        i += cstr.size();
    }

    if ((str[i] != ' ') && (str[i] != '('))
        std ::cout << "Error at column " << i << ": expected 'circle'"
                   << std ::endl;

    i = SpaceSkeeper(str, i);
    if (str[i] != '(') {
        std ::cout << "Error at column " << i << ": expected '('" << std ::endl;
        return;
    }
    i += 1;

    std ::string digit = "1234567890.";

    do {
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return;
        }
        if (str[i] == '.') {
            dotc++;
            if (dotc > 2)
                std ::cout << "Error at column " << i << ": expected 'double'"
                           << std ::endl;
            ;
        }
        point1.append(str, i, 1);
        i++;
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return;
        }
    } while (isdigit(str[i]) || (str[i] == '.'));
    std ::cout << point1 << std ::endl;
    dotc = 0;
    i++;

    do {
        if ((isdigit(str[i]) == 0) && (str[i] != '.') && ((str[i] != ','))) {
            std ::cout << "Error at column " << i << ": expected 'double'"
                       << std ::endl;
            return;
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
            return;
        }
    } while (isdigit(str[i]) || (str[i] == '.'));
    std ::cout << point2 << std ::endl;
    dotc = 0;

    if (str[i] != ',') {
        std ::cout << "Error at column " << i << ": expected ','" << std ::endl;
        return;
    }
    i++;
    if (str[i] == ' ')
        i++;

    if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
        std ::cout << "Error at column " << i << ": expected 'double'"
                   << std ::endl;
        return;
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
            return;
        }
        i++;
    } while ((isdigit(str[i]) || (str[i] == '.') || (i < str.length()))
             && str[i] != ')');
    std ::cout << radius << std ::endl;

    if (str.find(")", i) != i) {
        std ::cout << "Error at column " << i << ": expected ')'" << std ::endl;
        return;
    }
    i += 1;
    SpaceSkeeper(str, i);

    while (i < str.size()) {
        if (str[i] != ' ') {
            std ::cout << "Error at column " << i << ": unexpecteble token"
                       << std ::endl;
            return;
        }
        i++;
    }
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

double intersect(double** prmtrs, int i, int j)
{
    int verdict = 0;
    if (sqrt(pow((prmtrs[i][0] - prmtrs[j][0]), 2)
             + pow((prmtrs[i][1] - prmtrs[j][1]), 2))
        > (prmtrs[i][2] + prmtrs[j][2])) {
        verdict = 1;
    }

    return verdict;
}
