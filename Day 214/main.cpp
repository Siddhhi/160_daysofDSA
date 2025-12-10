/*
    Title: Vertical Order Traversal of a Binary Tree

    Problem Statement:
        - Given the root of a binary tree, return its vertical order traversal.
        - Nodes are grouped based on their horizontal distance (HD) from the root:
              HD(root) = 0
              Left child  → HD - 1
              Right child → HD + 1
        - The traversal must be level-order (BFS) so that nodes appearing earlier 
          in the tree appear earlier in their vertical group.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<vector<int>> verticalOrder(Node *root) {
    if (!root) return {};

    unordered_map<int, vector<int>> lst;
    queue<pair<Node*, int>> q;

    q.push({root, 0});
    int mn = 0, mx = 0;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        mn = min(mn, hd);
        mx = max(mx, hd);

        lst[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    vector<vector<int>> res;
    for (int i = mn; i <= mx; i++) {
        res.push_back(lst[i]);
    }

    return res;
}

int main() {
    /*
            Constructed Binary Tree:
                     1
                   /   \
                  2     3
                 / \   / \
                4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = verticalOrder(root);

    cout << "Vertical Order Traversal:\n";
    for (auto &col : result) {
        cout << "[ ";
        for (int val : col)
            cout << val << " ";
        cout << "]\n";
    }

    return 0;
}



