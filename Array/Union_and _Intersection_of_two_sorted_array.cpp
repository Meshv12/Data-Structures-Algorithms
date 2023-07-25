#include <bits/stdc++.h>

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
  int i = 0, j = 0;  // pointers
  vector<int> Union; // Uninon vector
  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    }
    else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

vector<int> intersectionOfArrays(vector<int> A, vector<int> B)
{

  vector<int> ans;

  int i = 0, j = 0;

  // to traverse the arrays
  while (i < A.size() && j < B.size())
  {

    // if current element in i is smaller
    if (A[i] < B[j])
    {
      i++;
    }
    else if (B[j] < A[i])
    {
      j++;
    }
    else
    {

      // both elements are equal
      ans.push_back(A[i]);
      i++;
      j++;
    }
  }

  return ans;
}