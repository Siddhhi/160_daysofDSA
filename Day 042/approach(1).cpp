/*
    Title: Check if a Pair Exists with a Given Sum in an Array (Brute Force Approach)

    Approach:
        - Use a **brute force** approach with **nested loops** to check all possible pairs.
        - If a pair with the given sum is found, return `true`, otherwise return `false`.
    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

bool checkSum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
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
