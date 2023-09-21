#include <bits/stdc++.h> 
using namespace std;
/*
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
*/

class Solution {
public:
    int dp[1001][1001];
    set<pair<int, int>> vis;
    int f(int i, int j, int n){     
        if(i == n) return 0;
        if(i > n) return 1e8;

        if(dp[i][j] != -1) return dp[i][j];

        if(vis.find({i, j}) != vis.end()) return 1e8;    // It's stuck into infinte recurtion
        else vis.insert({i, j});
        int op1 = 1 + f(i, i, n);     // Copy all A's form screen to clipboard

        int op2 = 1 + f(i+j, j, n);   // paste all A's from clipboard to screen

        return dp[i][j] = min(op1,op2);
    }
    int minSteps(int n) {
        memset(dp, -1, sizeof dp);
        return f(1, 0, n);     // At start I have 1 A on screen and 0 A    on clipboard
    }
};