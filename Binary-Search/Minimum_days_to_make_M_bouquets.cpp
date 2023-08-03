#include<bits/stdc++.h>
using namespace std;
/*
9
1 2 1 2 7 2 2 3 1
3 2

Sample Output 1 :
3

Explanation For Sample Input 1 :
We will return 3, because:
All the roses with 'arr[i]' less than equal to 3 have already bloomed after 3 days, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.
*/

bool possible(vector<int> &arr, int day, int k, int n)
{
    int cnt = 0;
    int totalB = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            totalB += (cnt / k);
            cnt = 0;
        }
    }
    totalB += (cnt / k);

    return totalB >= n;
}

int roseGarden(vector<int> arr, int r, int b)
{
    long long val = r * 1LL * b * 1LL; // Impossible case
    if (val > arr.size())
        return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, r, b))
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