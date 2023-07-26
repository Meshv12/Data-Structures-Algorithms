#include<bits/stdc++.h>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr){
	int n = arr.size();
	int pre = 1, suff = 1;
	int maxi = INT_MIN;

	for(int i = 0; i < n; i++){
		if(pre == 0) pre = 1;
		if(suff == 0) suff = 1;

		pre = pre * arr[i];
		suff = suff * arr[n - i - 1];

		maxi = max(maxi,max(suff,pre));
	}
	return maxi;
} 