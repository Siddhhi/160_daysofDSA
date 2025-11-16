/*
    Title: Count Quadruples That Sum to a Target

    Problem Statement:
        - You are given an array of integers and a target value.
        - Your task is to count the number of UNIQUE quadruples (a, b, c, d)
              such that:  a + b + c + d = target
        - The order of elements must respect the index order in the array:
              i < j < k < l

    Author: Siddhi
*/


#include<bits/stdc++.h>
using namespace std;

int countQuadraple(vector<int>& arr,int target){
    int n = arr.size();
    int count = 0;
    unordered_map<int,int> freq;
    
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int temp = arr[i]+arr[j];
            
            count+=freq[target-temp];
        }
        
        for(int j = 0;j<i;j++){
            int temp = arr[i]+arr[j];
            freq[temp]++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,10,4,12,11,5,9};
    int target = 27;
    
    cout<<"Number of quadraples in array to produce target sum : "<<countQuadraple(arr,target);
    return 0;
}
