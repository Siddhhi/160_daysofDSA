/*
    Title: Find Floor Square Root Using Binary Search

    Problem Statement:
        - Given a non-negative integer `n`, find the **floor value** of its square root.
        - The floor square root of `n` is the largest integer `x` such that `x * x <= n`.

    Example:
        Input:
            n = 17
        Process:
            mid = 9 → 3*3=9 <=17 ✔ (res=3)
            mid = 13 → 4*4=16 <=17 ✔ (res=4)
            mid = 15 → 5*5=25 >17 ❌ (move left)
        Output:
            ✅ Floor square root = 4

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

