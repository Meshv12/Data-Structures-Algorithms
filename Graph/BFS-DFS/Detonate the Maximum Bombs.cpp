#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    void bfs(int i, unordered_map<int, vector<int>> &adj, unordered_set<int> &st){
        queue<int> q;
        q.push(i);
        st.insert(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(st.find(it) == st.end()){
                    q.push(it);
                    st.insert(it);
                }
            }

        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) continue;

                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll dist = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);               // radius in bigger than dist btw to centers then ..

                if(r1*r1 >= dist){
                    adj[i].push_back(j);
                }
                
            }
        }
        
        // do BFS for all node and get maximum 
        unordered_set<int> st; 
        int res = 0;

        for(int i = 0; i<n; i++){ 
            bfs(i, adj, st);

            int cnt = st.size();
            res = max(res, cnt);

// check for all nodes we need to clear visited array(set) to get cnt how many nodes is connected with perticuler node
            st.clear(); 

        }
        return res;
    }
};