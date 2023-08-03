#include <bits/stdc++.h>
using namespace std;
/*
You have to give right rotate array Find out How many times array rotated?
If we right rotate the array {1, 2, 3, 4} by '3' times then we will get {2, 3, 4, 1}. Thus 'r' = 3.
*/
int findKRotation(vector<int> &arr)
{ // Minimum element in roteted sorted array
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // whole Search space is already sorted
        // then always arr[low] is will be smaller
        // in that search space
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;    // for Finding how many times roteted array
                ans = arr[low]; // we have to keep track of index of minimum element
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            } // take min form sorted part and move
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            } // take min form sorted part and move
            high = mid - 1;
        }
    }
    return index;
}