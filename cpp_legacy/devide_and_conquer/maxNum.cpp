#include <iostream>

using namespace std;

/**
 * Devide the problem into two parts:
 * 1. Get the max number in the left part of array;
 * 2. Get the max number in the right part of array;
 * 3. return the bigger one.
 * You should noticed that when the left is equal to right, there is only one value in the array, so it is the max number which will be returned.
 * The time complexity is |- O(1) ... length = 1
 *                        |- O(n) ... length > 1
*/
int maxnum(int* array, int left, int right)
{
    if (left == right)
    {
        return array[left];
    }
    int mid = (right + left) / 2;
    int leftMax = maxnum(array, left, mid);
    int rightMax = maxnum(array, (mid + 1), right);
    return leftMax > rightMax ? leftMax : rightMax;
}

int main()
{
    int length;
    cout << "Please enter the length of array: ";
    cin >> length;
    int array[length];
    int left = 0;
    int right = length - 1;
    for (int i = 0; i < length; i++)
    {
        cout << "number#" << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "The max number in this array is: " << maxnum(array, left, right) << endl;
}