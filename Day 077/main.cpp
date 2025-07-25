/*
    Title: N-Queens Problem using Backtracking.
    Problem Statement:
        - Place N queens on an N x N chessboard such that no two queens threaten each other.
        - A queen can move any number of squares vertically, horizontally, or diagonally.
        - Print all possible arrangements where N queens can be safely placed.

    Author: Siddhi
*/

#include<iostream>
#include<vector>
using namespace std;

void nQueenFunction(int j, int n,
                    vector<bool>& rows,
                    vector<bool>& diag1,
                    vector<bool>& diag2,
                    vector<int>& board,
                    vector<vector<int>>& res) {
    if(j == n + 1){
        res.push_back(board);
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!rows[i] && !diag1[i - j + n] && !diag2[i + j]) {
            rows[i] = diag1[i - j + n] = diag2[i + j] = true;
            board.push_back(i);

            nQueenFunction(j + 1, n, rows, diag1, diag2, board, res);

            board.pop_back();
            rows[i] = diag1[i - j + n] = diag2[i + j] = false;
        }
    }
}

vector<vector<int>> nQueen(int n){
    vector<bool> rows(n + 1, false);
    vector<bool> diag1(2 * n + 1, false);
    vector<bool> diag2(2 * n + 1, false);
    vector<int> board;
    vector<vector<int>> res;

    nQueenFunction(1, n, rows, diag1, diag2, board, res);
    return res;
}

int main(){
    int n = 5;
    vector<vector<int>> result = nQueen(n);

    cout << n << "-Queen Solutions:\n";
    for (auto sol : result){
        cout << "[ ";
        for (int j : sol){
            cout << j << " ";
        }
        cout << "]\n";
    }

    return 0;
}
