/* 
    Title: Partition Problem.

    Problem Statement:
        - You are given an array `arr[]` of size `n`.
        - Determine whether the array can be partitioned into two subsets such that 
          the sum of both subsets is equal.

    Author: Siddhi
*/



#include<iostream>
#include<vector>
using namespace std;

bool subsetRec(int sum, vector<int> &arr,vector<vector<int>> &memo,int n ){
    if(sum == 0){
        return true;
    }
    if(sum<0){
        return false;
    }
    if(n==0){
        return false;
    }
    
    if(memo[sum][n]!=-1){
        return memo[sum][n];
    }
    
    return memo[sum][n]=subsetRec(sum-arr[n-1],arr,memo,n-1) || subsetRec(sum,arr,memo,n-1);
}

bool isSubsetSum(vector<int> &arr){
    int n = arr.size();
    
    int sum = 0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
    }
    
    if(sum%2==1){
        return 0;
    }
    
    sum = sum/2;
    vector<vector<int>> memo (sum+1,vector<int>(n+1,-1));
    memo[sum][n]=subsetRec(sum,arr,memo,n);
    
    return memo[sum][n];
    
}

int main(){
    
    vector<int> arr = {1,5,2,3,5,4};
    
    if(isSubsetSum(arr)){
        cout<<"The partition "<<" is possible";
    }else{
        cout<<"The partition"<< "is not possible";
    }
    
    return 0;
}
