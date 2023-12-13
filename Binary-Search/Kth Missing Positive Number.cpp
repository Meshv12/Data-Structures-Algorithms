#include <bits/stdc++.h>
using namespace std;

// O(log N) --> Optimal Solution
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k < arr[0]) return k;
        
        int low = 1;
        int high = arr.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high + 1 + k;
    }
};