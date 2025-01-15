#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySum(int arr[], int n) {
    int maxSum = INT_MIN; // To store the maximum sum
    int currentSum = 0;   // To store the sum of the current subarray

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];              // Add the current element to the current sum
        maxSum = max(maxSum, currentSum);  // Update the maximum sum if the current sum is greater
        if (currentSum < 0) {
            currentSum = 0;                // Reset current sum if it becomes negative
        }
    }
    return maxSum;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = maxSubArraySum(arr, n);
    cout << "The maximum sum of a subarray is: " << maxSum << endl;

    return 0;
}
