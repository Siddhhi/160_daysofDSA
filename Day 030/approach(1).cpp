/*
    Title: Searching in a Rotated Sorted Array (Binary Search Approach)

    Description:
        - This program searches for an element in a **rotated sorted array**.
        - It finds the **pivot index** (smallest element) and then performs **binary search**
          on the appropriate half of the array.
        - The time complexity is **O(log n)**.

    Author: Siddhi
*/

#include <iostream>
using namespace std;

int findPivot(int arr[], int low, int high)
{
    while (low < high)
    {
        int mid = (low + high) / 2;

        // If mid element is greater than the last element, the pivot is on the right
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        // Otherwise, the pivot is on the left (including mid)
        else
        {
            high = mid;
        }
    }
    return low; // Pivot index
}

int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid; // Target found
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Search in the right half
        }
        else
        {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int search(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    // Step 1: Find the pivot index
    int pivot = findPivot(arr, low, high);

    // Step 2: If target is at pivot
    if (arr[pivot] == target)
    {
        return pivot;
    }

    // Step 3: Search in the appropriate half
    if (pivot == 0)
    {
        return binarySearch(arr, 0, size - 1, target); // Normal binary search if not rotated
    }

    if (arr[0] <= target)
    {
        return binarySearch(arr, 0, pivot - 1, target); // Search in left half
    }

    return binarySearch(arr, pivot, size - 1, target); // Search in right half
}

int main()
{
    int size, target;

    // Taking input for array size
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size]; // Declaring array

    // Taking input for array elements
    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Taking input for the target element
    cout << "Enter the target element: ";
    cin >> target;

    // Searching for the target
    int result = search(arr, size, target);

    // Output result
    if (result == -1)
    {
        cout << "Element is not present in the array.\n";
    }
    else
    {
        cout << "Element is present at index: " << result << ".\n";
    }

    return 0;
}
