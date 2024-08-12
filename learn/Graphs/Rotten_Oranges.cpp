#include<bits/stdc++.h>
using namespace std;

bool isValid(int row , int col , int n , int m , vector<vector<int>> &visited , vector<vector<int>> &grid){
    if(row<n && row>=0 && col<m && col>=0 && grid[row][col] == 1 && visited[row][col] != 2){
        return true;
    }
    return false;
}


int rotten_oranges(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();

    queue<pair<pair<int , int> , int>>  q;
    vector<vector<int>> visited(n , vector<int>(m));


    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(arr[i][j] == 2){
                q.push({{i , j} , 0});
                visited[i][j] = 2;
            }
            else{
                visited[i][j] = 0;
            }
        }
    }

    int tm = 0;
    while(!q.empty()){
        auto curr = q.front();
        int r = curr.first.first;
        int c = curr.first.second;
        int t = curr.second;
        tm = max(tm , t);
        q.pop();

        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , 1 , 0 , -1};
        for(int i = 0 ; i<4 ; i++){
            int nRow = drow[i] + r;
            int nCol = dcol[i] + c;
            if(isValid(nRow , nCol , n , m , visited , arr)){
                q.push({{nRow , nCol} , t+1});
                visited[nRow][nCol] = 2;
            }
        }
    }
     
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(visited[i][j] != 2 && arr[i][j] == 1){
                return -1;
            }
        }
    }
    return tm;
}




int main(){
    vector<vector<int>> grid = {
        {0 , 1 , 2},
        {0 , 1 , 2},
        {2 , 1 , 1}
    };

    cout<<rotten_oranges(grid)<<endl;
    

    return 0;
}