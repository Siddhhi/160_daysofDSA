/* 
    Title: Best Time to Buy and Sell Stock with At Most 2 Transactions 
           (Recursion + Memoization)

    Problem Statement:
        - You are given an array `prices[]` where `prices[i]` is the stock price on day `i`.
        - You are allowed to complete at most 2 transactions.
        - Each transaction consists of exactly one buy and one sell.
        - Find the maximum profit possible.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int recFunction(int i, int n, int k, int buy, vector<vector<vector<int>>> &memo, vector<int> &prices){
        if(i==n || k==0){
            return 0;
        }
        
        if(memo[i][k][buy]!=-1){
            return memo[i][k][buy];
        }
        
        int res = recFunction(i+1,n,k,buy,memo,prices);
        
        if(buy){
            res = max(res,recFunction(i+1,n,k,0,memo,prices)-prices[i]);
        }
        else{
            res = max(res,recFunction(i+1,n,k-1,1,memo,prices)+prices[i]);
        }
        
        
        return memo[i][k][buy]=res;
    }
int maxProfit(vector<int> &prices) {
    // code here
    int k =2;
    int n = prices.size();
    
    vector<vector<vector<int>>> memo(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
    
    memo[0][k][1]=recFunction(0,n,k,1,memo,prices);
    return memo[0][k][1];
}

int main(){
    
    vector<int> prices= {10,15,20,5,60,10,80};
    cout<<"Maximum profit you can achieve in 2 transactions "<<maxProfit(prices);
    return 0;

}


