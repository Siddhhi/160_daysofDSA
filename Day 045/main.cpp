/*
    Title: Find Intersection of Two Arrays (Using Hashing)

    Problem Statement:
        - Given two integer arrays, find their intersection (i.e., common elements without duplicates).

    Author: Siddhi
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the intersection of two arrays
vector<int> intersection(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> as_set(a.begin(), a.end()); // Store unique elements of 'a'
    vector<int> res;
    
    for (int element : b) {
        if (as_set.count(element)) {
            res.push_back(element);
            as_set.erase(element); // Remove to ensure uniqueness in result
        }
    }
    
    return res;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 3, 5};
    
    vector<int> result = intersection(a, b);
    
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
