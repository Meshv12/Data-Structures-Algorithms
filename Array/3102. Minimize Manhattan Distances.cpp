#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxdist(vector<vector<int>> &points, int exclude)
    {
        int n = points.size();
        vector<int> ans = {-1, -1, -1}; // ,max_dist ,i, j

        pair<int, int> maxdiff = {-1, INT_MIN}, mindiff = {-1, INT_MAX}, maxsum = {-1, INT_MIN}, minsum = {-1, INT_MAX};
        // ind, ans

        for (int i = 0; i < n; i++)
        {
            if (exclude == i)
                continue;

            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];

            if (sum > maxsum.second)
                maxsum = {i, sum};
            if (sum < minsum.second)
                minsum = {i, sum};
            if (diff > maxdiff.second)
                maxdiff = {i, diff};
            if (diff < mindiff.second)
                mindiff = {i, diff};
        }

        if (maxdiff.second - mindiff.second > maxsum.second - minsum.second)
        {
            ans[0] = maxdiff.second - mindiff.second;
            ans[1] = mindiff.first;
            ans[2] = maxdiff.first;
        }
        else
        {
            ans[0] = maxsum.second - minsum.second;
            ans[1] = minsum.first;
            ans[2] = maxsum.first;
        }

        return ans;
    }

    int minimumDistance(vector<vector<int>> &points)
    {
        auto a = maxdist(points, -1);
        int i = a[1];
        int j = a[2];

        return min(maxdist(points, i)[0], maxdist(points, j)[0]);
    }
};