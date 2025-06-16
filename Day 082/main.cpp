/*
    Title: Diameter of a Binary Tree

    Problem Statement:
        - Given a binary tree, compute its diameter.
        - The diameter is the number of edges in the longest path between any two nodes in the tree.
        - This path may or may not pass through the root.


    Space Complexity:
        - O(h), where h is the height of the binary tree (for recursion stack).

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
using namespace std;

// Define the Tree node class
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

// Helper function to compute diameter recursively
int diameterRec(Tree* root, vector<int>& res) {
    if (root == NULL) return 0;

    int lHeight = diameterRec(root->left, res);
    int rHeight = diameterRec(root->right, res);

    // Update the diameter (number of edges in longest path)
    res[0] = max(res[0], lHeight + rHeight);

    return 1 + max(lHeight, rHeight);
}

// Function to compute diameter
int diameter(Tree* root) {
    vector<int> res = {0};
    diameterRec(root, res);
    return res[0];
}

int main() {
    // Create a test binary tree
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    // Output the diameter
    cout << "Diameter of the Binary Tree: " << diameter(root) << endl;

    return 0;
}
