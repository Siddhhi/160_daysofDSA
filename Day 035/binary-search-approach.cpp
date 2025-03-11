/*
    Title: Find K-th Smallest Element in Two Sorted Arrays (Binary Search Approach)
    
    Problem Statement:
        - Given two sorted arrays, find the k-th smallest element in their merged sorted form.
        - The arrays are independently sorted, and we need an efficient way to find the k-th smallest element.

    Time Complexity: **O(log(min(size1, size2)))**
    Space Complexity: **O(1)** (No extra space used)

    Author: Siddhi
*/

#include <iostream>
#include <algorithm>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

int findKth(int arr1[], int arr2[], int size1, int size2, int k) {
    // Ensure binary search is performed on the smaller array
    if (size1 > size2) {
        return fi
