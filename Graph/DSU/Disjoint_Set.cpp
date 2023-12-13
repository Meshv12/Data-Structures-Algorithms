#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
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

// ******************** Kruskal Algo *********************

bool customComparator(const std::vector<int> &a, const std::vector<int> &b)
{
    return a.back() < b.back();
}
// int kruskalMST(int n, vector<vector<int>> &edges)
// {
//     DisjointSet ds(n);
//     sort(edges.begin(), edges.end(), customComparator);
//     int ans = 0;
//     for (auto it : edges)
//     {
//         int u = it[0];
//         int v = it[1];
//         int wt = it[2];

//         if (ds.find_ulti_parent(u) != ds.find_ulti_parent(v))
//         {
//             ans += wt;
//             ds.unionBySize(u, v);
//         }
//     }
//     return ans;
// }