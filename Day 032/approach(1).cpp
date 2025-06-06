/*
    Title: Finding the K-th Missing Positive Number in a Sorted Array

    Description:
        - Given a sorted array of distinct positive integers, find the K-th missing positive integer.
        - The missing numbers start from 1.

    Author: Siddhi
*/

#include <iostream>
#include <set>
using namespace std;

int kthMissing(int arr[], int size, int k) {
    set<int> s(arr, arr + size); // Store array elements in a set for quick lookup
    
    int counter = 0; // Counts missing numbers
    int i = 0;       // Start checking numbers from 1

    while (counter < k) {
        i++; // Increment the number we are checking

        // If 'i' is not in the array, it is a missing number
        if (!s.count(i)) {
            counter++; // Count this missing number
        }
    }
    return i; // Return the k-th missing number
}

int main() {
    int size, k;

    // Taking input for array size
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size]; // Declare the array

    // Taking input for array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Taking input for k
    cout << "Enter the value of k: ";
    cin >> k;

    // Finding and displaying the k-th missing number
    cout << k << "-th missing element from the array is: " << kthMissing(arr, size, k) << endl;

    return 0;
}
