/*
    Title: Celebrity Problem (Using Stack)

    Problem Statement:
        - You are given a matrix `mat` of size N×N.
        - mat[i][j] = 1 means person `i` knows person `j`.
        - A celebrity is a person who:
            1. Does NOT know anyone.
            2. Is known by everyone else.
        - Find the index of the celebrity if present, otherwise return -1.

    Author: Siddhi
*/

#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    stack<int> st;

    for(int i = 0; i < n; i++){
        st.push(i);
    }

    while(st.size() > 1){
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if(mat[a][b] == 1)
            st.push(b);
        else
            st.push(a);
    }

    int celeb = st.top();

    for(int i = 0; i < n; i++){
        if(i != celeb && (mat[celeb][i] == 1 || mat[i][celeb] == 0)){
            return -1;
        }
    }

    return celeb;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int res = celebrity(mat);

    if(res == -1)
        cout << "No celebrity found\n";
    else
        cout << "Celebrity is person index: " << res << endl;

    return 0;
}




