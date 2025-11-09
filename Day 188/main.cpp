/*
    Title: Quadruple Sum in an Array

    Problem Statement:
        Given an array of integers and a target value,
        find all unique quadruples (a, b, c, d) such that:
                a + b + c + d = target

    Author: 
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> quadrapleSum(vector<int> &arr, int target) {
    vector<vector<int>> res;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int k = j + 1, l = n - 1;

            while (k < l) {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];

                if (sum == target) {
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                } 
                else if (sum < target) {
                    k++;
                } 
                else {
                    l--;
                }
            }
        }
    }

    if (res.empty())
        return {{0}};
    else
        return res;
}

int main() {
    vector<int> arr = {10, 2, 3, 4, 5, 7, 8, 9};
    int target = 23;

    cout << "\nArray : ";
    for (int val : arr) cout << val << " ";

    vector<vector<int>> res = quadrapleSum(arr, target);

    if (res[0][0] == 0) {
        cout << "\nNot possible to get target sum as " << target << "\n";
    } 
    else {
        cout << "\nPossible quadruples to get the target sum " << target << " are:\n";
        for (vector<int> x : res) {
            cout << "{ ";
            for (int val : x) cout << val << " ";
            cout << "}\n";
        }
    }

    return 0;
}




