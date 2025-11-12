/*
    Title: Maximum Distance Between Equal Elements in an Array

    Problem Statement:
        Given an array of integers, find the maximum distance between
        two equal elements in the array.  
        The distance is defined as the difference between their indices.
        
    Time Complexity: O(n)
    Space Complexity: O(n)

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> &arr){
    unordered_map<int,int> map;
    
    int res = 0;
    for(int i = 0;i<arr.size();i++){
        if(map.find(arr[i])==map.end()){
            map[arr[i]]=i;
        }
        else{
            res=max(res,i-map[arr[i]]);
        }
    }
    
    return res;
}

int main(){
    vector<int> arr= {1,2,3,2,4,9,2,6,1,8};
    cout<<"\nMaximum Distance Between Equal Elements in this Array : "<<maxDistance(arr);
    return 0;

}
