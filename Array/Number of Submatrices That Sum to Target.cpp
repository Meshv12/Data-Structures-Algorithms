#include <bits/stdc++.h>
using namespace std;

int numSubmatrixSumTarget(vector<vector<int>> &mat, int target)
{
    int n = mat.size();    // m
    int m = mat[0].size(); // n

    // First calculate the cumulative sum row-wise
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            mat[i][j] += mat[i][j - 1];
        }
    }

    // Now, you need to find the "No. of subarrays with sum k" in downward direction
    int res = 0;
    for (int start_col = 0; start_col < m; start_col++)
    {

        for (int j = start_col; j < m; j++)
        {
            // We need to find all sub matrices sum

            // Now comes the concept of "No. of subarrays with sum k"
            unordered_map<int, int> mp;
            mp.insert({0, 1});
            int sum = 0;

            // Go downwards row wise
            for (int row = 0; row < n; row++)
            {
                sum += mat[row][j] - (start_col > 0 ? mat[row][start_col - 1] : 0);

                int remaining = sum - target;
                if (mp.find(remaining) != mp.end())
                {
                    res += mp[remaining];
                }

                mp[sum]++;
            }
        }
    }

    return res;
}