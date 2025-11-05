/*
    Title: Closest Triplet Sum to Target

    Problem Statement:
        - Given an array `arr` and an integer `target`,
          find the sum of three integers in the array such that
          the sum is closest to the given target.
        - If multiple sums are equally close, return the maximum among them.

    Time Complexity:
        - O(n²): Outer loop O(n), inner two-pointer traversal O(n)
        - Sorting adds O(n log n)

    Space Complexity:
        - O(1): Only constant extra space used.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int closestSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    int minDiff = INT_MAX;
    int res = 0;
    
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;
        
        while (l < r) {
            int currSum = arr[i] + arr[l] + arr[r];
            int diff = abs(currSum - target);
            
            if (diff < minDiff) {
                minDiff = diff;
                res = currSum;
            } 
            else if (diff == minDiff) {
                res = max(res, currSum);
            }
            
            if (currSum < target)
                l++;
            else
                r--;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, -5, 12, -3, 8};
    int target = 14;
    
    int sum = closestSum(arr, target);
    
    cout << "The closest sum to target " << target << " is " << sum << endl;
    return 0;
}


