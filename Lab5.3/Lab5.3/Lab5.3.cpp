#include <iostream>
#include "Function.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m;
    
    cout << "Введите порядок матрицы n*m:" << '\n';
    cin >> n >> m;
    
    int** a = new int*[m] {};
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }
    
    vvod_mass(a, n, m);

    cout << "Ваша матрица:" << '\n';
    vivod_mass(a, n, m);
    sort(a, n, m);
    cout << "Ваша отсортированная матрица:" << '\n';
    vivod_mass(a, n, m);
    return 0;
}