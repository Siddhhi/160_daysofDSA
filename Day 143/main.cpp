/*
    Title: Topological Sort of a Directed Acyclic Graph (DAG) using Kahn's Algorithm

    Problem Statement:
        - Given a directed graph with V vertices and a list of edges.
        - Perform Topological Sorting of the graph.
        - A topological ordering of a Directed Acyclic Graph (DAG) is a linear ordering 
          of its vertices such that for every directed edge (u → v), 
          vertex u comes before v in the ordering.

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalOrder(int V, vector<vector<int>>& edges){
    vector<vector<int>> adj(V);
    
    deque<int> q;
    
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    vector<int> indegree(V,0);
    vector<int> ans;
    for(int i = 0;i<edges.size();i++){
        indegree[edges[i][1]]++;
    }
    
    for(int i = 0;i<V;i++){
        if(indegree[i]==0){
            q.push_back(i);
        }
    }
    
    while(!q.empty()){
        int i = q.front();
        q.pop_front();
        ans.push_back(i);
        
        for(int j : adj[i]){
            indegree[j]--;
            if(indegree[j]==0){
                q.push_back(j);
            }
        }
    }
    
    return ans;
    
    
}

int main(){
    
    int V = 6;
    
    vector<vector<int>> edges = {{1,3},{4,1},{4,0},{2,3},{5,0},{5,2}};
    vector<int> result = topologicalOrder(V,edges);
    
    cout<<"The possible topological Order for this Directed Acyclic Graph : \n";
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    
    return 0;
}
