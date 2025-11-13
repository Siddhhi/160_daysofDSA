/*
    Title: Count Pairs with Given Difference

    Problem Statement:
        - You are given an integer array `arr` and an integer `k`.
        - Find the total number of unordered pairs (i, j) such that:
            
                |arr[i] - arr[j]| = k

        - Each valid pair should be counted only once.

    Author: 
*/


#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int k) {
    int cnt = 0;
    unordered_map<int,int> map;
    
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(map.find(arr[i] + k) != map.end()){
            cnt += map[arr[i] + k];
        }
        if(map.find(arr[i] - k) != map.end()){
            cnt += map[arr[i] - k];
        }
        map[arr[i]]++;
    }
    
    return cnt;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;

    cout << "\nArray : ";
    for (int x : arr) cout << x << " ";

    cout << "\nDifference (k) : " << k;

    int result = countPairs(arr, k);

    cout << "\nNumber of valid pairs with difference " << k
         << " : " << result << "\n";

    return 0;
}



