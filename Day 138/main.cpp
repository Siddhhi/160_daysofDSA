/*
    Title: Depth First Search (DFS) Traversal of a Graph

    Problem Statement:
        - Implement Depth First Search (DFS) for a given undirected graph 
          represented as an adjacency list.
        - Perform DFS starting from node 0 and print the traversal order.

    Space Complexity:
        - O(V), for visited array and recursion stack.

    Output:
        - Returns a vector of nodes in DFS traversal order.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void dfsRec(int i, vector<bool> &visited, vector<int> &res, vector<vector<int>> &adj) {
    visited[i] = true;
    res.push_back(i);

    for (auto x : adj[i]) {
        if (!visited[x]) {
            dfsRec(x, visited, res, adj);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> res;

    dfsRec(0, visited, res, adj); // start from node 0
    return res;
}
int main(){
    
    vector<vector<int>> adj ={{2,3,1},{0},{0,4},{0},{2}};
    
    vector<int> result = dfs(adj);
    
    cout<<"The DFS traversal will be : ";
    for(int i = 0;i<result.size();i++){
        cout<<" "<<result[i];
    }
    cout<<"\n";
    return 0;

}

