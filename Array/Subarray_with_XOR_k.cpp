#include<bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector < int > a, int k) {
    int xr = 0;
    map<int,int> mpp;
    int cnt = 0;
    mpp[0] = 1; //{0,1}

    for(int i = 0; i < a.size(); i++){
        xr = xr ^ a[i];  //prefix  
        int x = xr ^ k;    // reverse enginnering 
        cnt = cnt + mpp[x];    // get cnt
        mpp[xr]++;             // put prefix in map
    }
    return cnt;
}