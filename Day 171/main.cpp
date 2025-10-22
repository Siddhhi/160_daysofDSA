/*
    Title: Form the Largest Number from an Array of Integers

    Problem Statement:
        - Given an array of non-negative integers, arrange them such that they form the largest possible number.
        - The result should be returned as a string because the formed number can be very large.

    Space Complexity:
        - O(N) for storing string representations.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

bool myComp(string &a, string &b) {
    return (a + b) > (b + a);
}

string largestNumber(vector<int>& arr) {
    vector<string> numbers;
    
    for (int x : arr) {
        numbers.push_back(to_string(x));
    }
    
    sort(numbers.begin(), numbers.end(), myComp);
    
    if (numbers[0] == "0") {
        return "0";
    }
    
    string res;
    for (string ele : numbers) {
        res += ele;
    }
    
    return res;
}

int main() {
    vector<int> arr = {45, 3, 9, 867, 4, 90};
    cout << "Largest number that can be formed from the given array is " << largestNumber(arr);
    return 0;
}

