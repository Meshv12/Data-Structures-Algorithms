#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reverse
    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}