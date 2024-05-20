#include<bits/stdc++.h>
using namespace std;

// Tabulation(General Method)
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n, 0);
    int maxi = 1, last_ind = 0;
    for(int i = 0; i < n; i++){
       // hash[i] = i;
        for(int prev = 0; prev < i; prev++){

            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                //hash[i] = prev;
            }

        }
        if(dp[i] > maxi){
            maxi = max(maxi, dp[i]);
            //last_ind = i;
        }
    }

    // vector<int> lis;
    // lis.push_back(arr[last_ind]);
    // while(hash[last_ind] != last_ind){             for printing LIS
    //     lis.push_back(arr[last_ind]);
    //     last_ind = hash[last_ind];
    // }

    return maxi;
}


// Binary search

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sorted;

    for (int i = 0; i < n; i++)
    {
        /*
             Why lower bound ?
             We want increasing subsequence and  hence
             we want to eliminate the duplicates as well.
             lower_bound returns iterator to "next greater or equal to"
        */
        auto it = lower_bound(begin(sorted), end(sorted), nums[i]);

        if (it == end(sorted))
            sorted.push_back(nums[i]); // greatest : so insert it
        else
            *it = nums[i]; // replace
    }

    return (int)sorted.size();
}