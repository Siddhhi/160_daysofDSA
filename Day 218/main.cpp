/*
    Title: Rearrange String So That No Two Adjacent Characters Are Same

    Problem Statement:
        - You are given a string `s` consisting of lowercase English letters.
        - Rearrange the characters of the string such that no two adjacent
          characters are the same.
        - If it is not possible to rearrange the string, return an empty string.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;


string rearrangeString(string s) {
    // code here
    int n  = s.size();
    
    unordered_map<char,int> freq;
    
    for(int i = 0;i<n;i++){
        freq[s[i]]++;
    }
    
    priority_queue<pair<int,char>> pq;
    
    for(char c = 'a' ; c<='z' ; c++){
        if(freq[c]>0){
            pq.push({freq[c],c});
        }
    }
    
    string res = "";
    
    pair<int, char> prev = {-1,'#'};
    
    while(!pq.empty()){
        pair<int,char> p = pq.top();
        pq.pop();
        
        res.push_back(p.second);
        
        if(prev.first > 0){
            pq.push(prev);
        }
        
        p.first--;
        prev = p;
    }
    
    if(res.size()!=n){
        return "";
    }
    return res;
}

int main() {
    string s = "aaabc";
    cout << rearrangeString(s);
    return 0;
}
