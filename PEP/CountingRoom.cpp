#include<bits/stdc++.h>
using namespace std;


void bfs(vector<vector<bool>> &visited , vector<vector<char>> &mat , int  i , int j , int n , int m){
    queue<pair<int , int>> q;
    q.push({i , j});
    visited[i][j] = true;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        int dirX[] = {0 , 1 , 0 , -1};
        int dirY[] = {1 , 0 , -1 , 0};

        for(int k = 0 ; k<4 ; k++){
            int nx = dirX[k] + x;
            int ny = dirY[k] + y;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == false && mat[nx][ny] == '.'){
                q.push({nx , ny});
                visited[nx][ny] = true;
            }
        }
    }
    
}





int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> mat(n , vector<char>(m));
    queue<pair<int , int>> q;
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin>>mat[i][j];
        }
    }


    int cnt = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(mat[i][j] == '.' && visited[i][j] == false){
                bfs(visited , mat , i , j , n , m);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}