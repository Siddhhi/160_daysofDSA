/*
    Title: Count Number of Distinct Subsets in an Array

    Problem Statement:
        - You are given an array of integers.
        - A subset here is defined as a **sequence of consecutive integers**
          such that it forms a chain like:
              
                x, x+1, x+2, ... , y

        - The task is NOT to list all subsets, but simply to count how many
          such distinct consecutive-number subsets exist in the array.

        - A subset STARTS only when:
              (x - 1) does NOT exist in the array.
          Meaning: x is the beginning of a new consecutive chain.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

int minSet(vector<int> &arr){
    unordered_set<int> s(arr.begin(),arr.end());
    
    int count = 0;
    for(int x : arr){
        if(s.find(x-1)==s.end()){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,3,4,200,202,201,40,56};
    cout<<"Minimum number of subset of Consecutive numbers are "<<minSet(arr);
    return 0;

}



