/*
    Title: Rotten Oranges Problem (Minimum Time to Rot All Oranges)

    Problem Statement:
        - You are given a grid (n x m) where:
            0 → Empty cell
            1 → Fresh orange
            2 → Rotten orange
        - Every minute, a rotten orange makes its 4-directionally adjacent
          fresh oranges rotten.
        - Return the minimum time required so that no fresh orange remains.
        - If it is impossible, return -1.

    Author: Siddhi
*/


#include<iostream>
#include<deque>
#include<vector>
using namespace std;

bool isSafe(int x,int y, int n , int m){
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    return true;
}


int rottenOranges(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    
    deque<pair<int,int>> q;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mat[i][j]==2){
                q.push_back({i,j});
            }
        }
    }
    
    int elapsedTime = 0;
    
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while(!q.empty()){
        elapsedTime++;
        
        int l = q.size();
        
        for(int k=0;k<l;k++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            
            for(auto d : dir){
                x = x + d[0];
                y = y + d[1];
                
                if(isSafe(x,y,n,m) && mat[x][y]==1){
                    mat[x][y]=2;
                    q.push_back({x,y});
                }
            }
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mat[i][j]==1){
                return -1;
            }
        }
    }
    
    return elapsedTime==0 ? 0 : elapsedTime-1;
}


int main(){
    vector<vector<int>>mat = {{2,1,1},{2,0,1},{1,0,1}};
    
    cout<<"Minimum time required to rotten all oranges : "<<rottenOranges(mat);
    return 0;
}
