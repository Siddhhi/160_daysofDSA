/*
    Title: Gas Station Problem (Circular Tour)

    Problem Statement:
        - There are N gas stations arranged in a circular route.
        - Two arrays are given:
            • gas[i]  → amount of fuel available at station i
            • cost[i] → fuel required to travel from station i to (i+1)th station
        - You start with an empty fuel tank at some station.
        - Task: Find the index of the starting gas station from which you can complete
          a full circular tour of all stations. If no such station exists, return -1.

    Author: 
*/

#include <iostream>
#include<vector>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    
    int leftGas = 0;
    int startIdx = 0;
    
    for(int i =0;i<n;i++){
        leftGas = leftGas + gas[i] - cost[i];
        
        if(leftGas<0){
            leftGas = 0;
            startIdx = i+1;
        }
    }
    
    if(startIdx == n){
        return -1;
    }
    
    leftGas = 0;
    
    for(int i = 0;i<n;i++){
        
        int idx = (i+startIdx)%n;
        leftGas = leftGas +gas[idx]-cost[idx];
        if(leftGas<0){
            return -1;
        }
    }
    
    return startIdx;
}

int main()
{
    vector<int> gas = {3,7,5,2,6,16,5,5,38,4,4,9,7,4,3,5,7};
    vector<int> cost = {6,5,9,3,14,9,13,3,1,14,11,8,10,7,4,4,9};

    cout<<"Trip can be start from station "<<startStation(gas,cost)+1;
    return 0;
}
