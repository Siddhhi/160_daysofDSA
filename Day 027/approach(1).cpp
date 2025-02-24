/*
    Title: Merge Two Sorted Arrays Without Extra Space (Gap Method Approach)

    Description:
        - This program merges two sorted arrays `arr1` and `arr2` in **non-decreasing order**.
        - The merging is done **without using extra space**.
        - The first array (`arr1`) has the smallest elements, while the second array (`arr2`) holds the larger elements.

    Author: Siddhi
*/

#include <iostream>
#include <algorithm>  // For sorting
using namespace std;

// Function to merge two sorted arrays in place without extra space
void mergeArray(int arr1[], int size1, int arr2[], int size2) {
    int i = size1 - 1; // Pointer at last index of arr1
    int j = 0;         // Pointer at first index of arr2

    // Swap elements if arr1[i] > arr2[j] and move pointers
    while (i >= 0 && j < size2) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
        i--;
        j++;
    }

    // Sort both arrays to maintain order
    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);
}

// Driver function
int main() {
    int size1, size2;
    cout << "Enter the size of both arrays: ";
    cin >> size1 >> size2;

    int arr1[size1], arr2[size2];

    cout << "Enter the elements of the first sorted array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of the second sorted array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    // Function call to merge arrays
    mergeArray(arr1, size1, arr2, size2);

    // Output the merged arrays
    cout << "Array after merging: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}
