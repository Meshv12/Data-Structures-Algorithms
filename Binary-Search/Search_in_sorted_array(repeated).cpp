#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Step - 1:- First of all identify which half is sorted-----
        if (arr[mid] == k)
            return true;

        // For Duplicates we have to pay attention on edge case
        // Edge Case: arr[low] == arr[mid] == arr[high]
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        // Left half will be sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Right half will be sorted
        else
        {
            if (arr[mid] <= k && k <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}