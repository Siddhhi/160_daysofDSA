/*
    Title: Longest Subarray with Equal Number of 0s and 1s (Optimized Approach)

    Problem Statement:
        - Given a binary array (containing only 0s and 1s),
          find the length of the longest subarray with equal number of 0s and 1s.

    Author: Siddhi
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the longest subarray with equal 0s and 1s
int maxLen(vector<int> arr) {
    unordered_map<int, int> mp;
    int preSum = 0;
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {
        preSum += (arr[i] == 1) ? 1 : -1;

        if (preSum == 0) {
            res = i + 1;
        } else if (mp.count(preSum)) {
            res = max(res, i - mp[preSum]);
        } else {
            mp[preSum] = i;
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
