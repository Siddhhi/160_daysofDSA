 /* 
    Title: Minimum Coin Change Problem (Dynamic Programming - Memoization)

    Problem Statement:
        - You are given:
            1. An array `coins[]` where each element represents the denomination of a coin.
            2. An integer `sum` representing the target value.
        - Find the minimum number of coins required to make the target sum.
        - If the target sum cannot be formed using given coins, return -1.
        - Each coin can be used **infinite times**.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
using namespace std;

 
const int inf = 1e9;
int minCoin(vector<int>&coins,int n,vector<vector<int>> &memo,int sum){
    
    if(sum<0){
        return inf;
    }
    if(sum==0){
        return 0;
    }
    
    if(n==0){
        return inf;
    }
    
    if(memo[n][sum]!=-1){
        return memo[n][sum];
    }
    
    int take = minCoin(coins,n,memo,sum-coins[n-1]);
    if(take!=inf){
        take++;
    }
    
    int notTake = minCoin(coins,n-1,memo,sum);
    
    memo[n][sum] = min(take,notTake);
    return memo[n][sum];
}



int minCoins(vector<int> &coins, int sum) {
    // code here
    int n = coins.size();
    
    vector<vector<int>> memo (n+1,vector<int>(sum+1,-1));
    
    memo[n][sum]=minCoin(coins,n,memo,sum);
    if(memo[n][sum]==inf){
        return -1;
    }
    
    return memo[n][sum];
}

int main(){
    
    vector<int> coins = {10,5,25};
    int sum = 30;
    cout<<"minimum coins needed to be exchanged : "<<minCoins(coins,sum);
    return 0;
}
