/*
    Title: Longest Subarray Where Elements Greater Than k Are in Majority

    Problem Statement:
        - You are given an integer array `arr` and an integer `k`.
        - Consider a subarray valid if the number of elements strictly greater than `k`
          is MORE than the number of elements less than or equal to `k` in that subarray.
        - Your task is to find the LENGTH of the longest such subarray.


    Space Complexity:
        - O(n), for the hash map storing first occurrence of each prefix sum.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0, ans = 0;
    unordered_map<int,int> mp;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            sum--;
        } else {
            sum++;
        }

        if (sum > 0) {
            ans = i + 1;
        } else {
            if (mp.find(sum - 1) != mp.end()) {
                ans = max(ans, i - mp[sum - 1]);
            }
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i; 
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 3, 2};
    int k = 3;

    int res = longestSubarray(arr, k);

    cout << "Length of longest subarray in which elements greater than " 
         << k << " are in majority: " << res << "\n";

    return 0;
}



