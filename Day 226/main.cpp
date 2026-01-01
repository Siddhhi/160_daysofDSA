/*
    Title: Maximum Score from Jumping with K Distance

    Problem Statement:
        - You are given an integer array `arr` where each element represents a score.
        - You start at index 0 and want to reach the last index.
        - From index `i`, you can jump to any index `j` such that:
              i < j ≤ i + k
        - Each time you land on an index, you collect its value.
        - Your task is to find the **maximum total score** obtainable when reaching the end.

    Author: Siddhi
*/

#include <bits/stdc++.h>
using namespace std;

int getScore(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, INT_MIN);

    dp[n - 1] = arr[n - 1];
    deque<int> dq;
    dq.push_back(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        while (!dq.empty() && dq.front() > i + k) {
            dq.pop_front();
        }

        dp[i] = arr[i] + dp[dq.front()];

        while (!dq.empty() && dp[i] >= dp[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return dp[0];
}

int main() {
    vector<int> arr = {1, -1, -2, 4, -7, 3};
    int k = 2;

    cout << "Maximum score obtainable: " << getScore(arr, k) << endl;
    return 0;
}




