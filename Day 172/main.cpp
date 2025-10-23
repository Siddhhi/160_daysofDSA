/*
    Title: Minimum Increments to Make Array Elements Unique

    Problem Statement:
        - Given an integer array, make all elements unique by performing the minimum number of increment operations.
        - In one operation, you can increment any element by 1.
        - Find the minimum total increments required and the final modified array.

    Applications:
        - Useful in scheduling, ID assignment, and resource allocation problems
          where uniqueness is required.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int minIncrement(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] >= arr[i]) {
            cnt += arr[i - 1] - arr[i] + 1;
            arr[i] = arr[i - 1] + 1;
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 6, 2};
    
    cout << "Array : [ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
    
    int moves = minIncrement(arr);
    
    cout << "\nMinimum " << moves << " increments are required to make all elements unique.\n";
    
    cout << "\nAnd the array will become : [ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
    
    return 0;
}

