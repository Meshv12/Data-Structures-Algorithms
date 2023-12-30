#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<pair<int,int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis){
    vis[row][col] = 1;
    
    int n = mat.size();
    int m = mat[0].size();

    for(auto it: dir){
        int nrow = row + it.first;
        int ncol = col + it.second;
        
        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && mat[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
            dfs(nrow, ncol, mat, vis);
        }
    }
    
}
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis (n, vector<int>(m, 0));
        
        for(int i = 0; i < m; i++){
            // Traverse first row
            if(mat[0][i] == 'O' && vis[0][i] == 0){
                dfs(0, i, mat, vis);
            }
            // travese last row
            if(mat[n-1][i] == 'O' && vis[n-1][i] == 0){
                dfs(n-1, i, mat, vis);
            }
        }
        
        for(int i = 0; i<n; i++){
            // first col
            if(mat[i][0] == 'O' && vis[i][0] == 0){
                dfs(i, 0, mat, vis);
            }
            // last col
            if(mat[i][m-1] == 'O' && vis[i][m-1] == 0){
                dfs(i, m-1, mat, vis);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        
    }
};