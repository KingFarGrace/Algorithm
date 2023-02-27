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
 * An optimised bubble sort algorithm.
 * - When swap() never called in a single traversal, it means the array is ordered, then return.
 * - Record the boundary of unordered part of the array (because the ordered part sinked to the bottom of the array) to reduce the number of comparisons.
 * The optimisation can be shown directly by the return value of this function.
*/
int bubbleSort(int* array, int length)
{   
    int boundary = length - 1;
    int traverseCount = 0;
    for (int i = 0; i < length - 1; i++)
    {
        bool isOrdered = true; 
        int tempBound = 0;
        for (int j = 0; j < boundary; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                tempBound = j;
                isOrdered = false;
            }
        }
        boundary = tempBound;
        traverseCount += 1;
        if (isOrdered)
        {
            return traverseCount;
        }
    }
    return traverseCount;
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
    int traverseCount = bubbleSort(array, length);
    for (int i = 0; i < length; i++)
    {
        cout << "idx: " << i << " value: " << array[i] << "\n";
    }
    cout << "Traverse times: " << traverseCount << endl;
}