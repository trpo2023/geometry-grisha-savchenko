#include <LibGeometry/func.h>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std ::string path = "test";
    std ::vector<std ::string> str
            = dataFromFile(path); // вектор строк из файла
    int k = str.size();
    double** prmtrs;
    prmtrs = new double*[k];
    for (int i = 0; i < k; i++)
        prmtrs[i] = new double[3];

    for (int i = 0; i < k; i++) {
        StrChek(str[i], prmtrs[i]);
        for (int j = 0; j < 3; j++)
            std ::cout << prmtrs[i][j] << " ";
        std ::cout << std ::endl;
    }

    for (std ::string s : str)
        std ::cout << s << std ::endl;
    /////////////////////////////////////////////////////////////////////
    for (int i = 0; i < k; i++) {
        if ((prmtrs[i][0] != 0) && (prmtrs[i][1] != 0) && (prmtrs[i][2] != 0)) {
            std ::cout << "perimeter =" << perimter(prmtrs[i][2]) << std ::endl;
            std ::cout << "area =" << area(prmtrs[i][2]) << std ::endl;
            std ::cout << "intersects:" << std ::endl;
            for (int j = 0; j < k; j++) {
                if ((prmtrs[i][0] != 0) && (prmtrs[i][1] != 0)
                    && (prmtrs[i][2] != 0) && (j != i)) {
                    if (intersect(prmtrs, i, j))
                        std ::cout << "circle" << std ::endl;
                }
            }
        }
        std ::cout << std ::endl;
    }
    for (int i = 0; i < k; i++) {
        delete prmtrs[i];
    }
    delete prmtrs;
    return 0;
}
