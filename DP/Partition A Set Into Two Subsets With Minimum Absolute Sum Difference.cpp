#include <bits/stdc++.h> 
using namespace std;

//Use subset sum equal to K concept

int minDifference(int arr[], int n)  { 
	    int totSum = 0;
    	for(int i = 0; i<n; i++) totSum += arr[i];
    	int k = totSum;
    
    	vector<bool> prev(k+1, 0), cur(k+1, 0);           // 3) After every iteration (prev = cur)
        prev[0] = cur[0] = true;                          // Note : Take first row is true because at target == 0 (acc. to base case) whole 1-D is true
        if(arr[0] <= k) prev[arr[0]] = true;
    
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= k; target++){
    
                bool notPick = prev[target];
                bool pick = false;
                if(arr[ind] <= target){
                    pick = prev[target-arr[ind]];
                }
    
                cur[target] = pick | notPick;
    
            }
            prev = cur;
        }
    	// dp[n-1][col->0.....col->sum]
    	int mini = 1e9;
    	for(int s1 = 0; s1<=k/2;s1++){
    		if(prev[s1] == true){
    			mini = min(mini, abs((totSum - s1) - s1));
    		}
    	}
    	return mini;
	} 