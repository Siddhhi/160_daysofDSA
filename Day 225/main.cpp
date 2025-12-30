/*
    Title: Minimum K Consecutive Bit Flips

    Problem Statement:
        - You are given a binary array `arr` consisting of 0s and 1s.
        - You are allowed to flip exactly `k` consecutive bits in one operation.
        - A flip means changing 0 → 1 and 1 → 0.
        - Your task is to determine the **minimum number of flips** required
          to make all elements of the array equal to 1.
        - If it is not possible, return `-1`.

    Author: Siddhi
*/

#include <bits/stdc++.h>
using namespace std;

int kBitFlips(vector<int>& arr, int k) {
    int n = arr.size();
    int res = 0;
    int flag = 0;
    queue<int> q;

    for(int i = 0; i < n; i++){
        if(i >= k){
            flag ^= q.front();
            q.pop();
        }

        if(flag == 1){
            arr[i] ^= 1;
        }

        if(arr[i] == 0){
            if(i + k > n){
                return -1;
            }
            res++;
            flag ^= 1;
            q.push(1);
        } else {
            q.push(0);
        }
    }
    return res;
}

int main(){
    vector<int> arr = {0, 1, 0};
    int k = 1;

    int result = kBitFlips(arr, k);
    cout << "Minimum number of flips required: " << result << endl;

    return 0;
}





