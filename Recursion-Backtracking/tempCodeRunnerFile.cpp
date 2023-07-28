#include<bits/stdc++.h>
using namespace std;

void print(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " ";
        }

        if(ds.size() == 0){
            cout<<"{}"<<" ";
        }
        cout<<endl;
        return;
    }

    // take or pick element
    ds.push_back(arr[ind]);
    print(ind + 1, ds, arr, n);
    ds.pop_back();

    // not pick element 
    print(ind + 1, ds, arr,n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    print(0, ds, arr, n);
}