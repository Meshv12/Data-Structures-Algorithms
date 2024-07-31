#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi(l, r) for (ll i = l; i < r; i++)
#define fj(l, r) for (ll j = l; j < r; j++)
#define fir(r, l) for (ll i = r; i >= l; i--)
#define fjr(r, l) for (ll j = r; j >= l; j--)
#define ha cout << "YES" << endl
#define na cout << "NO" << endl
#define line cout << endl
using namespace std;
int mod = 1e9 + 7;

void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<int> &vis, unordered_map<int, vector<int>> &adjT)
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adjT);
        }
    }
}

void code()
{
    ll n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;
    unordered_map<int, vector<int>> adjT;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    int scc = 0;
    vector<int> viis(n + 1, 0);

    vector<int> ans;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!viis[node])
        {
            ans.push_back(node);
            scc++;
            dfs3(node, viis, adjT);
        }
    }

    if (scc == 1)
        ha;
    else
    {
        na;
        cout << ans[1] << " " << ans[0] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        code();
    }

    return 0;
}
