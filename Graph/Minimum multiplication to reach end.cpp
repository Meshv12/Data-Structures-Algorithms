#include<bits/stdc++.h>
using namespace std;

int mod = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        //{step, node}
        vector<int> dist(100000, 1e9);
        q.push({0, start});
        dist[start] = 0;
        
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
        
            if(node == end) return steps;
            
            for(auto it : arr){
                int nextNode = (it*node) % mod;
                if(steps + 1 < dist[nextNode]){
                    dist[nextNode] = steps + 1;
                    q.push({steps + 1, nextNode});
                    
                }
            }
        }
        
        return -1;
        
    }