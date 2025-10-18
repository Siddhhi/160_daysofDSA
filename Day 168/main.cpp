/*
    Title: Longest Prefix which is also a Suffix (LPS)

    Problem Statement:
        - Given a string `s`, find the length of the longest proper prefix 
          which is also a suffix of the string.
        - Proper prefix means it cannot be equal to the entire string itself.

    Time Complexity:
        - O(N), where N = length of string `s`

    Space Complexity:
        - O(N), for storing the LPS array

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int getLPSLength(string &s){
    int n = s.size();
    vector<int> lps(n, 0);
    
    int len = 0;
    int i = 1;
    
    while(i < n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[n - 1];
}

int main(){
    string s = "abcbaabcbaabc";
    cout << "Length of longest prefix which is also a suffix is : " << getLPSLength(s);
    return 0;
}

