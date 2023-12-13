#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        vector<int> start(m);
        vector<int> ending(m);

        for(int i = 0; i<m; i++){
            start[i] = flowers[i][0];
            ending[i] = flowers[i][1];
        }

        vector<int> res;
        sort(start.begin(), start.end());
        sort(ending.begin(), ending.end());

        for(int i = 0; i<n; i++){
            int time = people[i];

            int bloomed_time = upper_bound(start.begin(), start.end(), time) - start.begin();
            int died_time = lower_bound(ending.begin(), ending.end(), time) - ending.begin();

            res.push_back(bloomed_time - died_time);
        }
        return res;
    }
};