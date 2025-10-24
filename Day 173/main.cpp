/*
    Title: Find Lower Bound Index using Binary Search

    Problem Statement:
        - Given a sorted array `arr` and a target value `target`,
          find the **smallest index** such that `arr[index] >= target`.
        - If no such index exists, return the size of the array.
        
    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int result = arr.size();

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {2, 4, 5, 7, 11, 11, 25};
    int target = 11;

    cout << "The smallest index in the array where all elements are equal or greater than "
         << target << " is " << lowerBound(arr, target) << ".\n";
    
    return 0;
}




