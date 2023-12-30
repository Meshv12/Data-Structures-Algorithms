#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    bool isPossible(int len, vector<int>& nums, vector<ll>& presum, long long k){
        int n = nums.size();
        ll i = 0;
        ll j = len - 1;       
        // Step 2 : sliding Window of size (mid) 

        while(j < n){
            ll target_ind = (i+j)/2;               // don't confuse with BS it is an avg middle element for min cost
            ll target = nums[target_ind];

            ll operations_left = 0, operations_right = 0;

            // Step 3 : find operations use concept of prefix sum
            if(target_ind == 0){  
                operations_left = 0;              // Left sum
            }
            else{
                operations_left = abs( (target_ind - i) * target - (presum[target_ind - 1] - (i > 0 ? presum[i-1] : 0)) );
            }                             

            // Right sum
            operations_right = abs( (j - target_ind) * target - (presum[j] - presum[target_ind]) );

            if(operations_left + operations_right <= k) return true;

            i++;
            j++;

        }
        return false;
    }

    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        int low = 1;
        int high = n;
        sort(nums.begin(), nums.end());   // Step 1 : Sort the array

        vector<ll> presum(n, 0);
        presum[0] = nums[0];
        for(int i = 1; i<n; i++) presum[i] = presum[i-1] + nums[i];

        int result = 1;

        // binary search on answers
        while(low <= high){
            int mid = low + (high-low)/2;

            if(isPossible(mid, nums, presum, k)){
                result = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return result;
    }
};