#include <iostream> 
#include "mergesort.h"
#include "quicksort.h"

using namespace std;

template<typename T> void printArray(T A[], int size, int counter)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl << counter << endl;
}

int main()
{
    srand(time(NULL));
    std::cout << "Enter array size: ";
    int arraySize;
    std::cin >> arraySize;

    std::cout << "Select filling method for array: 1.Ascending 2.Descending 3.Random ";
    int choise;
    std::cin >> choise;

    int* arr = new int[arraySize];
    int* arr2 = new int[arraySize];

    switch (choise)
    {
    case 1:
        for (int i = 0; i < arraySize; i++)
        {
            arr[i] = i + 1;
        }
        break;
    case 2:
        for (int i = 0; i < arraySize; i++)
        {
            arr[i] = arraySize - i;
        }
        break;
    case 3:
        for (int i = 0; i < arraySize; i++)
        {
            arr[i] = rand() / 100.0;
        }
        break;
    default:
        std::cout << "Wrong choise!";
        return 0;
    }

    printArray(arr, arraySize, 0);

    for (int i = 0; i < arraySize; i++)
    {
        arr2[i] = arr[i];
    }

    int quickCounter = 0;
    int mergeCounter = 0;

    quickSort(arr, 0, arraySize - 1, quickCounter);
    mergeSort(arr2, 0, arraySize - 1, mergeCounter);

    printArray(arr, arraySize, quickCounter);
    printArray(arr2, arraySize, mergeCounter);
}