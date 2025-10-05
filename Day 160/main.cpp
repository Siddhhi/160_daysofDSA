/*
    Title: Missing Number in an Array using XOR

    Problem Statement:
        - You are given an array containing 'n-1' distinct numbers from 1 to n.
        - Find the missing number efficiently without using extra space.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &arr){
    int n = arr.size() + 1;
    int xor1 = 0, xor2 = 0;
    
    // XOR of numbers f


#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int> & arr){
    int n  = arr.size()+1;
    
    int xor1=0, xor2=0;
    
    for(int i = 1;i<=n;i++){
        xor1^=i;
    }
    
    for(int i =0;i<n-1;i++){
        xor2^=arr[i];
    }
    
    return xor2^xor1;
}

int main(){
    
    vector<int> arr = {1,3,2,5,6,9,8,4};
    
    cout<<"The missing number from array is : "<<missingNum(arr);
    return 0;
}
