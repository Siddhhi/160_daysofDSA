/*
    Title: Sentence Palindrome Checker (Ignoring Non-Alphanumeric Characters)

    Problem Statement:
        - Given a sentence (string) that may contain letters, digits, spaces, and special symbols.
        - Check whether the sentence is a palindrome or not.
        - Ignore non-alphanumeric characters (e.g., spaces, punctuation, symbols).
        - Comparison should be case-insensitive.

    Author: 
*/


#include<bits/stdc++.h>
using namespace std;

bool isPalSen(string &s){
    int i = 0;
    int j = s.size()-1;
    
    while(i<=j){
        if(!isalnum(s[i])){
            i++;
        }
        else if(!isalnum(s[j])){
            j--;
        }
        else if(tolower(s[i])==tolower(s[j])){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string s = "ABC $. def01ASDF";
    
    if(isPalSen(s)){
        cout<<"Sentence is palindrome\n";
    }
    else{
        cout<<"Sentence is not palidrome\n";
    }
    return 0;
}
