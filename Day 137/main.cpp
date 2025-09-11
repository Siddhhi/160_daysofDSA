/*
    Title: Maximum Number of Partitions of a String

    Problem Statement:
        - Given a string s, partition it into as many parts as possible 
          so that each letter appears in at most one part.
        - Return the maximum number of such partitions.

 
    Output:
        - Returns the maximum number of partitions possible.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;



int maxPartitions(string &s) {
    int n = s.size();
    int ans = 0;
    
    unordered_map<char,int> map;
    
    for(int i = 0;i<n;i++){
        map[s[i]]=i;
    }
    
    int last=-1;
    
    for(int i = 0;i<n;i++){
        last = max(last,map[s[i]]);
        
        if(last==i){
            ans++;
        }
    }
    
    return ans;
    
}

    
int main(){
    
    string s = "abccbsfdzjjq";
    
    cout<<"Maximum partition of this string : "<<maxPartitions(s);
    return 0;

}


