/*
    Title: Running Median of a Stream

    Problem Statement:
        - Given an input stream of integers, return the median after reading each new integer.
        - Median is:
            - Middle element when the number of elements is odd.
            - Average of two middle elements when the number of elements is even.

    Author: Siddhi
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Function to compute running median
vector<double> getMedian(vector<int> &arr) {
    vector<double> result;
    vector<int> temp;
    
    for (int i = 0; i < arr.size(); i++) {
        temp.push_back(arr[i]);
        sort(temp.begin(), temp.end());

        int n = temp.size();
        if (n % 2 == 1) {
            result.push_back(temp[n / 2]);
        } else {
            double median = (temp[(n / 2) - 1] + temp[n / 2]) / 2.0;
            result.push_back(median);
        }
    }

    return result;
}

// Main function for testing
int main() {
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> medianArr = getMedian(arr);

    cout << "Running Median: ";
    for (double med : medianArr) {
        cout << med << " ";
    }
    cout << endl;

    return 0;
}
