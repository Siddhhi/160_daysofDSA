/*
    Title: Minimum Days to Make M Bouquets

    Problem Statement:
        - You are given an array `arr[]` where `arr[i]` represents the day on which the i-th flower blooms.
        - You need to make exactly `m` bouquets.
        - Each bouquet requires exactly `k` consecutive flowers that have bloomed on or before a certain day.
        - Find the **minimum number of days** required to make `m` bouquets.
        - If it is not possible to make `m` bouquets, return -1.
        
    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

// Helper function: Checks if we can make m bouquets in 'days' days
bool check(vector<int> &arr, int k, int m, int days) {
    int bouquet = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= days) {
            cnt++;
        } else {
            bouquet += cnt / k;
            cnt = 0;
        }
    }
    bouquet += cnt / k;
    return bouquet >= m;
}

// Main function: Finds minimum days required
int minDaysBloom(vector<int> &arr, int k, int m) {
    if ((long long)m * k > arr.size()) return -1; // Not enough flowers

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int res = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(arr, k, m, mid)) {
            res = mid;
            high = mid - 1; // Try to find a smaller valid day
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "Minimum number of days to make " << m 
         << " bouquets is : " << minDaysBloom(arr, k, m) << "\n";

    return 0;
}
