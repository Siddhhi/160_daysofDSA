/* 
    Title: Maximum Loot 

    Problem Statement:
        - You are given an array `arr[]` where each element represents the 
          amount of money stored in a house.
        - You cannot rob two adjacent houses (to avoid alerting the police).
        - Find the maximum amount of money you can loot.

    Author: Siddhi
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxLootRec(vector<int>& arr,int n , vector<int> &memo){
    if(n==0){
        return arr[0];
    }
    if(n==2){
        return max(arr[0],arr[1]);
    }
    
    if(memo[n]!=-1){
        return memo[n];
    }
    
    memo[n] = max(arr[n-1]+maxLootRec(arr,n-2,memo),maxLootRec(arr,n-1,memo));
    
    return memo[n];
}

int maxLoot(vector<int> &arr){
    int n = arr.size();
    
    vector<int> memo(n+1,-1);
    
    memo[n] = maxLootRec(arr,n,memo);
    return memo[n];
}

int main(){
    
    vector<int> prices= {10,15,20,5,60,10,80};
    cout<<"Maximum loot can be achieve is "<<maxLoot(prices);
    return 0;

}



