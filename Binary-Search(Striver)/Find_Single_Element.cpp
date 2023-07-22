#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }
        //[1   1   2 2 3 4 4]
        // even odd E O E O E   <-- Index
        //(even,odd) -> element is in right side(elemenet left side)
        //(odd,even) -> element is in left side

        if ((mid % 2 == 1 && arr[mid - 1] == arr[mid]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {                  // I am standing near left half
            low = mid + 1; // eleminets the left half
        }

        else
        {                   // I am standing at right
            high = mid - 1; // elemenets the right half
        }
    }
    return -1;
}