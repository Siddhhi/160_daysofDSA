/*
    Title: Pair Sum in a Rotated Sorted Array

    Problem Statement:
        Given a **sorted and rotated array**, and an integer `target`, determine whether there exists a pair (arr[i], arr[j]) such that:
                arr[i] + arr[j] == target

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

bool pairInSortedArray(vector<int>& arr, int target) {
    int n = arr.size();
    int i;

    // Step 1: Find pivot where rotation happened
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) break;
    }

    int r = i;           // index of largest element
    int l = (i + 1) % n; // index of smallest element

    // Step 2: Use circular two-pointer technique
    while (l != r) {
        int sum = arr[l] + arr[r];

        if (sum == target) return true;

        if (sum > target)
            r = (r - 1 + n) % n;
        else
            l = (l + 1) % n;
    }

    return false;
}

int main() {
    vector<int> arr = {12, 15, 2, 5, 7, 9, 11};
    int target = 23;

    cout << "\nArray : ";
    for (int num : arr) cout << num << " ";

    cout << "\nTarget : " << target;

    if (pairInSortedArray(arr, target))
        cout << "\nPair sum with target " << target << " can be achieved from this array.\n";
    else
        cout << "\nTarget sum is not possible.\n";

    return 0;
}


