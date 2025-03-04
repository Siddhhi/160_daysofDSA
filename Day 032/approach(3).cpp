/*
    Title: Find the K-th Missing Positive Number in a Sorted Array (Binary Search Approach)

    Description:
        - This program finds the K-th missing positive number in a sorted array.
        - The array is assumed to contain unique sorted positive integers.
        - We use a **binary search** approach to efficiently find the missing number.

   
    Time Complexity:
        - **O(log n)** (Binary search reduces the search space efficiently)

    Space Complexity:
        - **O(1)** (Only a few extra variables used)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

int kthMissing(int arr[], int size, int k) {
    int low = 0;
    int high = size - 1;
    int res = size + k; // Default assumption for missing number

    while (low <= high) {
        int mid = (low + high) / 2;

        // If missing numbers before arr[mid] are more than k, search left
        if (arr[mid] > mid + k) {
            res = mid + k;
            high = mid - 1;
        }
        // Otherwise, search right
        else {
            low = mid + 1;
        }
    }
    return res;
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

    // Finding and displaying the K-th missing number
    cout << k << "-th missing element from the array is: " << kthMissing(arr, size, k) << endl;

    return 0;
}
