/*
    Title: Largest Zero-Sum Submatrix

    Problem Statement:
        - You are given a 2D matrix of integers (positive, negative, or zero).
        - Your task is to find the area (number of cells) of the largest
          rectangular submatrix whose sum of all elements is exactly 0.

    Author: Siddhi
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with sum = 0 in 1D array
int maxZeroSumSubarray(vector<int> &arr) {
    int prefSum = 0;
    int maxLength = 0;
    unordered_map<int,int> mp;  // prefixSum -> first index

    for (int i = 0; i < (int)arr.size(); i++) {
        prefSum += arr[i];

        // Case 1: subarray from 0..i has sum 0
        if (prefSum == 0) {
            maxLength = i + 1;
        }

        // Case 2: subarray from (mp[prefSum] + 1 .. i) has sum 0
        if (mp.find(prefSum) != mp.end()) {
            maxLength = max(maxLength, i - mp[prefSum]);
        } else {
            // store first occurrence of this prefix sum
            mp[prefSum] = i;
        }
    }
    return maxLength;
}

// Function to find the largest-area zero-sum submatrix
int zeroSumSubmat(vector<vector<int>>& mat) {
    int row = mat.size();
    if (row == 0) return 0;
    int col = mat[0].size();
    int maxArea = 0;

    // Fix top row
    for (int top = 0; top < row; top++) {
        vector<int> temp(col, 0);

        // Extend bottom row
        for (int bottom = top; bottom < row; bottom++) {
            // Add current row to temp
            for (int k = 0; k < col; k++) {
                temp[k] += mat[bottom][k];
            }

            // Find longest zero-sum subarray in temp
            int len = maxZeroSumSubarray(temp);
            int height = bottom - top + 1;
            maxArea = max(maxArea, height * len);
        }
    }
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        { 1,  2,  3},
        {-3, -2, -1},
        { 1,  7,  5}
    };

    cout << "Given matrix:\n";
    for (auto &row : mat) {
        for (auto val : row) {
            cout << setw(2) << val << " ";
        }
        cout << "\n";
    }

    int res = zeroSumSubmat(mat);
    cout << "\nLargest rectangular area with sum 0: " << res << "\n";

    return 0;
}




