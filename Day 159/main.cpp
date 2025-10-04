/*
    Title: Sum of XOR of All Subsets

    Problem Statement:
        - You are given an array of integers.
        - The task is to calculate the sum of XOR values of all possible subsets.
        - Example: If arr = {a, b}, subsets = {}, {a}, {b}, {a, b}
            XORs = 0, a, b, a^b → sum = 0 + a + b + (a^b).

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

int sumOfXor(vector<int> & arr){
    int n = arr.size();
    int bits = 0;
    
    for(int i = 0; i < n; i++){
        bits = bits | arr[i];
    }

    int ans = bits * (pow(2, n-1));
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    int xorSum = sumOfXor(arr);
    cout << "Sum of all subset XOR is : " << xorSum;
    return 0;
}





