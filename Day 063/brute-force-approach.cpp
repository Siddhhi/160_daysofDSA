/*
    Title: Longest Subarray with Equal Number of 0s and 1s (Brute Force Approach)

    Problem Statement:
        - Given a binary array (containing only 0s and 1s),
          find the length of the longest subarray with equal number of 0s and 1s.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the longest subarray with equal 0s and 1s
int maxLen(vector<int> arr) {
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += (arr[j] == 1) ? 1 : -1;

            if (sum == 0) {
                res = max(res, j - i + 1);
            }
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};

    int longestLength = maxLen(arr);

    cout << "Length of longest subarray with equal 0s and 1s is: " << longestLength << endl;

    return 0;
}
