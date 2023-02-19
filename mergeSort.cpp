#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void mergeSort(int array[], int n);
void mergePass(int array[], int length, int n);
void merge(int array[], int low, int mid, int high);

int main() {
    int length;
    cout << "Input the length of array:" << endl;
    cin >> length;
    int array[length];
    for (int i = 0; i < length; i++)
    {
        cout << "number " << i + 1 << ": ";
        cin >> array[i];
    }
    
    mergeSort(array, length);
    for (int i = 0; i < length; i++)
    {
        cout << "pos: " << i << " value: " << array[i] << "\n";
    }
    system("pause");
}

/*
 * merge sort
 */
void mergeSort(int array[], int n)
{
    int length;
    for (length = 1; length < n; length *= 2)
    {
        mergePass(array, length, n);
    }
}

void mergePass(int array[], int length, int n)
{
    register int i;
    for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
    {
        merge(array, i, i + length - 1, i + 2 * length - 1);
    }
    if (i + length - 1 < n)
    {
        merge(array, i, i + length - 1, n - 1);
    }
}

void merge(int array[], int low, int mid, int high)
{
    int* tmpArray;
    int i = low, j = mid + 1, k = 0;
    tmpArray = (int*) malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
            tmpArray[k++] = array[i++];
        else
            tmpArray[k++] = array[j++];
    }
    
    while (i <= mid)
    {
        tmpArray[k++] = array[i++];
    }

    while (j <= high)
    {
        tmpArray[k++] = array[j++];
    }

    for (k = 0, i = low; i <= high; k++, i++)
    {
        array[i] = tmpArray[k];
    }

    delete tmpArray;
}