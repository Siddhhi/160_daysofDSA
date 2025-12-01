/*
    Title: Generate All Possible Words from Phone Digits (T9 Keypad Combinations)

    Problem Statement:
        - Given an array of digits (0–9), return all possible character combinations
          that these digits can represent using the mobile keypad mapping.
        - Digits 2–9 map to letters (like old Nokia keypad):
                2 → abc
                3 → def
                4 → ghi
                5 → jkl
                6 → mno
                7 → pqrs
                8 → tuv
                9 → wxyz
        - Digits 0 and 1 do not map to any characters and should be skipped.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

void possibleWordsRec(vector<int>& arr, int i, vector<string>& padMap,
                      vector<string>& res, string &prefix) {
    
    if(i == arr.size()){
        res.push_back(prefix);
        return;
    }
    
    int digit = arr[i];
    
    if(digit < 2 || digit > 9){
        possibleWordsRec(arr, i+1, padMap, res, prefix);
        return;
    }
    
    for(char ch : padMap[digit]){
        prefix.push_back(ch);
        possibleWordsRec(arr, i+1, padMap, res, prefix);
        prefix.pop_back();
    }
}

vector<string> possibleWords(vector<int>& arr){
    vector<string> res;
    string prefix = "";
    
    vector<string> padMap = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    possibleWordsRec(arr, 0, padMap, res, prefix);
    
    return res;
}

int main(){
    vector<int> arr = {3,6,4};
    vector<string> combinations = possibleWords(arr);
    
    cout << "[ ";
    for(auto s : combinations){
        cout << s << " ";
    }
    cout << "]";
    
    return 0;
}


