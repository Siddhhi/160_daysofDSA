/*
    Title: Check if a Binary Tree is Height Balanced

    Problem Statement:
        - You are given the root of a binary tree.
        - A binary tree is considered *height-balanced* if:
                For every node, the absolute difference between the height 
                of its left and right subtree is NOT more than 1.
        - Determine whether the given binary tree is height-balanced.

    Time Complexity:
        - O(N), where N = number of nodes.

    Space Complexity:
        - O(H), where H = height of the tree (due to recursion stack).

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int x){
        val = x;
        left = right = nullptr;
    }
};


int isBalancedRec(Node* root){
    if(root == nullptr){
        return 0;
    }
    
    int lHeight = isBalancedRec(root->left);
    int rHeight = isBalancedRec(root->right);
    
    if(lHeight==-1 || rHeight == -1 ||  abs(lHeight-rHeight)>1){
        return -1;
    }
    return max(lHeight , rHeight) + 1;
}

bool isBalanced(Node* root){
    return isBalancedRec(root)>0;
}


int main(){
    
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    cout << (isBalanced(root) ? "The tree is balanced\n" : "The tree is not balanced\n");
    
    
    return 0;
}
