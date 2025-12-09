/*
    Title: Distribute Candies in a Binary Tree (Minimum Moves)

    Problem Statement:
        - You are given a binary tree where each node contains an integer value.
        - Each value represents the number of candies at that node.
        - Every node must end up with exactly **one candy**.
        - In one move, you may transfer a candy to/from an adjacent node (parent or child).
        - The task is to compute the **minimum number of moves** required so that
          every node has exactly one candy.

        Output:
            8 moves (for balancing all nodes to 1 candy each)

    Dry Run:
        - Each leaf with 0 → needs 1 candy → returns -1
        - Internal children accumulate deficits
        - Root with 5 distributes extra candies downward
        - Total moves = |l| + |r| at each node

    Time Complexity:
        - O(N), where N = number of nodes (each visited once).

    Space Complexity:
        - O(H), where H = tree height (recursion stack).

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int val){
      data=val;
      left=right=nullptr;
  }
  
};

int distCandyUtil(Node* root, int &ans){
    if(root==nullptr){
        return 0;
    }
    
    int l = distCandyUtil(root->left,ans);
    int r = distCandyUtil(root->right,ans);
    
    ans+= abs(l) + abs(r);
    
    return root->data + l+r-1;
}

int distCandy(Node* root){
    int ans = 0;
    distCandyUtil(root,ans);
    return ans;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(0);
    root->right = new Node(0);
    root->left->left = new Node(0);
    root->right->right = new Node(0);
    
    int steps = distCandy(root);
    cout<<"Step to distribute candies to all nodes : "<<steps<<"\n";
    return 0;
}
