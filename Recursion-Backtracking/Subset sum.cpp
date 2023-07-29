#include<bits/stdc++.h> 
using namespace std; 
/*
Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8                          TC --> O(2^N)  if not asked sorted sum
*/
class Solution
{
public:
    void findSubset(int ind, int sum, vector<int> &ans, vector<int> &arr, int N){
        if(ind == N){
            ans.push_back(sum);
            return;
        }
        
        //Pick element
        findSubset(ind + 1, sum + arr[ind], ans, arr, N);
        
        //Not Pick element 
        findSubset(ind + 1, sum, ans, arr, N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        findSubset(0, 0, ans, arr, N);
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
