#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &grid , vector<vector<bool>> &visited , int r , int c , int n , int m){
    if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && visited[r][c] == false){
        return true;
    }
    return false;
}

void DFS(vector<vector<char>> &grid , vector<vector<bool>> &visited , int sx , int sy , int n , int m){
    stack<pair<int , int>> st;
    st.push({sx , sy});
    visited[sx][sy] = true;
    
    int dRow[] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
    int dCol[] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
    
    while(!st.empty()){
        auto curr = st.top();
        int r = curr.first;
        int c = curr.second;
        st.pop();
        for(int i = 0 ; i<8 ; i++){
            int nRow = dRow[i] + r;
            int nCol = dCol[i] + c;
            
            if(isValid(grid , visited , nRow , nCol , n , m)){
                visited[nRow][nCol] = true;
                st.push({nRow , nCol});
            }   
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    int res = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(grid[i][j] == '1' && visited[i][j] == false){
                res++;
                DFS(grid , visited , i , j , n , m);
            }
        }
    }
    return res;
}


int main(){
    
    return 0;
}