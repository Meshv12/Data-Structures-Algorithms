#include <bits/stdc++.h>
using namespace std;
/*
Sample Input 1:
8 5
5 4 5 2 3 4 5 6
Sample Output 1:
9
Explanation For Sample Input 1:
In the test case, the given weights are [5,4,5,2,3,4,5,6] and these are needed to be shipped in 5 days. We can divide these weights in the following manner:
Day         Weights       Total
1        -   5, 4          -    9
2        -   5, 2          -    7
3        -   3, 4          -    7
4        -   5             -    5
5        -   6             -    6
The least weight capacity needed is 9, which is the total amount of weight that needs to be taken on Day 1.


In the second test case, the given weights are [2,1,4] and these are needed to be shipped in 2 days. We can divide these weights in the following manner:
Day         Weights         Total
1         -      2, 1        -      3
2         -      4           -      4
The least weight capacity needed is 4, which is the total amount of weight that needs to be taken on Day 2.
*/

int findDays(vector<int> &arr, int cap)
{
    int days = 1, load = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (load + arr[i] > cap)
        {
            days = days + 1;
            load = arr[i];
        }
        else
        {
            load = load + arr[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &arr, int d)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int numOfDays = findDays(arr, mid);
        if (numOfDays <= d)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}