/* 
    Title: Longest Palindromic Subsequence (LPS) - Length

    Problem Statement:
        - Given a string `s`, find the length of the longest subsequence that is a palindrome.
        - A subsequence is derived from another string by deleting some or no elements 
          without changing the order of the remaining characters.


    Space Complexity:
        - O(n^2), for memoization storage.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lps(int low, int high, string s, vector<vector<int>> memo) {
    if (low > high) {
        return 0;
    }
    
    if (low == high) {
        memo[low][high] = 1;
        return memo[low][high];
    }
    
    if (s[low] == s[high]) {
        memo[low][high] = 2 + lps(low + 1, high - 1, s, memo);
    } else {
        memo[low][high] = max(lps(low + 1, high, s, memo),
                              lps(low, high - 1, s, memo));
    }
    
    return memo[low][high];
}

int longestPalinSeq(string s) {
    int n = s.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    memo[0][n - 1] = lps(0, n - 1, s, memo);
    return memo[0][n - 1];
}

int main() {
    string s = "ababccdba";
    cout << "Length of the longest palindromic subsequence: " 
         << longestPalinSeq(s);
    return 0;
}


