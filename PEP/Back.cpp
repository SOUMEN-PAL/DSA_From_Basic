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
    
    return 0;
}
