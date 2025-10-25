/*
    Title: Find Bitonic Point in an Array

    Problem Statement:
        - A **bitonic array** first increases and then decreases.
        - The task is to find the **maximum element** (bitonic point) in such an array.

    Example:
        Input:
            arr = [1, 2, 3, 7, 9, 800, 11, 7, 3, 2]
        
        Process:
            - The array increases till 800, then decreases.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int bitonicPoint(vector<int> &arr) {
    int n = arr.size();

    if (n == 1 || arr[0] > arr[1]) {
        return arr[0];
    }

    if (arr[n - 2] < arr[n - 1]) {
        return arr[n - 1];
    }

    int low = 1, high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return arr[mid];
        } else if (arr[mid] > arr[mid + 1]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return arr[high];
}

int main() {
    vector<int> arr = {1, 2, 3, 7, 9, 800, 11, 7, 3, 2};

    cout << "\nThe bitonic point of the array [ ";
    for (int x : arr) cout << x << " ";
    cout << "] is " << bitonicPoint(arr) << "\n";

    return 0;
}


