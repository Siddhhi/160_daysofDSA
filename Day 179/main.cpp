/*
    Title: Rotate a Square Matrix by 180 Degrees

    Problem Statement:
        - Given an NxN matrix, rotate it **by 180 degrees in place**.
        - Rotation by 180° means each element at (i, j) moves to (n-1-i, n-1-j).

    Author: Siddhi
*/

#include <bits/stdc++.h>
using namespace std;

// Function to rotate a square matrix by 180 degrees
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();

    // Swap symmetric elements from top and bottom
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(mat[i][j], mat[n - 1 - i][n - 1 - j]);
        }
    }

    // If n is odd, reverse the middle row
    if (n % 2 == 1) {
        int mid = n / 2;
        for (int j = 0; j < n / 2; j++) {
            swap(mat[mid][j], mat[mid][n - j - 1]);
        }
    }
}

// Driver code
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    for (auto &row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    rotateMatrix(mat);

    cout << "\nMatrix after 180° rotation:\n";
    for (auto &row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    return 0;
}




