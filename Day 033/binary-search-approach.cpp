/*
    Title: Aggressive Cows - Maximum Minimum Distance Placement (Binary Search Approach)

    Description:
        - Given 'N' stalls and 'K' cows, place the cows in the stalls such that the 
          **minimum distance** between any two cows is maximized.
        - Uses **binary search on answer** to efficiently find the optimal placement.


    Author: Siddhi
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool checkCow(int arr[], int k, int dist, int size) {
    int count = 1;     // Place the first cow at the first stall
    int prev = arr[0]; // Track the last placed cow's position

    for (int i = 1; i < size; i++) {
        if (arr[i] - prev >= dist) { // Check if we can place a cow here
            prev = arr[i];
            count++;

            if (count == k) { // If all cows are placed, return true
                return true;
            }
        }
    }
    return false;
}


int aggressiveCows(int arr[], int size, int k) {
    sort(arr, arr + size); // Sort stall positions

    int low = 1;                     // Minimum possible distance
    int high = arr[size - 1] - arr[0]; // Maximum possible distance
    int res = 0;                      // Store the best minimum distance

    while (low <= high) {
        int mid = (low + high) / 2; // Middle distance to test

        if (checkCow(arr, k, mid, size)) { // If possible, try for a larger distance
            res = mid;
            low = mid + 1;
        } else { // Otherwise, reduce the distance
            high = mid - 1;
        }
    }
    return res;
}

int main() {
    int size;
    cout << "Enter the number of stalls: ";
    cin >> size;
    int arr[size];

    // Taking input for stall positions
    cout << "Enter the positions of stalls: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of cows: ";
    cin >> k;

    // Finding and displaying the largest minimum distance
    cout << "Largest minimum distance: " << aggressiveCows(arr, size, k) << endl;
    return 0;
}
