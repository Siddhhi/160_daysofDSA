/*
    Title: Check if a Pair Exists with a Given Sum using Two-Pointer Approach
    
    Problem Statement:
        - Given an array of integers, determine if there exist two numbers 
          that add up to a given target sum.

    Author: Siddhi
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if a pair exists with the given sum
bool checkSum(int arr[], int n, int target) {
    sort(arr, arr + n); // Step 1: Sort the array
    
    int left = 0, right = n - 1;
    while (left < right) { // Step 2: Use two pointers
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            return true; // Found a valid pair
        }
        if (sum < target) {
            left++; // Move left pointer to increase sum
        } else {
            right--; // Move right pointer to decrease sum
        }
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
