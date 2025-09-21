/*
    Title: Dijkstra’s Algorithm (Single Source Shortest Path using Min Heap)

    Problem Statement:
        - Given a weighted graph with V vertices and E edges (undirected, weighted).
        - Each edge has form {u, v, w}, where u and v are vertices, and w is weight.
        - Find the shortest distance from a given source node to every other node.

  
    Output:
        - Prints the shortest distance from source to all vertices.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> builAdj(int V,vector<vector<int>> &edges){
    vector<vector<pair<int,int>>> res(V);
    
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        res[u].push_back({v,wt});
        res[v].push_back({u,wt});
        
    }
    return res;
}

vector<int> dijkstra(int src, int V, vector<vector<int>> &edges){
    vector<vector<pair<int,int>>> adj = builAdj(V,edges);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    
    vector<int> dist (V,INT_MAX);
    dist[src]=0;
    minHeap.push({0,src});
    
    while(!minHeap.empty()){
        int u = minHeap.top().second;
        int currentDist = minHeap.top().first;
        
        minHeap.pop();
        for(auto neighbour : adj[u]){
            int v = neighbour.first;
            int wt = neighbour.second;
            if(dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
                minHeap.push({dist[v],v});
            }
        }
    }
    
    return dist;
}

int main(){
    int src = 0;
    int V  =5;
    vector<vector<int>> edges = {{0,1,4},{0,2,8},{2,3,2},{3,4,10},{1,4,6}};
    
    vector<int> distance = dijkstra(src,V,edges);
    
    for(auto dist : distance){
        cout<<dist<<"  ";
    }
    return 0;
}
