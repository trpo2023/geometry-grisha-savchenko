#include <fstream>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

vector<string>
dataFromFile(string path) // записываем данные из файла в массив строк
{
  string line = "";
  int index = 0;
  int dataSize = 0;

  ifstream checkLines(path);
  if (checkLines.is_open()) {
    while (getline(checkLines, line))
      dataSize++;
  } else
    cout << "Файл не удалось открыть" << endl;
  checkLines.close();

  line = "";
  vector<string> data(dataSize);

  ifstream in(path);
  if (in.is_open()) {
    while (getline(in, line)) {
      data[index] = line;
      index++;
    }
  } else
    cout << "Файл не удалось открыть" << endl;
  in.close();
  return data;
}

int SpaceSkeeper(string str, int i) {
  if (str[i] != ' ')
    return i;
  return SpaceSkeeper(str, ++i);
}

int Skeeper(string str, int i) {
  if (str[i] == ' ')
    return i;
  return Skeeper(str, ++i);
}

void StrChek(string str, double prmtrs[]) {
  int dotc = 0; unsigned int i = 0;

  string point1 = "";
  string point2 = "";
  string radius = "";

  i = SpaceSkeeper(str, i);

  if (str.find("circle", i) != i) {
    cout << "Error at column " << i << ": expected 'circle'" << endl;
    return;
  } else {
    string cstr = "circle";
    i += cstr.size();
  }

  if ((str[i] != ' ') && (str[i] != '('))
    cout << "Error at column " << i << ": expected 'circle'" << endl;

  i = SpaceSkeeper(str, i);
  if (str[i] != '(') {
    cout << "Error at column " << i << ": expected '('" << endl;
    return;
  }
  i += 1;

  string digit = "1234567890.";

  do {
    if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
      cout << "Error at column " << i << ": expected 'double'" << endl;
      return;
    }
    if (str[i] == '.') {
      dotc++;
      if (dotc > 2)
        cout << "Error at column " << i << ": expected 'double'" << endl;
      ;
    }
    point1.append(str, i, 1);
    i++;
    if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
      cout << "Error at column " << i << ": expected 'double'" << endl;
      return;
    }
  } while (isdigit(str[i]) || (str[i] == '.'));
  cout << point1 << endl;
  dotc = 0;
  i++;

  do {
    if ((isdigit(str[i]) == 0) && (str[i] != '.') && ((str[i] != ','))) {
      cout << "Error at column " << i << ": expected 'double'" << endl;
      return;
    }
    if (str[i] == '.') {
      dotc++;
      if (dotc > 2)
        cout << "Error at column " << i << ": expected 'double'" << endl;
      ;
    }
    point2.append(str, i, 1);
    i++;
    if ((isdigit(str[i]) == 0) && (str[i] != '.') && ((str[i] != ','))) {
      cout << "Error at column " << i << ": expected 'double'" << endl;
      return;
    }
  } while (isdigit(str[i]) || (str[i] == '.'));
  cout << point2 << endl;
  dotc = 0;

  if (str[i] != ',') {
    cout << "Error at column " << i << ": expected ','" << endl;
    return;
  }
  i++;
  if (str[i] == ' ')
    i++;

  if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ' ')) {
    cout << "Error at column " << i << ": expected 'double'" << endl;
    return;
  }
  do {
    if (str[i] == '.') {
      dotc++;
      if (dotc > 2)
        cout << "Error at column " << i << ": expected 'double'" << endl;
      ;
    }
    radius.append(str, i, 1);
    if ((isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != ')')) {
      cout << "Error at column " << i << ": expected 'double'" << endl;
      return;
    }
    i++;
  } while ((isdigit(str[i]) || (str[i] == '.') || (i < str.length())) &&
           str[i] != ')');
  cout << radius << endl;

  if (str.find(")", i) != i) {
    cout << "Error at column " << i << ": expected ')'" << endl;
    return;
  }
  i += 1;
  SpaceSkeeper(str, i);

  while (i < str.size()) {
    if (str[i] != ' ') {
      cout << "Error at column " << i << ": unexpecteble token" << endl;
      return;
    }
    i++;
  }
  prmtrs[0] = stod(point1);
  prmtrs[1] = stod(point2);
  prmtrs[2] = stod(radius);
  return;
}

double perimter(double r) { return 2 * r * 3.14; }

double area(double r) { return r * r * 3.14; }

double intersect(double **prmtrs, int i, int j) {
  int verdict = 0;
  if (sqrt(pow((prmtrs[i][0] - prmtrs[j][0]), 2) +
           pow((prmtrs[i][1] - prmtrs[j][1]), 2)) >
      (prmtrs[i][2] + prmtrs[j][2])) {
    verdict = 1;
  }

  return verdict;
}
