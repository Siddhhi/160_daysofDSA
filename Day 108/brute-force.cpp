/*
    Title: Maximum of All Subarrays of Size K

    Problem Statement:
        - Given an array of integers and an integer K, find the maximum element 
          for every contiguous subarray of size K.

    Author: Siddhi
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    vector<int> res;
    
    for (int i = 0; i <= arr.size() - k; i++) {
        int maxElem = arr[i];
        for (int j = 1; j < k; j++) {
            maxElem = max(maxElem, arr[i + j]);
        }
        res.push_back(maxElem);
    }
    return res;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 0, 5};
    int k = 3;

    vector<int> result = maxOfSubarrays(arr, k);

    cout << "Maximum of all subarrays of size " << k << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
