/*
    Title: Generate All Subsets of a Set

    Problem Statement:
        - You are given an array of integers.
        - The task is to generate all possible subsets (the power set).
        - Each element may either be included or excluded from a subset.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &arr){
    int n = arr.size();
    int total = 1 << n;
    
    vector<vector<int>> res;
    
    for(int i = 0; i < total; i++){
        vector<int> subset;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                subset.push_back(arr[j]);
            }
        }
        res.push_back(subset);
    }
    
    return res;
}

int main(){
    vector<int> arr = {2,3,5};
    vector<vector<int>> res = subsets(arr);
    
    cout << "Subsets are: ";
    for(auto sub : res){
        cout << "{";
        for(auto elem : sub){
            cout << elem << " ";
        }
        cout << "}, ";
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &arr){
    int n = arr.size();
    int total = 1<<n;
    
    vector<vector<int>> res ;
    
    for(int i = 0;i<total;i++){
        vector<int> subset ;
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                subset.push_back(arr[j]);
            }
        }
        
        res.push_back(subset);
    }
    
    return res;
}

int main(){
    vector<int> arr = {2,3,5};
    vector<vector<int>> res = subsets(arr);
    
    cout<<"Subsets are : ";
    for( auto sub:res){
        cout<<"{";
        for(auto elem: sub){
            cout<<elem<<" ";
        }
        cout<<"}, ";
    }
    return 0;
}
