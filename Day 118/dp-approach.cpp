/* 
    Title: Coin Change Problem (Recursive Approach)

    Problem Statement:
        - You are given:
            1. A set of coins with given denominations `coin[]`.
            2. An integer `sum` representing the target value.
        - You need to count the number of distinct ways to make up the given sum
          using the available coins.
        - Each coin can be used **infinite times**.

    Author: Siddhi
*/


#include<iostream>
#include<vector>
using namespace std;

int function(vector<int> coin,int sum,int n,vector<vector<int>> memo){
    if(sum==0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    
    if(memo[sum][n]!=-1){
        return memo[sum][n];
    }
    
    int pick = function(coin,sum-coin[n-1],n,memo);
    int notPick = function(coin,sum,n-1,memo);
    
    return pick + notPick;
}

int countWays(vector<int> &coin, int sum,int n){
    
    vector<vector<int>> memo (sum+1,vector<int>(n+1,-1));
    
    memo[sum][n]=function(coin,sum,n,memo);
    
    return memo[sum][n];

}

int main(){
    
    vector<int> coin = {5,2,3,6};
    int sum = 10;
    int n = coin.size();
    cout<<"Ways : "<<countWays(coin,sum,n);
    return 0;
}
