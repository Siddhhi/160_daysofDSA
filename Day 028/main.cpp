/*
    Title: Find Minimum Element in a Rotated Sorted Array (Binary Search Approach)

    Description:
        - This program finds the minimum element in a rotated sorted array.
        - A rotated sorted array is an array that was originally sorted in ascending order but was rotated at some pivot.
        - The minimum element is the pivot point.

    Author: Siddhi
*/

#include <iostream>
using namespace std;

// Function to find the minimum element in a rotated sorted array using binary search
int findMinimum(int arr[], int low, int high)
{
    while (low < high)
    {
        // If array is already sorted, return first element
        if (arr[low] < arr[high])
        {
            return arr[low];
        }

        int mid = (low + high) / 2;

        // If mid element is greater than the last element, min is in right half
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        // Otherwise, min is in left half
        else
        {
            high = mid;
        }
    }
    return arr[low]; // Return the minimum element
}

// Driver function
int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Function call to find the minimum element
    cout << "Minimum element in this rotated sorted array: " << findMinimum(arr, 0, size - 1) << endl;

    return 0;
}
