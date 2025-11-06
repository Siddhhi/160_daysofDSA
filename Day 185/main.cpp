/*
    Title: Count Subarrays with At Most K Distinct Integers

    Problem Statement:
        - Given an integer array `arr` and an integer `k`,
          find the number of subarrays that contain at most K distinct integers.

    Author: 
*/

#include <bits/stdc++.h>
using namespace std;

int countAtMostK(vector<int> &arr, int k) {
    int n = arr.size();
    int res = 0;
    
    int left = 0, right = 0;
    unordered_map<int, int> freq;
    
    while (right < n) {
        freq[arr[right]]++;
        
        // A new distinct element reduces available distinct count
        if (freq[arr[right]] == 1)
            k--;
        
        // If more than k distinct, shrink window
        while (k < 0) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0)
                k++;
            left++;
        }
        
        // Add count of all valid subarrays ending at right
        res += (right - left + 1);
        right++;
    }
    
    return res;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    
    cout << "Count of subarrays with at most " << k 
         << " distinct elements: " << countAtMostK(arr, k) << endl;
    return 0;
}




