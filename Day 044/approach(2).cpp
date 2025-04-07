/*
    Title: Find Unique Triplets with Sum Zero using Hashing

    Problem Statement:
        - Given an array of integers, find all unique triplets whose sum equals zero.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

// Function to find and print all unique triplets that sum to zero
void findTriplets(int arr[], int n) {
    set<vector<int>> resSet;  // Stores unique triplets

    for (int i = 0; i < n - 1; i++) {
        unordered_set<int> seen;  // Stores elements for the current iteration
        
        for (int j = i + 1; j < n; j++) {
            int complement = -(arr[i] + arr[j]);
            
            if (seen.count(complement)) {
                vector<int> triplet = {arr[i], arr[j], complement};
                sort(triplet.begin(), triplet.end());  // Sort to maintain uniqueness
                resSet.insert(triplet);
            }
            
            seen.insert(arr[j]);
        }
    }

    // Printing unique triplets
    for (const auto& triplet : resSet) {
        cout << triplet[0] << " , " << triplet[1] << " , " << triplet[2] << "\n";
    }
}

int main() {
    int n = 7;
    int arr[n] = {4, 1, 7, -8, -5, 9,-4};
    
    findTriplets(arr, n);
    
    return 0;
}
