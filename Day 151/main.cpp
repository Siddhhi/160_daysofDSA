/*
    Title: Bellman-Ford Algorithm (Single Source Shortest Path)

    Problem Statement:
        - You are given a weighted directed graph with V vertices and a list of edges.
        - Each edge is represented as {u, v, w}, meaning there is an edge from u → v 
          with weight w (which can be negative).
        - The task is to find the shortest path from a given source vertex to all 
          other vertices.
        - If there exists a negative weight cycle reachable from the source, return {-1}.
        
    Author: Siddhi
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, int src, vector<vector<int>>& edges){
    vector<int> dist (V,1e8);
    dist[src]=0;
    
    for(int i = 0 ;i<V;i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                if(i==V-1){
                    return {-1};
                }
                
                dist[v] = dist[u]+w;
            }
        }
    }
    
    return dist;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = {{1,3,2},{4,3,-1},{2,4,1},{1,2,1},{0,1,5}};
    int src = 0;
    
    vector<int> res = bellmanFord(V,src,edges);
    cout<<"Shortest path from "<<src<<" vertex : ";
    for(auto val : res){
        cout<<val<<"  ";
    }
}
