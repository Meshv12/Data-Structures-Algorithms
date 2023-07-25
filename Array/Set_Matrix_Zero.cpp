#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// int col[m] --> matrix[0][..]
	// int row[n] --> matrix[..][0]
	int col0 = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				// mark i-th row
				matrix[i][0] = 0;        // STEP 1: MARK APPROPRIATE COLS AND ROWS

				// marks j-th col
				if(j == 0)
					col0 = 0;
				else
					matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i<n; i++){
		for(int j = 1; j<m; j++){
			if(matrix[i][j] != 0){
				if(matrix[i][0] == 0 || matrix[0][j] == 0){
					matrix[i][j] = 0;//   STEP 2: EXEPT 1ST COL AND 1ST ROW
//                                                TRAVERSE MATRIX AND CHANGE 1'S TO 0'S
				}
			}
		}
	}

        if (matrix[0][0] == 0) {
          for (int j = 0; j < m; j++) {
			  matrix[0][j] = 0;
          }
        } //                            STEP 3: MARK 1ST COL AND 1ST ROW

		if(col0 == 0){
			for(int i = 0; i < n; i++){
				matrix[i][0] = 0;
			}
		}

		return matrix;
}