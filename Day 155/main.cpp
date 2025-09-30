/*
    Title: Longest Word with All Prefixes (Using Trie)

    Problem Statement:
        - You are given a list of words.
        - A word is considered valid if all its prefixes are also present in the list.
        - The task is to find the longest valid word. 
        - If there are multiple such words of the same length, return the lexicographically smallest one.

    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        TrieNode * child[26];
        bool isEnd;
        
        TrieNode(){
            isEnd = false;
            fill(child,child+26,nullptr);
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        
        void insert(string &word){
            TrieNode* node = root;
            for(char ch : word){
                int idx = ch-'a';
                if(!node->child[idx]){
                    node->child[idx]=new TrieNode();
                }
                node=node->child[idx];
            }
            node->isEnd=true;
        }
        
        bool allPrefixExist(string &word){
            TrieNode * node = root;
            for(char ch:word){
                int idx = ch-'a';
                node=node->child[idx];
                if(!node || !node->isEnd){
                    return false;
                }
            }
            return true;
        }
};

string longestValidWord(vector<string> &words){
    Trie trie;
    
    for(string word: words){
        trie.insert(word);
    }
    
    string result = "";
    
    for(string word:words){
        if(trie.allPrefixExist(word)){
            if(word.size()>result.size() || (word.size()==result.size() && word<result)){
                result=word;
            }
        }
    }
    
    return result;
}


int main(){
    
    vector<string> words = {"a","banana","app","appl","ap","apply","apple"};
    string result = longestValidWord(words);
    cout<<"Longest Word with all Prefix : "<<result<<"\n";
    return 0;
}
