template<typename T> void swap(T* a, T* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T> T partition(T arr[], int start, int end)
{

    T pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }



    int pivotIndex = start + count;
    swap(&arr[pivotIndex], &arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(&arr[i++], &arr[j--]);
        }
    }

    return pivotIndex;
}

template<typename T> void quickSort(T arr[], int start, int end, int& counter)
{
    if (start >= end)
        return;

    T p = partition(arr, start, end);
    counter++;

    quickSort(arr, start, p - 1, counter);
    counter++;

    quickSort(arr, p + 1, end, counter);
    counter++;
}