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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.find_ulti_parent(u) == ds.find_ulti_parent(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
         
        int compo = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i){
                compo++;
            }
        }
        int ans = compo - 1;   // there are n components we need minimum n-1 edges to connect them
        if(extraEdges >= ans ) return ans;      
        return -1;
    }
};