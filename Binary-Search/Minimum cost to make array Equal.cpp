#include <bits/stdc++.h>
using namespace std;

/*
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.*/

class Solution {
public:
    typedef long long ll;
    ll check(vector<int>& nums, vector<int>& cost, int target){
        ll totcost = 0;
        for(int i = 0; i<nums.size(); i++){
            totcost += (ll)abs(target - nums[i]) * cost[i];
        }
        return totcost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        ll ans = INT_MAX;

        while(low <= high){
            int mid = low + (high- low)/2;
            ll cost1 = check(nums,cost, mid);
            ll cost2 = check(nums, cost, mid + 1);
            ans = min(cost1, cost2);

            if(cost2 > cost1){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};