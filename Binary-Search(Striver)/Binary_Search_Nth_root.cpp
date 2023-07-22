#include <bits/stdc++.h>
#define ll long long int
#define harekrishna                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
using namespace std;

double esp = 1e-6;

double multiply(double mid,int n)
{
    double ans = 1;
    for (int i = 0; i < n;i++)
    {
        ans = ans * mid;
    }
    return ans;
}                                   // T.C = N * log(n)

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double lo = 1, hi = x, mid;
    while(hi - lo > esp)
    {
        mid = (hi + lo) / 2;
        if(multiply(mid,n) < x)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    cout << lo << "\n" << hi<<"\n";
    cout << pow(x, 1.0 / n) << endl;
}