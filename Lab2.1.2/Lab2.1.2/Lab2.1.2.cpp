#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double x;
    int n;
    cout << "Введите положительное вещественное число: ";
    cin >> x;
    cout << "Введите количество цифр дробной части для проверки: ";
    cin >> n;

    int prevDigit = static_cast<int>(x * pow(10, n)) % 10; // Получаем первую цифру
    int currentDigit;
    bool isIncreasing = true, isDecreasing = true;

    for (int i = 1; i < n; i++) {
        currentDigit = static_cast<int>(x * pow(10, n - i)) % 10; // Получаем следующие цифры

        if (currentDigit > prevDigit) {
            isIncreasing = false;
        }
        else if (currentDigit < prevDigit) {
            isDecreasing = false;
        }

        prevDigit = currentDigit;
    }

    if (isIncreasing) {
        cout << "Первые " << n << " цифр образуют возрастающую последовательность" << endl;
    }
    else if (isDecreasing) {
        cout << "Первые " << n << " цифр образуют убывающую последовательность" << endl;
    }
    else {
        cout << "Первые " << n << " цифр не образуют монотонную последовательность" << endl;
    }

    return 0;
}
