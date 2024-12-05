#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<string>& board,int row,int col,int n){
    int nrow;
    int ncol;
    
    // upper diagonal
    nrow = row-1;
    ncol = col-1;

    while(nrow>=0 && ncol>=0){
        if(board[nrow][ncol]=='Q')return false;
        nrow--;
        ncol--;
    }

    // left side way
    nrow = row,
    ncol = col-1;
    while(ncol>=0){
        if(board[nrow][ncol]=='Q'){
            return false;
        }
        ncol--;
    }

    // lower diagonal

    nrow = row+1;
    ncol = col-1;

    while(nrow<n && ncol>=0){
        if(board[nrow][ncol]=='Q')return false;
        nrow++;
        ncol--;
    }
    return true;
}
void solve(vector<string>& board, vector<vector<string>>& ans,int col,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    
    for (int row = 0; row < n; row++)
    {
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(board,ans,col+1,n);
            // backtracking
            board[row][col]='.';
        }
    }
    
}
int main(){
    int n=5;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0; i<n; i++){
        board[i] = s;
    }
    for(int i=0; i<board.size(); i++){
        cout<<board[i]<<endl;
    }

    solve(board,ans,0,n);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<n;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<"-----------"<<endl;
    }
    return 0;
}