/*
    Title: Next Greater Element in Circular Array

    Problem Statement:
        - Given a circular array of integers, find the next greater element 
          for each element in the array.
        - The next greater element of a number is the first greater number 
          to its right while traversing circularly.
        - If no such element exists, return -1 for that position.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    for(int i = 2*n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i % n]){
            st.pop();
        }

        if(i < n && !st.empty()){
            res[i] = st.top();
        }

        st.push(arr[i % n]);
    }
    return res;
}

int main(){
    vector<int> arr = {5, 7, 1, 2, 6};
    vector<int> res = nextGreater(arr);

    cout << "Next greater elements are: ";
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


