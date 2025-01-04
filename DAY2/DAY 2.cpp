#include <iostream>
using namespace std;

/**
 * Function to move zeros in the array by swapping them with other elements.
 * The goal is to rearrange the array such that all zeros are moved 
 * to a specific position while maintaining the structure of other elements.
 * 
 * @param arr[]: The input array
 * @param size: The size of the array
 */
void swapZeroR(int arr[], int size) {
    int count = 1; // Start swapping from index 1
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) { // If the current element is zero
            // Swap the current element with arr[count]
            arr[i] = arr[count];
            arr[count] = 0;
        }
        count++; // Move to the next index
        if (count >= size) {
            return; // Prevent out-of-bounds access
        }
    }
}

int main() {
    int size;
    
    // Input array size
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int A[size];
    
    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }
    
    // Call the function to move zeros in the array
    swapZeroR(A, size);
    
    // Output the modified array
    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}
