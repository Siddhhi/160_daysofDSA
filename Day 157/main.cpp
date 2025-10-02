/*
    Title: Total Hamming Distance Between All Pairs

    Problem Statement:
        - You are given an array of integers.
        - The Hamming Distance between two numbers is defined as the number of bit positions 
          at which the corresponding bits are different.
        - The task is to calculate the sum of Hamming Distances for all unique pairs of numbers in the array.

    Example:
        Input:
            arr = {4, 14}
        
        Process:
            - Binary forms: 4 (0100), 14 (1110)
            - Pair: (4,14) → differ in 2 positions → Hamming Distance = 2
        
        Output:
            2

    Time Complexity:
        - O(N * 32) = O(32N), since we check 32 bits for each number.
        - Much better than O(N^2).

    Space Complexity:
        - O(1) extra (besides a fixed-size 32-bit counter array).

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

int totHammingDist(vector<int>& arr) {
    int n = arr.size();
    vector<int> countone(32, 0);
    int count = 0;

    // Count how many numbers have '1' in each bit
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                countone[j]++;
            }
        }
    }

    // Contribution of each bit
    for (int i = 0; i < 32; i++) {
        count += countone[i] * (n - countone[i]);
    }

    return count;
}

int main() {
    vector<int> arr = {4, 14};
    int res = totHammingDist(arr);
    cout << "Total Hamming Distance: " << res << endl;
    return 0;
}
