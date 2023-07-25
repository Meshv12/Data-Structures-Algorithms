#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int ind = -1;
    int n = A.size();
    for(int i = n - 2; i >= 0; i--)
    {
        if(A[i] < A[i+1]){              // Step 1: Identify break point(from back of array)
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(A.begin(),A.end());     // Edge case like [5 4 3 2 1] -> [1 2 3 4 5] (if doesn't find break point)
        return A;
    }

    for(int i = n - 1; i>=ind; i--){
        if(A[i] > A[ind]){              // [2 1  |  5 4 3 0 0]
            swap(A[i],A[ind]);          // Step 2: smallest but greater than 1 (that is 3)
            break;                      //         swap it 
        }
    }                                   // Step 3: Sort the remaining part( we can reverse it)

    reverse(A.begin() + ind + 1,A.end());
    return A;

}