#include<bits/stdc++.h>
using namespace std;

bool isValid(int x , int y , int n , int m , vector<vector<bool>> visited){
    if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==false){
        return true;
    }
    return false;
}

void DFS(vector<vector<int>> &matrix , int n , int m , int si , int sj){
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    stack<pair<int , int>> s;
    s.push({si , sj});
    visited[si][sj] = true;

        int dx[] = {0 , 1 , 0 , -1};
        int dy[] = {-1 , 0 , 1 , 0};

    while(s.empty() == false){
        auto curr = s.top();
        int x = curr.first;
        int y = curr.second;
        s.pop();
        cout<<matrix[x][y]<<" ";
        visited[x][y] = true;

        for(int i = 0 ; i<4 ; i++){
            if(isValid(x+dx[i] , y+dy[i] , n , m , visited)){
                s.push({x+dx[i] , y+dy[i]});
            }
        }
    }
}


int main(){
    vector<vector<int>> matrix;

    matrix.push_back({1, 2,3,4,5});
    matrix.push_back({6,7,8,9,10});
    matrix.push_back({11,12,13,14,15});
    matrix.push_back({16,17,18,19,20});
    matrix.push_back({21,22,23,24,25});

    int n = matrix.size();
    int m = matrix[0].size();

    DFS(matrix , n , m , 0 , 0);

    return 0;
}