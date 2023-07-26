#include <bits/stdc++.h>
using namespace std;

//(1) Find nCr
int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    { // O(r)
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

//(2) Given the row number n. Print the n-th row of Pascal’s triangle.

void pascalTriangle(int n)
{
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    // Printing the rest of the part:
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

//(3) Given Row number n. Print whole pascal's triangle.

vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // inserting the 1st element

    // calculate the rest of the elements:
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascallTriangle(int n)
{
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}