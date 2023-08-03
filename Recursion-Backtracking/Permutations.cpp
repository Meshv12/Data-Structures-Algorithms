#include <bits/stdc++.h>
using namespace std;

// Using extra space
class Solution1
{
public:
    void getPermutations(vector<vector<int>> &ans, vector<int> &ds, int freq[], vector<int> &nums)
    {
        int n = nums.size();
        if (ds.size() == n)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (freq[i] == 0)
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                getPermutations(ans, ds, freq, nums);

                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for (int i = 0; i < n; i++)
            freq[i] = 0;
        getPermutations(ans, ds, freq, nums);
        return ans;
    }
};

// using without extra space (By swaping)

class Solution2
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

        for (int i = ind; i < n; i++)
        {
            swap(nums[ind], nums[i]);
            getPermutations(ind + 1, ans, nums); // Notice that ind + 1 not i + 1
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        getPermutations(0, ans, nums);
        return ans;
    }
};