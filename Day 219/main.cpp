/*
    Title: Sort a Nearly Sorted (K-Sorted) Array Using Min Heap

    Problem Statement:
        - You are given an array where each element is at most `k` positions
          away from its correct position in the sorted order.
        - Such an array is called a **k-sorted** or **nearly sorted** array.
        - The task is to efficiently sort the array.

    Author: 
*/


#include<bits/stdc++.h>
using namespace std;

void nearlySorted(vector<int>& arr, int k ){
    int  n =arr.size();
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0 ; i<k ;i++){
        pq.push(arr[i]);
    }
    int i;
    for(i = k ; i<n;i++){
        pq.push(arr[i]);
        
        arr[i-k]=pq.top();
        pq.pop();
    }
    
    while(!pq.empty()){
        arr[i-k]=pq.top();
        pq.pop();
        i++;
    }
}

int main(){
    
    vector<int>arr = {2,3,1,4};
    int k =2;
    
    cout<<"Original Vector : [ ";
    for(int x : arr){
        cout<<x << " ";
    }
    cout<<" ]\n\n";
    
    nearlySorted(arr, k);
    
    cout<<"Sorted Vector : [ ";
    for(int x : arr){
        cout<<x << " ";
    }
    cout<<" ]\n";
    return 0;
}
