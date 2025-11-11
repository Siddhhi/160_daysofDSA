/*
    Title: Roman to Decimal Conversion

    Problem Statement:
        Given a string representing a Roman numeral,
        convert it into its corresponding decimal (integer) value.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;


int romanToDecimal(string &s) {
    // code here
    unordered_map<char,int> romanMap = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    
    int res = 0;
    
    for(int i =0 ;i<s.size();i++){
        if(i+1 < s.size() && romanMap[s[i]]<romanMap[s[i+1]]){
            res+=romanMap[s[i+1]] - romanMap[s[i]];
            i++;
        }
        else{
            res+=romanMap[s[i]];
        }
    }
    return res;
}

int main(){
    
    string romanNum = "LXXVI";
    cout<<"Roman to int conversion for string : "<<romanToDecimal(romanNum);
    return 0;

}


