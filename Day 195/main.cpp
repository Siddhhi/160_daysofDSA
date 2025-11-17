/*
    Title: Group Shifted Strings (Using Hashing)

    Problem Statement:
        - You are given a list of lowercase strings.
        - Two strings belong to the same group if they are "shifted versions"
          of each other.
        - A shifted version means each character is shifted by the same amount.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;


string getHash(string s){
    int shifts=s[0]-'a';
    
    for(char &ch:s){
        ch=ch-shifts;
        if(ch<'a'){
            ch+=26;
        }
    }
    return s;
}
vector<vector<string>> groupShiftedString(vector<string> &arr) {
    // Your code here
    vector<vector<string>> res;
    
    unordered_map<string,int> mp;
    
    for(string s:arr){
        string hash = getHash(s);
        if(mp.find(hash)==mp.end()){
            mp[hash]=res.size();
            res.push_back({});
        }
        
        res[mp[hash]].push_back(s);
    }
    return res;
}


int main(){
    vector<string> arr = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    
    vector<vector<string>> res = groupShiftedString(arr);
    
    cout<<"\nThe groups of string based on shifting : \n\n";
    
    for (vector<string> &group : res) {
        for (string &s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;

}



