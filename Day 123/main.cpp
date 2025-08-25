/* 
    Title: Buy and Sell Stock (Recursion + Memoization)

    Problem Statement:
        - You are given an array `prices[]` where `prices[i]` is the price of a stock on day `i`.
        - You are also given an integer `k`, the maximum number of allowed transactions.
        - A transaction is defined as one buy and one sell.
        - Find the maximum profit you can achieve under these constraints.

    Author: Siddhi
*/


#include<iostream>
#include<vector>
using namespace std;

int recFunction(int i,int n , int k, int buy, vector<int> &prices,vector<vector<vector<int>>> &memo){
    
        if(i==n){
            return 0;
        }
        
        if(k==0){
            return 0;
        }
        if(memo[i][k][buy]!=-1){
            return memo[i][k][buy];
        }
        
            int res=recFunction(i+1,n,k,buy,prices,memo);
       
            if(buy){
                res=max(res,recFunction(i+1,n,k,0,prices,memo) - prices[i]);
            }
            else{
                res=max(res,recFunction(i+1,n,k-1,1,prices,memo) + prices[i]);
            }
            memo[i][k][buy] = res;
        
        
        return memo[i][k][buy];
    }
    
    
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        
        vector<vector<vector<int>>> memo (n,vector<vector<int>> (k+1,vector<int>(2,-1)));
        
        memo[0][k][1]=recFunction(0,n,k,1,prices,memo);
        
        return memo[0][k][1];
    }

int main(){
    
    vector<int> arr = {10,6,24,35,60};
    int k = 2;
    cout<<"Maximum profit which can be acheived is : "<<maxProfit(arr,k);
    
    return 0;
}
