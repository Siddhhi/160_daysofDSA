/*
    Title: Longest Subarray Where Elements Greater Than k Are in Majority

    Problem Statement:
        - You are given an integer array `arr` and an integer `k`.
        - Consider a subarray valid if the number of elements strictly greater than `k`
          is MORE than the number of elements less than or equal to `k` in that subarray.
        - Your task is to find the LENGTH of the longest such subarray.

        Transform:
            1 (<=3) → -1
            2 (<=3) → -1
            3 (<=3) → -1
            4 (>3)  → +1
            5 (>3)  → +1
            3 (<=3) → -1
            2 (<=3) → -1

        Running sum and logic:
            i=0: sum=-1 → store sum=-1 at i=0
            i=1: sum=-2 → store sum=-2 at i=1
            i=2: sum=-3 → store sum=-3 at i=2
            i=3: sum=-2 → already seen, check sum-1=-3 at i=2 → length=3-2=1
            i=4: sum=-1 → check sum-1=-2 at i=1 → length=4-1=3  (longest so far)
            i=5: sum=-2 → check sum-1=-3 at i=2 → length=5-2=3
            i=6: sum=-3 → no better than previous

        Longest valid subarray length = 3.

    Time Complexity:
        - O(n), single pass through the array.

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


