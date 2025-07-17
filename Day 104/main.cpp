/*
    Title: Stock Span Problem

    Problem Statement:
        - Given a list of daily stock prices, calculate the span of stock’s price for all days.
        - The span of the stock’s price on a given day is defined as the maximum number of consecutive days 
          just before the current day for which the price of the stock was less than or equal to its price on the current day.


    Time Complexity:
        - O(n), where n is the number of days.

    Space Complexity:
        - O(n), for using a stack to store indices.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate stock span
vector<int> calculateSpan(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        res[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }

    return res;
}

// Main function for testing
int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = calculateSpan(prices);

    cout << "Stock span: ";
    for (int val : span) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
