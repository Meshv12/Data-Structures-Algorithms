#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void getPermutations(int ind, vector<vector<int>> &ans, vector<int> &nums)
    {
        int n = nums.size();
        if (ind == n)
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for (int i = ind; i < n; i++)
        {
            if (st.find(nums[i]) != st.end())
                continue;

            st.insert(nums[i]);
            swap(nums[ind], nums[i]);

            getPermutations(ind + 1, ans, nums); // Notice that ind + 1 not i + 1

            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        getPermutations(0, ans, nums);
        return ans;
    }
};