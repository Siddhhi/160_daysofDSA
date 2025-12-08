/*
    Title: Count Nodes in a BST Within a Given Range [L, H]

    Problem Statement:
        - You are given the root of a Binary Search Tree (BST) and two integers L and H.
        - Your task is to count how many nodes in the BST have values within the range:
                     L ≤ node->data ≤ H
        - The BST property allows us to skip unnecessary subtrees and improve efficiency.

    Author:
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


int getCount(Node* root, int l, int h){
    if(root == nullptr){
        return 0;
    }
    
    if(root->data >= l && root->data <=h){
        return 1+ getCount(root->left,l,h) + getCount(root->right,l,h);
    }
    
    else if(root->data > h){
        return getCount(root->left,l,h);
    }
    else{
        return getCount(root->right,l,h);
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);
    
    int l = 5;
    int h = 45;
    
    int countNode = getCount(root, l,h);
    cout<<"Number of node lies in range ("<<l<<" , "<<h<<") : ";
    cout<<countNode<<"\n";
    return 0;

}


