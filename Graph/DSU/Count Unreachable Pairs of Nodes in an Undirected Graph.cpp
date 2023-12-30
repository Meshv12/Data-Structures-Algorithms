#include<bits/stdc++.h>
using namespace std; 

class DisjointSet{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find_ulti_parent(int node){       //Path Compression
        if(node == parent[node])
            return node;

        return parent[node] = find_ulti_parent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulti_u = find_ulti_parent(u);
        int ulti_v = find_ulti_parent(v);
        if(ulti_u == ulti_v) return;

        if(rank[ulti_u] < rank[ulti_v]){
            parent[ulti_u] = ulti_v;
        }
        else if(rank[ulti_v] < rank[ulti_u]){
            parent[ulti_v] = ulti_u;
        }
        else{
            parent[ulti_v] = ulti_u;
            rank[ulti_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulti_u = find_ulti_parent(u);
        int ulti_v = find_ulti_parent(v);
        if(ulti_u == ulti_v) return;

        if(size[ulti_u] < size[ulti_v]){
            parent[ulti_u] = ulti_v;
            size[ulti_v] += size[ulti_u];
        }
        else{
            parent[ulti_v] = ulti_u;
            size[ulti_u] += size[ulti_v];
        }
    }
};

class Solution {
public:
    typedef long long ll;

    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto it : edges){
            ds.unionBySize(it[0], it[1]);
        }

        unordered_map<int, int> mp;    // {parent, num of node in component}

        for(int i = 0; i<n; i++){
            int par = ds.find_ulti_parent(i);

            mp[par]++;
        }

        ll res = 0;
        ll remaining = n;

        // Traverse in map
        for(auto it : mp){
            ll size = it.second;              // size of current component

            res += size*(remaining - size);

            remaining -= size;
        }

        return res;
    }
};