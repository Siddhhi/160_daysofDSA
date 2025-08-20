/* 
    Title: Minimum Jumps to Reach End of Array (Dynamic Programming - Tabulation)

    Problem Statement:
        - You are given an array `arr[]` of size `n`.
        - Each element `arr[i]` represents the maximum number of steps 
          you can jump forward from index `i`.
        - Starting from index 0, find the **minimum number of jumps** 
          required to reach the last index.
        - If the last index cannot be reached, return -1.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
using namespace std;


int minJumps(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,n+1);
    
    dp[0]=0;
    for(int i =1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j]+j>=i){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    
    if(dp[n-1]==n+1){
        return -1;
    }
    
    return dp[n-1];
    
    
}
int main(){
    vector<int> arr = {1,3,2,4,5,2,3,1,9,3,2,1,3,2,1};
    cout<<"No of minimum jumps to reach the end of the array :"<<minJumps(arr);
    return 0;
}
