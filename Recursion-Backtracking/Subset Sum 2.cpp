#include<bits/stdc++.h> 
using namespace std; 
/*
Given an integer array nums that may contain duplicates, return all possible subsets

Note : The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

class Solution {
public:
    void findSubset(int ind, vector<vector<int>> &ans, vector<int> &nums, vector<int> &ds){
        ans.push_back(ds);              // For every call take an element and add to ans

        for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            findSubset(i + 1, ans, nums, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubset(0, ans, nums, ds);
        return ans;
    }
};