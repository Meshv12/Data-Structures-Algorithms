#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;
    vector<long long> sum;
    long long maxi;
    
    DisjointSet(int n, vector<int> &val) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        sum.resize(n + 1, 0); 
        maxi = 0;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sum[i] = val[i];
            maxi = max(maxi, sum[i]);
        }
    }

    int find_ulti_parent(int node) { // Path Compression
        if (node == parent[node])
            return node;

        return parent[node] = find_ulti_parent(parent[node]);
    }

    void merge(int u, int v) {
        int ulti_u = find_ulti_parent(u);
        int ulti_v = find_ulti_parent(v);
        if (ulti_u == ulti_v) return;

        if (size[ulti_u] > size[ulti_v]) swap(ulti_u, ulti_v);

        parent[ulti_u] = ulti_v;
        size[ulti_v] += size[ulti_u];
        sum[ulti_v] += sum[ulti_u];
        maxi = max(maxi, sum[ulti_v]);
    }
};

class Solution {
public:
    typedef long long ll;

    vector<ll> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        vector<int> pre = nums;
        for (int i = 0; i < n; i++) {
            int ind = removeQueries[i];
            pre[ind] = 0;
        }

        DisjointSet ds(n, pre);

        for (int i = 0; i < n; i++) {
            if (pre[i] == 0) continue;

            int start = i;
            while (start < n && pre[start] != 0) {
                ds.merge(start, i);
                start++;
            }
        }

        vector<long long> ans;

        for (int q = n - 1; q >= 0; q--) {

            ans.push_back(ds.maxi);

            int ind = removeQueries[q];
            pre[ind] = nums[ind];
            ds.sum[ind] = pre[ind];
            ds.maxi = max(ds.sum[ind], ds.maxi);

            if (ind > 0 && pre[ind - 1] != 0) ds.merge(ind, ind - 1);
            if (ind < n - 1 && pre[ind + 1] != 0) ds.merge(ind, ind + 1);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
