#include <iostream>

using namespace std;

/*You know what this function can do.*/
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/**
 * The simpliest way to sort an unordered array.
 * The time complexity is always O(n^2).
*/
int selectionSort(int* array, int length)
{
    // How many times do you swap to finish the sorting?
    int swapCount = 0;
    for (int i = 0; i < length - 1; i++)
    {
        // The end of the ordered part.
        int minIndex = i;
        // Find the smallest number from the head to the end of unordered part.
        for (int j = minIndex + 1; j < length; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        // If you get a smallest number, swap it.
        if (minIndex != i)
        {
            swap(array[minIndex], array[i]);
            swapCount += 1;
        }
    }
    return swapCount;
}

int main()
{
    int length;
    cout << "Please enter the length of array: ";
    cin >> length;
    int array[length];
    for (int i = 0; i < length; i++)
    {
        cout << "number#" << i + 1 << ": ";
        cin >> array[i];
    }
    int swapCount = selectionSort(array, length);
    for (int i = 0; i < length; i++)
    {
        cout << "idx: " << i << " value: " << array[i] << "\n";
    }
    cout << "Finished by " << swapCount << " times of swap." << endl;
}