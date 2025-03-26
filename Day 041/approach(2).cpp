/*
    Title: Set Matrix Zeroes (Optimized In-Place Approach)

    Problem Statement:
        - Implement a function to modify an M × N matrix such that if an element 
          is 0, its entire row and column are set to 0.
        - Optimize space usage by utilizing the first row and first column as markers.

    Author: Siddhi
*/

#include <iostream>
#include <vector>
using namespace std;

void setZeroMatrix(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();

    // Boolean variable to track whether the first column should be zeroed
    int c0 = 1;
    
    // Step 1: Identify zero positions and mark first row & column
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0;  // Mark first column
                
                if (j == 0) {
                    c0 = 0;  // Mark first column separately
                } else {
                    arr[0][j] = 0;  // Mark first row
                }
            }
        }
    }
    
    // Step 2: Update the matrix using markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }
    
    // Step 3: Zero out the first row if needed
    if (arr[0][0] == 0) {
        for (int j = 0; j < n; j++) {
            arr[0][j] = 0;
        }
    }
    
    // Step 4: Zero out the first column if needed
    if (c0 == 0) {
        for (int i = 0; i < m; i++) {
            arr[i][0] = 0;  // Fixed assignment issue
        }
    }
    
    // Step 5: Print the final matrix
    cout << "Matrix after setting zeroes:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << "\n";
    }
}

// Main function to test the setZeroMatrix function
int main() {
    int m = 4, n = 3;
    vector<vector<int>> matrix = {
        {0, 2, 0},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    
    // Call the function
    setZeroMatrix(matrix);

    return 0;
}
