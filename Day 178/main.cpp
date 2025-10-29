/*
    Title: Median of Two Sorted Arrays 

    Problem Statement:
        - You are given two sorted arrays `a[]` and `b[]` of sizes `n` and `m`.
        - You need to find the **median** of the two sorted arrays combined.
        - The median is the middle value if total elements are odd,
          or the average of the two middle values if total elements are even.
        - The combined array must be considered as if both arrays were merged and sorted.

    Author: Siddhi
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the median of two sorted arrays
double medianOf2(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    int m1 = -1, m2 = -1;

    for (int count = 0; count <= (m + n) / 2; count++) {
        m2 = m1;

        if (i != n && j != m) {
            // Pick the smaller element
            if (a[i] > b[j]) {
                m1 = b[j++];
            } else {
                m1 = a[i++];
            }
        } 
        else if (i < n) {
            m1 = a[i++];
        } 
        else {
            m1 = b[j++];
        }
    }

    // If total number of elements is odd
    if ((m + n) % 2 == 1) {
        return m1;
    } 
    // If even
    else {
        return (m1 + m2) / 2.0;
    }
}

// Driver code
int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};

    cout << "Median of the two sorted arrays is : " 
         << medianOf2(a, b) << "\n";

    return 0;
}




