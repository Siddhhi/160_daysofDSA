/*
    Title: Longest Subarray with Sum Divisible by K

    Problem Statement:
        - Given an integer array `arr` and an integer `k`,
          find the length of the **longest subarray** whose sum is divisible by `k`.
        - A subarray (i, j) is valid if:
                (arr[i] + arr[i+1] + ... + arr[j]) % k == 0

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayDivK(vector<int>& arr, int k) {
    int n= arr.size();
    int res = 0;
    unordered_map<int,int> prefIdx;
    int sum = 0;
    
    for(int i = 0;i<n;i++){
        sum = ((sum+arr[i])%k+k)%k;
        if(sum==0){
            res=i+1;
        }
        else if(prefIdx.find(sum)!=prefIdx.end()){
            res = max(res,i-prefIdx[sum]);
        }
        else{
            prefIdx[sum]=i;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {-2, 2, -5, 12, -11, -1, 7};
    int k = 3;
    cout<<"Longest length of subarray whose sum is divisible by "<<k<<" is : "<<longestSubarrayDivK(arr,k);
    
    return 0;

}




