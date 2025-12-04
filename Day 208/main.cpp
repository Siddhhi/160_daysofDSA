/*
    Title: Restore IP Addresses (Generate All Valid IPv4 Addresses)

    Problem Statement:
        - Given a string `s` containing only digits, return all possible valid IPv4 addresses
          that can be formed by inserting three dots into `s`.
        - An IPv4 address consists of four decimal numbers (each between 0 and 255) separated by dots.
        - Each of the four parts must not contain leading zeros unless the part is exactly "0".

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string& s){
    int n = s.size();
    
    if(n == 0) return false;
    if(n == 1){
        // single digit (including '0') is valid
        return true;
    }
    // leading zero is invalid for multi-digit parts
    if(s[0] == '0') return false;
    
    // numeric value must be <= 255
    int val = stoi(s);
    if(val > 255) return false;
    
    return true;
}

void generateIpRec(int index, vector<string>& res, string& s, string curr, int cnt){
    string temp = "";
    
    if(index >= (int)s.size()){
        return ;
    }
    
    if(cnt == 3){
        // last part: take the rest of the string
        temp = s.substr(index);
        if(temp.size() <= 3 && isValid(temp)){
            res.push_back(curr + temp);
        }
        return;
    }
    
    // try length 1, 2 and 3 for the current part
    for(int i = index; i < min(index + 3, (int)s.size()); i++){
        temp.push_back(s[i]);
        if(isValid(temp)){
            generateIpRec(i + 1, res, s, curr + temp + '.', cnt + 1);
        }
    }
}

vector<string> generateIp(string &s) {
    vector<string> res;
    generateIpRec(0, res, s, "", 0);
    return res;
}

int main(){
    string s = "25525511135";
    vector<string> ips = generateIp(s);
    cout << "Valid IPs from string \"" << s << "\":" << endl;
    for (auto &ip : ips) {
        cout << ip << endl;
    }
    return 0;
}



