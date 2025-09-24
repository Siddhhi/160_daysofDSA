/*
    Title: Clone an Undirected Graph (DFS Approach)

    Problem Statement:
        - You are given a reference to a node in a connected undirected graph.
        - Each node contains an integer value and a list of neighbors.
        - The task is to return a deep copy (clone) of the graph.
        
    Author: Siddhi
*/


#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// DFS helper function
Node* dfs(Node* node, unordered_map<Node*, Node*>& copies) {
    if (copies.count(node)) {
        return copies[node]; // already cloned
    }

    Node* clone = new Node(node->val);
    copies[node] = clone;

    for (auto neighbor : node->neighbors) {
        clone->neighbors.push_back(dfs(neighbor, copies));
    }

    return clone;
}

// Clone graph function
Node* cloneGraph(Node* node) {
    if (node == NULL) return NULL;
    unordered_map<Node*, Node*> copies;
    return dfs(node, copies);
}

// Utility function to print adjacency list of a graph
void printGraph(Node* node) {
    if (!node) return;

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Node " << curr->val << " -> ";
        for (auto neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << "\n";
    }
}

int main() {
    // Constructing example graph:
    //  1 -- 2
    //  |    |
    //  4 -- 3

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "Original Graph:\n";
    printGraph(n1);

    Node* clonedGraph = cloneGraph(n1);

    cout << "\nCloned Graph:\n";
    printGraph(clonedGraph);

    return 0;
}



