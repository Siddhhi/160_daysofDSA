/*
    Title: Decode Encoded String

    Problem Statement:
        - Given an encoded string, decode it.
        - The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times.
        - You may assume that the input string is always valid and contains only digits, letters, and square brackets.

    Author: Siddhi
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<string> strStack;
    stack<int> numStack;
    string currStr = "";
    int num = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0'); 
        } else if (ch == '[') {
            numStack.push(num);
            strStack.push(currStr);
            num = 0;
            currStr = "";
        } else if (ch == ']') {
            int repeat = numStack.top(); numStack.pop();
            string temp = "";
            for (int i = 0; i < repeat; i++) {
                temp += currStr;
            }
            currStr = strStack.top() + temp;
            strStack.pop();
        } else {
            currStr += ch;
        }
    }

    return currStr;
}

// Main function to test the code
int main() {
    string input = "3[a2[c]]";
    cout << "Decoded string: " << decodeString(input) << endl;
    return 0;
}
