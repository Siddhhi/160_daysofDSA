/*
    Title: Equilibrium Point in an Array (Brute Force Approach)

    Problem Statement:
        - Given an array of integers, find an index such that the sum of elements 
          to the left of it is equal to the sum of elements to the right.
        - Return the index if such a point exists, otherwise return -1.

    Author: Siddhi
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find equilibrium point (brute-force)
int equilibriumPoint(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) {
        int leftSum = 0, rightSum = 0;

        // Calculate left sum
        for (int j = 0; j < i; j++) {
            leftSum += arr[j];
        }

        // Calculate right sum
        for (int k = i + 1; k < n; k++) {
            rightSum += arr[k];
        }

        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 0, 3};
    int index = equilibriumPoint(arr, arr.size());

    if (index != -1) {
        cout << "Equilibrium point found at index: " << index << endl;
    } else {
        cout << "No equilibrium point found." << endl;
    }

    return 0;
}
