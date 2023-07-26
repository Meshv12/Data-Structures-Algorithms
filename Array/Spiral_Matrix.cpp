#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&mat) {
    int n = mat.size();  //num of rows
    int m = mat[0].size();  // num of cols
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while(top <= bottom && left <= right)
    {
        //right
        for(int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;

        //bottom
        for(int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;

        //left
        if(top<=bottom)            // we need to check for only one row 
        {
            for(int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        //top
        if(left<=right)            // if right exeeds then top does not goes upper side(Book's exmple)
        {
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}