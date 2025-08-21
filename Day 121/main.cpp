/* 
    Title: Subset Sum Problem

    Problem Statement:
        - You are given an array `arr[]` of size `n` and a target sum `S`.
        - Determine whether there exists a subset of `arr` whose sum is exactly `S`.

    Author: Siddhi
*/



#include<iostream>
#include<vector>
using namespace std;

bool isSubsetSumRec(int sum, vector<int> &arr,int n,vector<vector<int>> &memo ){
    if(sum==0){
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
    
    bool pick = isSubsetSumRec(sum-arr[n-1],arr,n-1,memo);
    bool notPick = isSubsetSumRec(sum,arr,n-1,memo);
    
    return memo[sum][n] = pick||notPick;
}

bool isSubsetSum(int sum,vector<int> &arr){
    int n = arr.size();
    
    vector<vector<int>> memo (sum+1,vector<int>(n+1,-1));
    
    memo[sum][n]=isSubsetSumRec(sum,arr,n,memo);
    
    return memo[sum][n];
}

int main(){
    
    vector<int> arr = {1,5,4,7,2,3,11,36,8};
    int sum = 45;
    
    
    
    if(isSubsetSum(sum,arr)){
        cout<<"The sum "<<sum<<" is possible";
    }else{
        cout<<"The sum "<<sum<< " is not possible";
    }
    
    return 0;
}
