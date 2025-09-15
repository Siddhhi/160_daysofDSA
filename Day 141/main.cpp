/*
    Title: Cycle Detection in an Undirected Graph (DFS)

    Problem Statement:
        - You are given an undirected graph with `V` vertices and a list of edges.
        - Task: Check if the graph contains a cycle.
        - Return:
            • true  → if there exists a cycle
            • false → otherwise

    Author: Siddhi
*/


#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adjacency(int V, vector<vector<int>>&edges){
    vector<vector<int>> res(V);
    
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        res[u].push_back(v);
        res[v].push_back(u);
    }
    
    return res;
}

bool dfs(int i , vector<bool> & vis,vector<vector<int>>&adj,int parent){
    vis[i] = true;
    
    for(auto x : adj[i]){
        if(!vis[x]){
            if(dfs(x,vis,adj,i)){
                return true;
            }
        }
        else{
            if(x!=parent){
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int V, vector<vector<int>> edges){
    vector<vector<int>> adj(V);
    
    adj = adjacency(V,edges);
    
    vector<bool> vis(V,false);
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,vis,adj,-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    
    vector<vector<int>> edges = {{1,0},{2,3},{4,1},{1,3},{2,4},{2,1}};
    int V = 5;
    if(isCycle(V,edges)){
        cout<<"Cycle is detected\n";
    }
    else{
        cout<<"No cycle detected\n";
    }
    return 0;
}
