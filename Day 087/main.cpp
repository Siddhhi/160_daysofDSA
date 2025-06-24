/*
    Title: Morris Inorder Traversal of Binary Tree

    Problem Statement:
        - Traverse a binary tree in inorder without using recursion or stack.

   
    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Tree Node Definition
class Tree {
public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Find rightmost node in left subtree (inorder predecessor)
Tree* findPredecessor(Tree* root) {
    Tree* curr = root->left;
    while (curr->right && curr->right != root) {
        curr = curr->right;
    }
    return curr;
}

// Morris Inorder Traversal
vector<int> morrisTraversal(Tree* root) {
    vector<int> res;
    Tree* curr = root;

    while (curr) {
        if (curr->left == NULL) {
            res.push_back(curr->data);
            curr = curr->right;
        } else {
            Tree* pred = findPredecessor(curr);

            if (pred->right == NULL) {
                pred->right = curr;  // Create thread
                curr = curr->left;
            } else {
                pred->right = NULL;  // Remove thread
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return res;
}

int main() {
    // Manual binary tree
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    // Morris traversal
    vector<int> inorderResult = morrisTraversal(root);

    cout << "Morris Inorder Traversal: ";
    for (int val : inorderResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
