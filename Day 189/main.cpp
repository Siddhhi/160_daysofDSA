/*
    Title: Count Subarrays with Exactly K Distinct Integers

    Problem Statement:
        Given an array of integers and an integer K, find the total number of subarrays that contain 
        exactly K distinct integers.

    Author: 
*/


#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int>& arr, int k) {
    int n = arr.size();
    int res = 0;
    
    int left = 0, right = 0;
    unordered_map<int,int> freq;
    
    while(right < n) {
        freq[arr[right]]++;
        
        if(freq[arr[right]] == 1) {
            k--;
        }
        
        while(k < 0) {
            freq[arr[left]]--;
            if(freq[arr[left]] == 0) {
                k++;
            }
            left++;
        }
        
        res += (right - left + 1);
        right++;
    }
    
    return res;
}

int exactlyK(vector<int>& arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k - 1);
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    
    cout << "\nArray : ";
    for(int val : arr) {
        cout << val << " ";
    }
    
    cout << "\nK : " << k;
    
    int result = exactlyK(arr, k);
    
    cout << "\nNumber of subarrays having exactly " << k 
         << " distinct elements are : " << result << "\n";
    
    return 0;
}



