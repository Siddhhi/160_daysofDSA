/*
    Title: Find Longest Consecutive Subsequence (Optimized Hashing Approach)

    Problem Statement:
        - Given an array of integers, find the length of the longest consecutive subsequence.

    Time Complexity:
        - **O(n)** (Each element is processed at most twice)

    Space Complexity:
        - **O(n)** (To store elements in the set)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the length of the longest consecutive subsequence
int longestSubsequence(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end()); // Insert all elements in a set for O(1) lookups
    int longest = 0;

    for (int num : arr) {
        // Check if it's the start of a new sequence
        if (!s.count(num - 1)) {
            int currentNum = num;
            int count = 1;

            // Count consecutive numbers
            while (s.count(currentNum + 1)) {
                currentNum++;
                count++;
            }
            longest = max(longest, count); // Update the longest sequence length
        }
    }
    return longest;
}

int main() {
    vector<int> a = {15, 13, 12, 14, 10, 9};

    cout << "Longest consecutive subsequence length: " << longestSubsequence(a) << endl;

    return 0;
}
