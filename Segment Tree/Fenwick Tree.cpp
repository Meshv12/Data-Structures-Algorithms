#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> bit;

void update(int id, int val)
{
    while (id <= n)
    {
        bit[id] += val;
        id += (id & -id); // go to LSB takes log n time
    }
}

int query(int id)
{ // gives ans to 1 to id
    int ans = 0;
    while (id > 0)
    {
        ans += bit[id];
        id -= (id & -id);
    }
    return ans;
}

int main()
{
    cin >> n;
    vector<int> a(n + 1);
    bit = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; i++)
    { // always 1 based indexing
        cin >> a[i];
        update(i, a[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        { // simple prefix sum
            int l, r;
            cin >> l >> r;
            int ans = query(r) - query(l - 1);
            cout << ans << endl;
        }
        else
        {
            int id, val;
            cin >> id >> val;
            update(id, val - a[id]);
        }
    }
}