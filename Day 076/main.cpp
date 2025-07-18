/*
    Title: Generate All Permutations of Integer Array

    Problem Statement:
        - Given an array of integers, print all possible permutations.
        
    Author: Siddhi
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to print one permutation
void printVector(vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Recursive function to generate permutations
void permute(vector<int>& arr, int i, int n) {
    if (i == n) {
        printVector(arr);
        return;
    }

    for (int j = i; j < n; j++) {
        swap(arr[i], arr[j]);
        permute(arr, i + 1, n);
        swap(arr[i], arr[j]); // backtrack
    }
}

// Driver code
int main() {
    vector<int> arr = {1, 2, 4,3};
    cout << "All permutations of the array are:\n";
    permute(arr, 0, arr.size());
    return 0;
}
