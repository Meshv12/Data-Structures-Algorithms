#include <bits/stdc++.h>
using namespace std;

void print(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
        }
        cout << endl;
        return;
    }

    // take or pick element
    ds.push_back(arr[ind]);
    s += arr[ind];
    print(ind + 1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();

    // not pick element
    print(ind + 1, ds, s, sum, arr, n);
}

// Only print One subsequence /// (Always remember in your mind this method)

bool printF(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        //condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }

        //condition not satisfied
        else return false;
    }

    // take or pick element
    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printF(ind + 1, ds, s, sum, arr, n) == true){
        return true;
    }

    s -= arr[ind];
    ds.pop_back();

    // not pick element
    if(printF(ind + 1, ds, s, sum, arr, n) == true){
        return true;
    }

    return false;
}



// Number of Subsequences which sum is K

int printy(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            return 1;
        }
        else
            return 0;
    }

    // take or pick element
    ds.push_back(arr[ind]);
    s += arr[ind];
    int l = printy(ind + 1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();

    // not pick element
    int r = printy(ind + 1, ds, s, sum, arr, n);

    return l + r;
}