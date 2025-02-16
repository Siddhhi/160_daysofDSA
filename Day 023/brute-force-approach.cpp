/*
    Title: Inversion Count in an Array (O(n²) Approach)

    Description:
        - This program counts the number of **inversions** in an array.
        - An inversion is when **a[i] > a[j]** for **i < j**.

    Author: Siddhi
*/

#include <iostream>
using namespace std;

// Function to count inversions in an array
int count_inverse(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            { // Condition for inversion
                count++;
            }
        }
    }
    return count;
}

// Driver function
int main()
{
    int size;

    // Taking input for array size
    cout << "Enter the size of an array: ";
    cin >> size;

    int arr[size];

    // Taking input for array elements
    cout << "Enter the elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Displaying inversion count
    cout << "Inversion count of this array: " << count_inverse(arr, size);

    return 0;
}
