/*
    Title: Find Floor Square Root Using Binary Search

    Problem Statement:
        - Given a non-negative integer `n`, find the **floor value** of its square root.
        - The floor square root of `n` is the largest integer `x` such that `x * x <= n`.

    Time Complexity:
        - O(log N): Binary search reduces the search space by half each step.

    Space Complexity:
        - O(1): Constant extra space.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int res = 0;
    int low = 1;
    int high = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (1LL * mid * mid <= n) { // prevent integer overflow
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

int main() {
    int n = 17;
    cout << "The floor square root of " << n << " is: " << floorSqrt(n) << "\n";
    return 0;
}


