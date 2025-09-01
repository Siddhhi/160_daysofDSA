/* 
    Title: Boolean Parenthesization Problem 

    Problem Statement:
        - You are given a boolean expression consisting of operands {T, F} 
          and operators {&, |, ^}.
        - The task is to count the number of ways to parenthesize the 
          expression such that the final result evaluates to True.

    Author: Siddhi
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool evaluate(int n1, int n2, char op){
        if(op=='&'){
            return (n1&n2);
        }
        if(op=='|'){
            return (n1|n2);
        }
        if(op=='^'){
            return (n1^n2);
        }
        return -1;
    }
    
    int recFunction(int i , int j , string& s, vector<vector<vector<int>>> &memo, int req){
        if(i==j){
            if(s[i]=='T' && req==1){
                return 1;
            }
            else if(s[i]=='F' && req==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(memo[i][j][req]!=-1){
            return memo[i][j][req];
        }
        
        int ans = 0;
        
        for(int k = i+1;k<j;k+=2){
            int LF = recFunction(i,k-1,s,memo,0);
            int LT = recFunction(i,k-1,s,memo,1);
            int RF = recFunction(k+1,j,s,memo,0);
            int RT = recFunction(k+1,j,s,memo,1);
            
            
            if(evaluate(1,1,s[k])==req){
                ans = ans + (LT * RT);
            }
            if(evaluate(1,0,s[k])==req){
                ans = ans + (LT*RF);
            }
            if(evaluate(0,1,s[k]) == req){
                ans = ans + (LF*RT);
            }
            if(evaluate(0,0,s[k])==req){
                ans = ans + (LF*RF);
            }
        }
        memo[i][j][req] = ans;
        
        return memo[i][j][req];
        
    }
    
    int countWays(string &s) {
        // code here
        int n = s.size();
        
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        return recFunction(0,n-1,s,memo,1);
        
        
    }


int main(){
    
    string s = "T|F&T";
    cout<<countWays(s);
    
    return 0;
    

}


