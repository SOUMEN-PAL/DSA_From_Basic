#include<bits/stdc++.h>
using namespace std;

// Rat in a maze or Flood Fill
int ratInAMaze(vector<vector<int>> &maze, int i, int j, string path, vector<vector<int>> &visited){
    if(i<0 || j<0 || i>=maze.size() || j>=maze[0].size() || maze[i][j]==0 || visited[i][j]==1){
        return 0;
    }
    if(i==maze.size()-1 && j==maze[0].size()-1){
        
        return 1;
    }
    visited[i][j] = 1;
    int ans = 0;
    ans += ratInAMaze(maze, i-1, j, path+"U", visited);
    ans += ratInAMaze(maze, i, j-1, path+"L", visited);
    ans += ratInAMaze(maze, i+1, j, path+"D", visited);
    ans += ratInAMaze(maze, i, j+1, path+"R", visited);
    visited[i][j] = 0;
    return ans;
}



//N queen
bool isSafe(vector<vector<int>> &board, int i, int j){
    for(int row = 0; row<i; row++){
        if(board[row][j]==1){
            return false;
        }
    }
    int x = i;
    int y = j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x = i;
    y = j;
    while(x>=0 && y<board.size()){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nQueen(vector<vector<int>> &board, int i){
    if(i==board.size()){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board.size(); j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    for(int j = 0; j<board.size(); j++){
        if(isSafe(board, i, j)){
            board[i][j] = 1;
            bool nextQueen = nQueen(board, i+1);
            if(nextQueen){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

//Sudoko 
bool isSafe(vector<vector<int>> &board, int i, int j, int num){
    for(int x = 0; x<9; x++){
        if(board[i][x]==num || board[x][j]==num){
            return false;
        }
    }
    int sx = (i/3)*3;
    int sy = (j/3)*3;
    for(int x = sx; x<sx+3; x++){
        for(int y = sy; y<sy+3; y++){
            if(board[x][y]==num){
                return false;
            }
        }
    }
    return true;
}

void sudoko(vector<vector<int>> &board, int i, int j){
    if(i==9){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }


    if(j==9){
        sudoko(board, i+1, 0);
        return;
    }

    
    if(board[i][j]!=0){
        sudoko(board, i, j+1);
        return;
    }
    for(int num = 1; num<=9; num++){
        if(isSafe(board, i, j, num)){
            board[i][j] = num;
            sudoko(board, i, j+1);
            board[i][j] = 0;
        }
    }
    return;
}


int main(){
    vector<vector<int>> maze = {
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };
    vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
    int res = ratInAMaze(maze, 0, 0, "", visited);
    cout<<res<<endl;
    

    vector<vector<int>> board(4, vector<int>(4, 0));
    nQueen(board, 0);
    

    vector<vector<int>> sudokoBoard = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudoko(sudokoBoard, 0, 0);


    

    return 0;
}
