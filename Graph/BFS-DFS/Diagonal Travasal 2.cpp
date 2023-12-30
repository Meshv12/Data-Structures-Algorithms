#include<bits/stdc++.h>
using namespace std;

// Question : Dioganal Travasal II
// BFS approch 

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        int n = v.size();
        queue<pair<int, int>> q;
        vector<int> ans;

        q.push({0, 0});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            ans.push_back(v[row][col]);
            if(col == 0 && row + 1 < n) q.push( {row + 1, 0} );  // for col == 0 only downward element push into queue
            if(col + 1 < v[row].size()) q.push( {row, col + 1} );
        }

        return ans;
    }
};

// Map Approch

vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        int n = v.size();
        unordered_map<int, vector<int>> mp;

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < v[i].size(); j++){

                mp[i+j].push_back(v[i][j]);
            }
        }

        vector<int> res;
        int diagonal = 0;

        while(mp.find(diagonal) != mp.end()){

            for(auto it : mp[diagonal]){
                res.push_back(it);
            }
            diagonal++;
        }

        return res;

    }