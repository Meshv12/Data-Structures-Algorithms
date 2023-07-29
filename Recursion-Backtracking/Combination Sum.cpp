#include <bits/stdc++.h>
using namespace std;
/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

/*
  TC --> O(2^t * K)  k is avg lenth and t is greater than n bcz we can take any element for any num of time
*/
class Solution {
    public:
    void findCombination(int ind, int target, vector<int> &arr,vector<vector<int>> &ans, vector<int> &ds){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);    // this takes liner time
            }
            return;
        }

        // pick up an element
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);   // Stay at that index
            ds.pop_back();
        }

        //Not pick an element
        findCombination(ind + 1, target, arr, ans, ds);   // Move on next index
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates , ans, ds);
        return ans;
    }
};