// Given an array prices[] of length n, representing the prices of the stocks on different days.
// The task is to find the maximum profit possible by buying and selling the stocks on different days
// when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell.
// If it is not possible to make a profit then return 0.

#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX; // Minimum price seen so far
    int maxProfit = 0;      // Maximum profit achievable

    for (int price : prices) {
       
        minPrice = min(minPrice, price);

        
        int profit = price - minPrice;

       
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;

    return 0;
}
