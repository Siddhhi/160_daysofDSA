/*
    Title: Print a Matrix in Spiral Order (Efficient Approach)
    
    Problem Statement:
        - Given an M x N matrix, print its elements in **spiral order**.
        - Start from the **top-left** and move in a clockwise spiral.

    Author: Siddhi
*/

#include <iostream>
#include <vector>
using namespace std;

void print_spiral(vector<vector<int>>& arr, int m, int n) {
    vector<int> res;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Move left to right
        for (int i = left; i <= right; i++) {
            res.push_back(arr[top][i]);
        }
        top++;

        // Move top to bottom
        for (int i = top; i <= bottom; i++) {
            res.push_back(arr[i][right]);
        }
        right--;

        // Move right to left (if still within bounds)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                res.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        // Move bottom to top (if still within bounds)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                res.push_back(arr[i][left]);
            }
            left++;
        }
    }

    // Print the spiral order result
    for (int val : res) {
        cout << val << "  ";
    }
    cout << endl;
}

int main() {
    int m = 4, n = 3;
    vector<vector<int>> matrix = {
        {1,  2,  3},
        {5,  6,  7},
        {9,  10, 11},
        {13, 14, 15}
    };

    print_spiral(matrix, m, n);
    return 0;
}
