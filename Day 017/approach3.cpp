/*
    Title: First Non-Repeating Character (Optimized Approach)
    
    Description:
        This program finds the first non-repeating character in a given string 
        using an optimized approach with an auxiliary array for character tracking.

    Author: Siddhi
*/

#include <iostream>
#include <climits>
#include <string>
using namespace std;

// Function to find the first non-repeating character in a string
char first_non_repeat(string s) {
    int arr[26];  
    fill(arr, arr + 26, -1); // Initialize array to -1 (not encountered)

    // First pass: Store first occurrence index or mark as repeated (-2)
    for (int i = 0; i < s.length(); i++) {
        if (arr[s[i] - 'a'] == -1) {
            arr[s[i] - 'a'] = i;  // Store first occurrence index
        } else {
            arr[s[i] - 'a'] = -2; // Mark as repeated
        }
    }

    // Find the minimum index among non-repeated characters
    int idx = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (arr[i] >= 0) {
            idx = min(arr[i], idx);
        }
    }

    // Return the first non-repeating character, or '$' if none found
    return (idx == INT_MAX) ? '$' : s[idx];
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    char result = first_non_repeat(s);
    if (result == '$') {
        cout << "No non-repeating character found.";
    } else {
        cout << "First non-repeating character in the entered string is: " << result;
    }
    return 0;
}
