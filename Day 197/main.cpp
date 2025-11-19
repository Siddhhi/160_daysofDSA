/*
    Title: Count Subarrays With Sum Divisible by K

    Problem Statement:
        - Given an integer array `arr` and an integer `k`,
          count how many subarrays have a sum that is divisible by `k`.
        - A subarray (i, j) is valid if:
                (arr[i] + arr[i+1] + ... + arr[j]) % k == 0

    Core Idea:
        - Use prefix-sum modulo technique.
        - If two prefix sums have the same remainder mod k,
          then the subarray between them has sum divisible by k.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int subCount(vector<int> &arr, int k){
    int res = 0,n = arr.size();
    int sum = 0;
    unordered_map<int,int> prefCnt;
    for(int i = 0;i<n;i++){
        sum = ((sum+arr[i])%k+k)%k;
        if(sum == 0){
            res++;
        }
        res+=prefCnt[sum];
        prefCnt[sum]++;
    }
    return res;
}


int main(){
    vector<int> arr = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout<<"Number of subarray which has the sum divisible by "<<k<<" : "<<subCount(arr,k);
    return 0;
}
