#include <iostream>

int main()
{
    int n;
    std::cout << "N= ";
    std::cin >> n;

    bool* arr = new bool[n + 1];
    for (int i = 2; i < n + 1; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i < n + 1; i++)
    {
        if (arr[i])
        {
            for (int k = i * i; k < n + 1; k += i)
            {
                arr[k] = false;
            }
        }
    }

    for (int i = n; i >= 0; i--)
    {
        if (arr[i])
        {
            std::cout << i;
            break;
        }
    }
}