#include <bits/stdc++.h>
using namespace std;

int f(vector<int> mat, int mid)
{
    return upper_bound(mat.begin(), mat.end(), mid) - mat.begin();
}

int findMedian(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 1;
    int high = 1e9 + 1;

    while (low <= high)
    {
        int mid = high + (low - high) / 2;

        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += f(mat[i], mid);

        if (cnt <= (m * n) / 2)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return low;
}
