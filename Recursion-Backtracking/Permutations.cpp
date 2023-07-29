#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    void getPermutations(vector<vector<int>> &ans, vector<int> &ds, int freq[], vector<int>& nums){
        int n = nums.size();
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < n; i++){
            if(freq[i] == 0){
                ds.push_back(nums[i]);
                freq[i] = 1;
                getPermutations(ans, ds, freq, nums);

                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for(int i = 0; i<n; i++) freq[i] = 0;
        getPermutations(ans, ds, freq, nums);
        return ans;
    }
};