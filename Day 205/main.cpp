/*
    Title: Target Sum Combinations

    Problem Statement:
        - You are given an array of positive integers `arr` and a target sum `target`.
        - Each element in `arr` can be used **any number of times** (including zero).
        - The task is to find all unique combinations of elements from `arr` whose sum is exactly equal to `target`.
        - The order of elements inside a combination does not matter, and combinations are printed based on the recursion order.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

void makeCombination(vector<int> &arr, int sum, vector<int>& curr,
                     vector<vector<int>>& res, int i) {
    
    if (sum == 0) {
        res.push_back(curr);
        return;
    }
    
    if (sum < 0 || i >= (int)arr.size()) {
        return;
    }
    
    // Include current element (can be reused)
    curr.push_back(arr[i]);
    makeCombination(arr, sum - arr[i], curr, res, i);
    
    // Exclude current element and move to next
    curr.pop_back();
    makeCombination(arr, sum, curr, res, i + 1);
}

vector<vector<int>> targetSumCombination(vector<int>& arr, int target) {
    vector<int> curr;
    vector<vector<int>> res;
    makeCombination(arr, target, curr, res, 0);
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int target = 8;
    
    vector<vector<int>> res = targetSumCombination(arr, target);
    
    if (res.size() == 0) {
        cout << "No combination possible\n";
    } else {
        cout << "Possible Combinations:\n";
        for (auto curr : res) {
            cout << "[ ";
            for (auto elem : curr) {
                cout << elem << " ";
            }
            cout << "]\n";
        }
    }
    return 0;
}




