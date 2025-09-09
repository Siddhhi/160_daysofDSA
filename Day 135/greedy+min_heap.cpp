/*
    Title: Job Sequencing Problem with Deadlines (Greedy + Min Heap)

    Problem Statement:
        - You are given two arrays:
            • deadline[i] → last time slot by which job i should be completed
            • profit[i]   → profit earned if job i is completed before or on its deadline
        - Task: Find the maximum number of jobs that can be done and the maximum 
          profit achievable, assuming each job takes exactly 1 unit of time.

    Output:
        Returns a vector<int> of size 2:
            • ans[0] → number of jobs completed
            • ans[1] → maximum profit earned

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    
    int n = deadline.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    
    vector<pair<int,int>> jobs;
    
    for(int i = 0;i<n;i++){
        jobs.push_back({deadline[i],profit[i]});
    }
    
    sort(jobs.begin(),jobs.end());
    
    for(int i =0;i<n;i++){
        if(jobs[i].first>(int)pq.size()){
            pq.push(jobs[i].second);
        }else if(!pq.empty() && pq.top() < jobs[i].second){
            pq.pop();
            pq.push(jobs[i].second);
        }
    }
    
    vector<int> ans = {0,0};
    while(!pq.empty()){
        ans[0]+=1;
        ans[1]+=pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
    
    vector<int> deadline = {2,1,2,1,1};
    vector<int> profit = {100,19,27,25,15};
    
    vector<int> result = jobSequencing(deadline,profit);
    
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<"   ";
    }
    return 0;
}
