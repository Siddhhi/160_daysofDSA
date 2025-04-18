/*
    Title: Print a Matrix in Spiral Order
    
    Problem Statement:
        - Given an M x N matrix, print its elements in spiral order.
        - Start from the top-left corner and traverse in a clockwise spiral.

    Author: Siddhi
*/

#include <iostream>
#include <vector>
using namespace std;
#define N 100


void print_spiral(vector<vector<int>>& arr, int m, int n) {
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // Direction vectors (right, down, left, up)
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    int r = 0, c = 0, index = 0;

    for (int i = 0; i < (m * n); i++) {
        cout << arr[r][c] << "  ";
        vis[r][c] = true;

        int newR = r + dr[index];
        int newC = c + dc[index];

        // Check if the new position is within bounds and unvisited
        if (newR >= 0 && newR < m && newC >= 0 && newC < n && !vis[newR][newC]) {
            r = newR;
            c = newC;
        } else {
            // Change direction
            index = (index + 1) % 4;
            r += dr[index];
            c += dc[index];
        }
    }
}

int main() {
    int m = 4, n = 4;
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    print_spiral(matrix, m, n);
    return 0;
}
