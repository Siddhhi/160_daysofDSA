/*
    Title: Check if a Pair Exists with a Given Sum using Hashing
    
    Problem Statement:
        - Given an array of integers, determine if there exist two numbers 
          that add up to a given target sum.

    Returns:
        - `true` if a pair exists with the target sum, otherwise `false`.

    Author: Siddhi
*/

#include <iostream>
#include <unordered_set>
using namespace std;

// Function to check if a pair exists with the given sum
bool checkSum(int arr[], int n, int target) {
    unordered_set<int> seen; // Hash set to store elements
    
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i]; // Find complement
        
        if (seen.count(complement)) { // Check if complement exists
            return true; // Pair found
        }
        
        seen.insert(arr[i]); // Insert current element into the set
    }
    return false; // No pair found
}

int main() {
    int n = 6;
    int arr[n] = {4, 1, 7, 8, 5, 9};
    int target = 12;

    if (checkSum(arr, n, target)) {
        cout << "True";
    } else {
        cout << "False";
    }
    
    return 0;
}
