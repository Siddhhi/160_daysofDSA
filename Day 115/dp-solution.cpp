/* 
    Title: Stair Climbing - Count Number of Ways (Dynamic Programming)

    Problem Statement:
        - Given `n` stairs, you can climb either 1 step or 2 steps at a time.
        - Find the total number of distinct ways to reach the top.

    Author: Siddhi
*/

#include <iostream>
#include <vector>
using namespace std;

int countWays(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

int main() {
    int stair = 5;
    cout << countWays(stair);
    return 0;
}








