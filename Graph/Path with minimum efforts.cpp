#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // as like distance array here take differece array
        vector<vector<int>> diffarray(n, vector<int>(m, INT_MAX)); 
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        diffarray[0][0] = 0;

        auto check = [&](int i, int j){
            return i >= 0 && j >=0 && i < n && j < m;
        };

        while(!pq.empty()){

            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(auto it : dir){
                int nrow = row + it.first;
                int ncol = col + it.second;

                if(check(nrow, ncol)){
                    int cc = abs(heights[row][col] - heights[nrow][ncol]);
                    int maxdiff = max(diff, cc);

                    if(maxdiff < diffarray[nrow][ncol]){
                        pq.push({maxdiff, {nrow, ncol}});
                        diffarray[nrow][ncol] = maxdiff;

                    }
                }
            }
        }

        return diffarray[n-1][m-1];

    }
};