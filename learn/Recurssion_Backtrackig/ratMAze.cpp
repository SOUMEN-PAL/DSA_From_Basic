#include <bits/stdc++.h>
using namespace std;

void solve(int i , int j , vector<vector<int>> &grid , int n , int m , vector<string> &ans , string move , vector<vector<bool>> &visited , vector<vector<vector<int>>> &maze) {
    if(i == n-1 && j == m-1){
        ans.push_back(move);
        vector<vector<int>> temp(n , vector<int>(m , 0));
        for(int  i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(visited[i][j]){
                    temp[i][j] = 1;
                }
            }
        }
        maze.push_back(temp);
        return;
    }

    string dir = "RDLU";
    int dirX[] = {0 , 1 , 0 , -1};
    int dirY[] = {1 , 0 , -1 , 0};

    for(int d = 0 ; d < 4 ; d++){
        int nx = i + dirX[d];
        int ny = j + dirY[d];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > 0){
            visited[nx][ny] = true;
            solve(nx , ny , grid , n , m , ans , move + dir[d] , visited , maze);
            visited[nx][ny] = false;
        }
    }
}

int main(){
    int n = 5, m = 5;
    vector<vector<int>> maze = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 1, 1, 1}
    };
    
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<vector<int>>> mazes;
    if(maze[0][0] == 1) {
        visited[0][0] = true;
        solve(0, 0, maze, n, m, ans, "", visited , mazes);
    }

    for(auto &path : ans){
        cout << path << " ";
    }
    cout << endl;

//print mazes 
    for(auto &m : mazes){
        for(auto &row : m){
            for(auto &ele : row){
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
