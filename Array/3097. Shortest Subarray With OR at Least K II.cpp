#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void addContribution(int val, vector<int> &bitarr, int contribution)
    {
        int i = 0;
        while (val > 0)
        {

            if (contribution == 1)
            {
                bitarr[i] += val % 2;
            }
            else
            {
                bitarr[i] -= val % 2;
            }

            val /= 2;
            i++;
        }
    }

    bool greater_than_K(int k, vector<int> &bitarr)
    {
        int sum = 0;

        for (int i = 0; i < 32; i++)
        {
            if (bitarr[i])
            {
                sum += (1 << i);
            }
        }

        if (sum >= k)
            return true;
        return false;
    }

    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> bitarr(32, 0);

        int j = 0;
        int i = 0;
        int ans = INT_MAX;

        while (j < n)
        {

            addContribution(nums[j], bitarr, 1); // 1 means add that value

            while (greater_than_K(k, bitarr) && i <= j)
            {

                ans = min(ans, j - i + 1);

                addContribution(nums[i], bitarr, -1); // -1 means remove that value

                i++;
            }

            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};