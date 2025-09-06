/* 
    Title: Minimum Number of Platforms (Greedy + Sorting)

    Problem Statement:
        - You are given two arrays:
            • arr[] → arrival times of trains
            • dep[] → departure times of trains
        - Task: Find the minimum number of railway platforms required so that 
          no train has to wait.

   
    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumPlatform(vector<int> &arr, vector<int> &dep){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    
    int n = arr.size();
    
    int count = 0;
    int res = 0;
    int i = 0, j= 0;
    
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        
        res = max(res,count);
    }
    
    return res;
}

int main(){
    
    vector<int> arr = {900,910,1100,1135,1210,500};
    vector<int> dep = {930,1200,1400,1330,1650,1800};
    
    cout<<"Minimum number of platform woul be required for arrival and departures "<<
    minimumPlatform(arr,dep);
    return 0;
}
