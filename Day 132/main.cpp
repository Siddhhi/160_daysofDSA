/* 
    Title: Longest String Chain (Dynamic Programming + Sorting)

    Problem Statement:
        - You are given a list of words.
        - A word `a` is a predecessor of word `b` if:
            • `b` has exactly one character more than `a`, AND
            • `a` can be formed by deleting exactly one character from `b`.
        - A string chain is formed by words where each word is a predecessor of the next.
        - Task: Find the length of the longest possible word chain.

    
        - O(n^2 * L), where:
            • n = number of words,
            • L = average word length (for predecessor check).

    Space Complexity:
        - O(n), for the DP array.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool predecessor(string& a, string& b){
    int m = a.size();
    int n = b.size();
    
    int i = 0, j = 0;
    
    if(m+1!=n){
        return false;
    }
    
    while(i<m && j<n){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    
    return i==m;
}


int longestWordChain(vector<string>& words){
    int n = words.size();
    
    vector<int> dp(n,1);
    sort(words.begin(),words.end());
    
    int res = 1;
    
    
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(predecessor(words[j],words[i])){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
        res =max(res,dp[i]);
    }
    
    return res;
}

int main(){
    
    vector<string> words = {"a","b","ab","abc","adbc"};
    
    cout<<"Longest word chain "<<longestWordChain(words);
    return 0;
}
