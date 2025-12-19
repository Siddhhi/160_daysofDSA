/*
    Title: Meeting Room with Maximum Bookings.

    Problem Statement:
        - You are given `n` meeting rooms, indexed from 0 to n-1.
        - You are also given a list of meetings, where each meeting is represented
          as [startTime, endTime].
        - Meetings must be scheduled using the following rules:
            1. A meeting is assigned the smallest-indexed available room.
            2. If no room is available, the meeting is delayed until the earliest
               room becomes free.
            3. Delayed meetings keep the same duration.
        - Return the index of the room that gets booked the maximum number of times.
        - If there is a tie, return the smallest room index.

    Author: Siddhi
*/


#include<bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings) {
    vector<int> cnt(n,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occ;
    priority_queue<int, vector<int>, greater<int>> avail;

    for(int i = 0 ; i < n ; i++){
        avail.push(i);
    }

    sort(meetings.begin(), meetings.end());

    for(auto &m : meetings){
        int s = m[0];
        int e = m[1];

        while(!occ.empty() && occ.top().first <= s){
            avail.push(occ.top().second);
            occ.pop();
        }

        if(!avail.empty()){
            int room = avail.top();
            avail.pop();
            occ.push({e, room});
            cnt[room]++;
        }
        else{
            auto [endTime, room] = occ.top();
            occ.pop();
            occ.push({endTime + (e - s), room});
            cnt[room]++;
        }
    }

    int res = 0;
    for(int i = 1; i < n; i++){
        if(cnt[i] > cnt[res]){
            res = i;
        }
    }

    return res;
}

int main(){
    int n = 2;
    vector<vector<int>> meetings = {{0,10}, {1,5}, {2,7}, {3,4}};

    cout << "Room with maximum bookings: "
         << mostBooked(n, meetings) << "\n";

    return 0;
}







