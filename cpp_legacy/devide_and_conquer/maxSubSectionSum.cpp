#include <iostream>
#include <algorithm>

using namespace std;

/**
 * A decorator to reduce the duplication in function maxSub().
*/
int mid2side(int* array, int mid, int side)
{
    int sideMax = 0;
    int sideSum = 0;
    // From mid to left.
    if (side <= mid)
    {
        for (int i = mid; i >= side; i--)
        {
            sideSum += array[i];
            if (sideSum > sideMax)
            {
                sideMax = sideSum;
            }
        }
    }
    // From mid to right.
    else
    {
        for (int i = mid + 1; i <= side; i++)
        {
            sideSum += array[i];
            if (sideSum > sideMax)
            {
                sideMax = sideSum;
            }
        }
    }
    return sideMax;
}

/**
 * Devide the problem into 3 parts:
 * 1. If the sum of left section is the maximum value;
 * 2. If the sum of right section is the maximum value;
 * 3. If the sum of section which across the middle of array is the maximum value;
 * First 2 sub-problem is quite easy, but the third one need more thinking.
 * To simplified it, you can also devided it into smaller ones. 
 * Just imagine the sub-section is composed by the sub-sub-section from mid to left and mid to right. Get maximum sum of each section and add them.
 * See details in the code, the number of aboce sub-problem will be annotated above its solution.
 * The time complexity is |- O(1) ... n = 1
 *                        |- O(nlogn) ... n > 1
*/
int maxSub(int* array, int left, int right)
{
    // End of the problem.
    if (left == right)
    {
        return array[left] >= 0 ? array[left] : 0;
    }
    int mid = (left + right) / 2;
    // Solution for 1.
    int leftSum = maxSub(array, left, mid);
    // Solution for 2.
    int rightSum = maxSub(array, mid + 1, right);
    // Solution for 3.
    int mid2LeftSide = mid2side(array, mid, left);
    int mid2RightSide = mid2side(array, mid, right);
    int left2RightSum = mid2LeftSide + mid2RightSide;
    // Return the biggest value among 3 solutions.
    int subMax = max(leftSum, rightSum);
    return max(subMax, left2RightSum);
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
    int left = 0;
    int right = length - 1;
    cout << "The max sub-section sum is: " << maxSub(array, left, right) << endl;
}