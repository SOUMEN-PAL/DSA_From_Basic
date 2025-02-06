#include<bits/stdc++.h>
using namespace std;


//Naive approach
bool isSafe(vector<vector<int>> &board , int i , int j){
    //checking the above rows
    for(int row = 0 ; row < i ; row++){
        if(board[row][j] == 1){
            return false;
        }
    }

    int x = i;
    int y = j;

    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }

        x--;
        y--;
    }

    x = i;
    y = j;

    while(x >= 0 && y < board.size()){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    return true;
}

void helper(vector<vector<int>> &board , int n , int row , vector<vector<vector<int>>> &ans){
    if(row == n){
        ans.push_back(board);
        return;
    }

    for(int col = 0 ; col < n ; col++){
        if(isSafe(board , row , col)){
            board[row][col] = 1;
            helper(board , n , row + 1 , ans);
            board[row][col] = 0; //backtracking and reseting the value
        }
    }
}

bool nQueen(int n){
    if(n<4){
        return false;
    }

    vector<vector<int>> board(n , vector<int>(n , 0));
    int i = 0;
    vector<vector<vector<int>>> ans;

    helper(board , n , 0 , ans);

    for(int i = 0 ; i<ans.size() ; i++){
        cout<<"Solution: "<<i+1<<endl;
        for(int row = 0 ; row<n ; row++){
            for(int col = 0 ; col < n ; col++){
                cout<<ans[i][row][col]<<" ";
            }
            cout<<endl;
        }
    }
    return true;
}


int main(){
    nQueen(7);
    return 0;
}