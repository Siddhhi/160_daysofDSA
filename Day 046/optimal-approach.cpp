/*
    Title: Find Union of Two Arrays (Using Hashing)

    Problem Statement:
        - Given two integer arrays, find their union (all unique elements from both arrays).
        
    Author: Siddhi
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to find the union of two arrays
vector<int> findUnion(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> res;
    
    // Insert elements of first array
    for (int num : a) {
        res.insert(num);
    }

    // Insert elements of second array
    for (int num : b) {
        res.insert(num);
    }

    // Convert set to vector
    return vector<int>(res.begin(), res.end());
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {5, 4, 9};

    vector<int> result = findUnion(a, b);

    cout << "Union: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
