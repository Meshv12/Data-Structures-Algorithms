#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
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