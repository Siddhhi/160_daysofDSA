/* 
    Title: Word Break Problem

    Problem Statement:
        - You are given a string `s` and a dictionary of words `dict[]`.
        - Task: Determine if `s` can be segmented into a sequence 
          of one or more dictionary words.
        - You may reuse dictionary words any number of times.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

bool wordBreak(string& s, vector<string>&dict){
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    
    unordered_set<string> wordSet(dict.begin(),dict.end());
    
    for(int i =1;i<n+1;i++){
        for(int j = 0;j<i;j++){
            if(dp[j] && wordSet.count(s.substr(j,i-j))){
                dp[i]=true;
                break;
            }
            
        }
    }
    
    return dp[n];
}

int main(){
    vector<string> dict = {"cats","dog","sand","dogs","cat","and"};
    string s = "catsanddogz";
    
    if(wordBreak(s,dict)){
        cout<<"Word can be break using dictionary word\n";
    }
    else{
        cout<<"Word can not be break\n";
    }
    return 0;
}
