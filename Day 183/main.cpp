/*
    Title: Triplet Sum in Array

    Problem Statement:
        - Given an array `arr` of integers and a target value `target`,
          determine whether there exists any three numbers in the array
          whose sum equals the target.
        - If such a triplet exists, return true; otherwise, return false.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

bool tripletSum(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    for (int i = 0; i < n - 2; i++) {
        int low = i + 1;
        int high = n - 1;
        int requiredSum = target - arr[i];
        
        while (low < high) {
            int currentSum = arr[low] + arr[high];
            if (currentSum == requiredSum) {
                return true;
            } 
            else if (currentSum < requiredSum) {
                low++;
            } 
            else {
                high--;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr = {4, 2, 1, 9, 34, 20, 6};
    int target = 32;
    
    if (tripletSum(arr, target)) {
        cout << "Sum " << target << " is possible with three elements of the array.\n";
    } 
    else {
        cout << "No triplet found with the sum " << target << ".\n";
    }
    return 0;
}



