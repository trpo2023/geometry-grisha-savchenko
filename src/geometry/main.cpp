#include <LibGeometry/func.h>


using namespace std;

int main() {
  string path = "test";
  vector<string> str = dataFromFile(path); // вектор строк из файла
  int k = str.size();
  double **prmtrs;
  prmtrs = (double **)calloc(k, sizeof(double *));
  for (int i = 0; i < k; i++)
    prmtrs[i] = (double *)calloc(3, sizeof(double));

  for (int i = 0; i < k; i++) {
    StrChek(str[i], prmtrs[i]);
    for (int j = 0; j < 3; j++)
      cout << prmtrs[i][j] << " ";
    cout << endl;
  }

  for (string s : str)
    cout << s << endl;
  /////////////////////////////////////////////////////////////////////
  for (int i = 0; i < k; i++) {
    if ((prmtrs[i][0] != 0) && (prmtrs[i][1] != 0) && (prmtrs[i][2] != 0)) {
      cout << "perimeter =" << perimter(prmtrs[i][2]) << endl;
      cout << "area =" << area(prmtrs[i][2]) << endl;
      cout << "intersects:" << endl;
      for (int j = 0; j < k; j++) {
        if ((prmtrs[i][0] != 0) && (prmtrs[i][1] != 0) && (prmtrs[i][2] != 0) &&
            (j != i)) {
          if (intersect(prmtrs, i, j))
            cout << "circle" << endl;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
