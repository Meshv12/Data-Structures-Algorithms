#include <bits/stdc++.h>
using namespace std;
/*
Input: ‘n’ = 4, ‘a’ = [7, 15, 6, 3], ‘h’ = 8

Output: 5

Explanation: If ‘m’ = 5, then 
The time taken to empty the 1st pile is 2 hour.
The time taken to empty the 2nd pile is 3 hour.
The time taken to empty the 3rd pile is 2 hour.
The time taken to empty the 4th pile is 1 hour.
Therefore, a total of 8 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 8 hours.
*/

int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int Hours)
{
    int totalHours = 0;
    for (int i = 0; i < v.size(); i++)
    {
        totalHours += ceil((double)v[i] / (double)Hours);
    }
    return totalHours;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1, high = findMax(v);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalHour = calculateTotalHours(v, mid);
        if (totalHour <= h)
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