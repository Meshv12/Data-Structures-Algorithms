#include<bits/stdc++.h>
using namespace std;

/*
#####Pending
845. Longest Mountain in Array
852. Peak Index in a Mountain Array
1671. Minimum Number of Removals to Make Mountain Array
941. Valid Mountain Array
*/
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp1(n, 1);
    int maxi = 0, last_ind = 0;
    for(int i = 0; i<n; i++){
        for(int prev = 0; prev<i; prev++){

            if(arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i]){
                dp1[i] = 1 + dp1[prev];
            }

        }
    }

    vector<int> dp2(n, 1);
    for(int i = n-1; i>=0; i--){
        for(int prev = n-1; prev > i; prev--){

            if(arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i]){
                dp2[i] = 1 + dp2[prev];
            }

        }
    }

	for(int i = 0; i < n; i++){
		maxi = max(maxi, dp1[i] + dp2[i] -1);
	}
	
    return maxi;
}
