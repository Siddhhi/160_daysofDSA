/*
    Title: Count Subarrays with a Given Sum (Optimized Hashing Approach)

    Problem Statement:
        - Given an array of integers and a target sum `k`, find the number of subarrays whose sum equals `k`.

        - **O(n)** (Each element is processed once)

    Space Complexity:
        - **O(n)** (For storing prefix sum frequencies)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays with sum equal to k
int countSubarray(vector<int> arr, int k) {
    unordered_map<int, int> prefixSumFreq;
    
    int res = 0;       // Count of valid subarrays
    int currSum = 0;   // Current prefix sum
    
    for (int i = 0; i < arr.size(); i++) {
        currSum += arr[i];  // Update prefix sum
        
        // If prefix sum equals k, count this subarray
        if (currSum == k) {
            res++;
        }

        // Check if there exists a prefix sum that forms a valid subarray
        if (prefixSumFreq.count(currSum - k)) {
            res += prefixSumFreq[currSum - k];
        }

        // Store/update the frequency of the current prefix sum
        prefixSumFreq[currSum]++;
    }
    
    return res;
}

int main() {
    vector<int> arr = {11, 4, 4, -1, 15, 5, 2, 17, 12, 9, 7, 3};  
    int k = 19;

    // Print the count of subarrays whose sum is k
    cout << "The subarray count having sum " << k << " is " << countSubarray(arr, k) << endl;
    
    return 0;
}
