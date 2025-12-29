/*
    Title: Sum of Maximum Elements of All Subarrays

    Problem Statement:
        - Given an integer array `arr`, find the sum of maximum elements
          of all possible subarrays.
        - For every subarray, identify its maximum element and add it to the total sum.

    Time Complexity:
        - O(n), each element is pushed and popped once.

    Space Complexity:
        - O(n), for stacks and auxiliary arrays.

    Applications:
        - Subarray maximum/minimum problems
        - Sliding window optimizations
        - Histogram and monotonic stack problems

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int sumOfMax(vector<int> &arr) {
    int n = arr.size();
    int res = 0;
    
    vector<int> left(n), right(n);
    stack<int> st;

    // Count elements to the left
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        left[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Count elements to the right
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        right[i] = st.empty() ? (n - i) : (st.top() - i);
        st.push(i);
    }

    // Calculate total sum
    for(int i = 0; i < n; i++){
        res += arr[i] * left[i] * right[i];
    }

    return res;
}

int main(){
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of maximum elements of all subarrays: " << sumOfMax(arr) << endl;
    return 0;
}



