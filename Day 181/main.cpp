/*
    Title: Generate Matrix from Row and Column Sums

    Problem Statement:
        - You are given two arrays: `rowSum` (size m) and `colSum` (size n).
        - Construct an m x n matrix such that:
            • The sum of each row equals rowSum[i]
            • The sum of each column equals colSum[j]
        
    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(vector<int> &rowSum, vector<int> &colSum) {
    int m = rowSum.size(), n = colSum.size();
    int i = 0, j = 0;
    
    vector<vector<int>> res(m, vector<int>(n, 0));
    
    // Check if total sums are equal
    if (accumulate(rowSum.begin(), rowSum.end(), 0) != 
        accumulate(colSum.begin(), colSum.end(), 0)) {
        return {{0}};
    }
    
    // Fill the matrix greedily
    while (i < m && j < n) {
        res[i][j] = min(rowSum[i], colSum[j]);
        rowSum[i] -= res[i][j];
        colSum[j] -= res[i][j];
        
        if (rowSum[i] == 0) i++;
        else j++;
    }
    
    return res;
}

int main() {
    vector<int> rowSum = {1, 7, 2, 4, 5};
    vector<int> colSum = {3, 4, 7, 2, 2, 1};
    
    vector<vector<int>> res = generateMatrix(rowSum, colSum);
    
    if (res[0][0] == 0) {
        cout << "\nNo matrix possible with the given rowSum and colSum arrays.\n";
    } 
    else {
        cout << "\nGenerated matrix is:\n";
        for (auto &row : res) {
            for (int val : row) cout << setw(3) << val;
            cout << "\n";
        }
    }
    
    return 0;
}




