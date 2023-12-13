#include<bits/stdc++.h>
using namespace std;

/*
A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
*/


vector<pair<int,int>> directions = {{2,1}, {-2,1}, {2,-1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};


double f(int i, int j, int k, int n, vector<vector<vector<double>>> &dp){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];

        double ways = 0;
        for(auto it : directions){
            int new_row = i + it.first;
            int new_col = j + it.second;

            ways = ways + (double)f(new_row, new_col, k-1, n, dp);
        }

        return dp[i][j][k] = (double)ways/8.0;
}

double knightProbability(int n, int k, int row, int column) {          // Row and col are coordinates from we have to start 
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>> (n+1, vector<double>(k+1, -1)));
        return f(row, column, k, n, dp);
}