#include <iostream>

using namespace std;

/*You know what this function can do.*/
int swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    return 1;
}

/**
 * A function to optimize the sort.
 * Find the min and max value in a single traversal and put them to the head and end of the array.
 * If min == max, return 0 and stop the sort (all elements in the array are same).
 * Else return 2 (the number of swap has occured).
 * It can reduced the swap times notably when the array is highly unordered (like 5, 4, 3, 2, 1).
*/
int resetMinAndMax(int* array, int length)
{
    int max = array[0];
    int maxIdx = 0;
    int min = array[0];
    int minIdx = 0;
    for (int i = 1; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            maxIdx = i;
        }
        if (array[i] < min)
        {
            min = array[i];
            minIdx = i;
        } 
    }
    if (max == min)
    {
        return 0;
    }
    else
    {
        swap(array[0], array[minIdx]);
        swap(array[length - 1], array[maxIdx]);
        return 2;
    }
}

/**
 * A function to realize insertion sort algorithm.
 * Return the times of swap() is called during the sort.
 * Annotate the optimised code and see if there's any difference on return value.
*/
int insertionSort(int* array, int length)
{
    int swapCount = 0;
    /* Optimisation start */
    int resetResult = resetMinAndMax(array, length);
    if (resetResult == 0)
    {
        return 0;
    }
    swapCount += resetResult;
    /* Optimisation end */
    for (int i = 1; i < length; i++)
    {
        int cur = i;
        int pre = i - 1;
        for (int j = pre; j >= 0; j--)
        {
            if (array[cur] <= array[j])
            {
                swapCount += swap(array[cur], array[j]);
                cur--;
            }
            else
            {
                break;
            }
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
    int swapCount = insertionSort(array, length);
    for (int i = 0; i < length; i++)
    {
        cout << "idx: " << i << " value: " << array[i] << "\n";
    }
    cout << "Swap occured " << swapCount << " times." << endl;
}