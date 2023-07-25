#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int more = target - num;
        if (mpp.find(more) != mpp.end())
        {
            return "YES"; //   If return index the return {mpp[more], i}
        }
        mpp[num] = i;
    }
    return "NO";
}

// time - O(N*logN) log N for searching elements from map data structure.
// space - O(N)