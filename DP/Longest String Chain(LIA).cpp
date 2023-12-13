#include<bits/stdc++.h>
using namespace std;
bool checkPossible(string &s1, string &s2){
    if(s1.size() != s2.size() + 1) return false;

    int first = 0;
    int second  = 0;
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){   // Extra condition for Example [abcd abc]
            first++;
            second++;
        }
        else{
            first++;
        }
    }

    if(first == s1.size() && second == s2.size()){
        return true;
    }
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr){
    int n = arr.size();
    vector<int> dp(n, 1), hash(n, 0);
    int maxi = 1, last_ind = 0;
    sort(arr.begin(), arr.end(), comp);  // sort according to size

    for(int i = 0; i<n; i++){
        hash[i] = i;
        for(int prev = 0; prev<i; prev++){

            if(checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }

        }
        if(dp[i] > maxi){
            maxi = max(maxi, dp[i]);
            last_ind = i;
        }
    }

    // vector<int> lis;
    // lis.push_back(arr[last_ind]);
    // while(hash[last_ind] != last_ind){
    //     lis.push_back(arr[last_ind]);
    //     last_ind = hash[last_ind];
    // }

    return maxi;
}