/* 
    Title: Matrix Chain Multiplication.

    Problem Statement:
        - Given a sequence of matrices, we want to multiply them together
          in such a way that the total number of scalar multiplications 
          is minimized.
        - The order of multiplication affects the total cost, but the 
          final result (matrix dimensions) remains the same.
        - Input is given as an array 'arr' of dimensions, where the 
          ith matrix has dimensions arr[i-1] x arr[i].

    Author: Siddhi
*/


#include<iostream>
#include<vector>

using namespace std;
#define MAX_INT  10000000

int recFunction(int i ,int j, vector<int>& arr, vector<vector<int>> &memo){
    if(i+1==j){
        return 0;
    }
    
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    
    int res = MAX_INT;
    
    for(int k = i+1;k<j;k++){
        int curr = recFunction(i,k,arr,memo) + recFunction(k,j,arr,memo) + (arr[i]*arr[j]*arr[k]);
        res = min(curr,res);
    }
        memo[i][j]=res;
        return memo[i][j];
    
    
}

int minOperation(vector<int>& arr){
    int n = arr.size();
    
    vector<vector<int>> memo(n,vector<int>(n,-1));
    
    memo[0][n-1]=recFunction(0,n-1,arr,memo);
    return memo[0][n-1];
}

int main(){
    
    vector<int> arr = {10,30,5,60};
    
    cout<<"Minimum number of operation to multiply these matrices : "<<minOperation(arr);
    return 0;
}
