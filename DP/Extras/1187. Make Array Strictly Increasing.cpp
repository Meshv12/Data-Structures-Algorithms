#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<pair<int, int>, int> mp;
    int f(int ind, int prev, vector<int> &nums1, vector<int> &nums2, int n, int m)
    {
        if (ind >= n)
            return 0;

        auto key = make_pair(ind, prev);
        if (mp.find(key) != mp.end())
            return mp[key];

        int not_change = 1e9 + 1;
        int change = 1e9 + 1;

        if ((nums1[ind] > prev))
        {
            not_change = f(ind + 1, nums1[ind], nums1, nums2, n, m); // no operation
        }

        int i = upper_bound(nums2.begin(), nums2.end(), prev) - nums2.begin();
        if (i != m)
        {
            int val = nums2[i];
            change = 1 + f(ind + 1, val, nums1, nums2, n, m); //  take operation
        }

        return mp[key] = min(change, not_change);
    }

    int makeArrayIncreasing(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        mp.clear();

        sort(nums2.begin(), nums2.end());

        int ans = f(0, -1, nums1, nums2, n, m);

        return ans == 1e9 + 1 ? -1 : ans;
    }
};