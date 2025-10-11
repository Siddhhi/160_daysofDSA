/*
    Title: Last Moment Before All Ants Fall Off a Plank

    Problem Statement:
        - A number of ants are walking on a plank of length `n`.
        - Each ant moves at a constant speed of 1 unit per second.
        - Some ants move to the left, others to the right.
        - When two ants meet, they effectively just pass through each other (swap directions),
          which means the result is the same as if they keep walking independently.
        - Find the **last moment (time)** before all ants fall off the plank.

    Author: Siddhi
*/


#include<bits/stdc++.h>
using namespace std;

int getLastMoment(int n ,vector<int> &left, vector<int>& right){
    int res = 0;
    for(int i =0;i<left.size();i++){
        res = max(res,left[i]);
    }
    
    for(int i =0;i<right.size();i++){
        res=max(res,n-right[i]);
    }
    
    return res;
}

int main(){
    int n = 4;
    vector<int> left = {2};
    vector<int> right = {0,1,3};
    
    cout<<"Last moment until all ants would get fall from plank : "<<getLastMoment(n,left,right);
    return 0;
    
}
