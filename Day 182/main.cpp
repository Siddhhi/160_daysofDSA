/*
    Title: Minimum Operations to Make Matrix Beautiful.

    Problem Statement:
        - You are given a square matrix `mat` of size n × n.
        - A matrix is called "beautiful" if all rows and columns have equal sums.
        - In one operation, you can increment any element of the matrix by 1.
        - The task is to find the **minimum number of operations** required to make the matrix beautiful.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

int matrixBeautiful(vector<vector<int>> &mat) {
    int n = mat.size();
    
    int matSum = 0;
    int maxSum = 0;
    
    // Find max row sum
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        maxSum = max(sum, maxSum);
    }
    
    // Find max column sum
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[j][i];
        }
        maxSum = max(sum, maxSum);
    }
    
    // Calculate total sum of matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matSum += mat[i][j];
        }
    }
    
    // Formula: (n * maxSum) - totalMatrixSum
    return (n * maxSum) - matSum;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 4},
        {3, 2, 4},
        {5, 1, 2}
    };
    
    int minOperation = matrixBeautiful(mat);
    
    cout << "Minimum " << minOperation 
         << " operations are required to make the matrix beautiful.\n";
    
    return 0;
}





