#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void bfs(int row, int col, int** grid, vector<vector<int>>& vis, set<vector<pair<int, int>>>& st, int n, int m, int base_row, int base_col){
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;
    vector<pair<int, int>> v;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        v.push_back({r - base_row, c - base_col});

        for(auto it : dir){
            int nrow = r + it.first;
            int ncol = c + it.second;

            if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    st.insert(v);
}

int distinctIslands(int** grid, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && vis[i][j] == 0){
                bfs(i, j, grid, vis, st, n, m, i, j);
            }
        }
    }

    return st.size();
}
