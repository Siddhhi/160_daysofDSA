/* 
    Title: Stair Climbing - Count Number of Ways

    Problem Statement:
        - Given `n` stairs, you can climb either 1 step or 2 steps at a time.
        - Find the total number of distinct ways to reach the top.

   
    Time Complexity:
        - O(2^n) for the recursive approach (can be optimized using DP).

    Space Complexity:
        - O(n) due to function call stack in recursion.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

int stairClimbing(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return stairClimbing(n - 1) + stairClimbing(n - 2);
}

int main() {
    int stair = 5;
    cout << stairClimbing(stair);
    return 0;
}


