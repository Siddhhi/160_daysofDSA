/*
    Title: Meeting Room Scheduler – 

    Problem Statement:
        - You are given an array of meeting time intervals where each interval is represented as [start, end].
        - Determine if a person can attend all meetings without any overlap.
        - If any two meetings overlap, return false; otherwise, return true.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

bool canAttend(vector<vector<int>> &arr){
    sort(arr.begin(), arr.end());
    
    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] < arr[i-1][1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> arr = {{1,5},{8,10},{6,7}};
    cout << "\nThe person " << (canAttend(arr) ? "can" : "can't") << " attend the meeting\n";
    return 0;
}




