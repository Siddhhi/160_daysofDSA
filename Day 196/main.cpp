/*
    Title: Count X-Axis Crossings in a Cumulative Sum Graph

    Problem Statement:
        - You are given an integer array representing values added sequentially.
        - Imagine plotting a graph of the cumulative sum of this array.
        - You must count how many times the cumulative-sum curve
          **touches or crosses the X-axis**.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

int touchedAxis(vector<int> &arr){
    int res = 0,sum = 0;
    int size = arr.size();
    for(int i = 0;i<size;i++){
        if(sum>0 && sum+arr[i]<=0){
            res++;
        }
        else if(sum<0 && sum+arr[i]>=0){
            res++;
        }
        sum+=arr[i];
    }
    return res;
}

int main(){
    vector<int> arr = {1,-4,2,-9,10,3,-5,2,-7,-6,11};
    cout<<"Number of times graph cuts the X-axis : "<<touchedAxis(arr);
    return 0;
}
