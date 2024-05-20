#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    int M = 31;
    int table[31][50002];
    TreeAncestor(int n, vector<int>& parent) {
        // parent[0] = 0;

        for(int i = 0; i<n; i++){
            table[0][i] = parent[i];
        }

        for(int i = 1; i<M; i++){
            for(int j = 0; j<n; j++){
                int p = table[i-1][j];
                if(p != -1)
                    table[i][j] = table[i-1][table[i-1][j]];
                else
                    table[i][j] = -1;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i = 0; i<M; i++){
            int mask = (1<<i);
            if((mask&k)){
                if(node != -1)
                    node = table[i][node];
                else    
                    node = -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */