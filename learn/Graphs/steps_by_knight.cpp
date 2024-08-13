#include<bits/stdc++.h>
using namespace std;


bool isValid(vector<vector<bool>> &visited , int r , int c , int n){
    if(r>=0 && r<n && c >= 0 && c < n && visited[r][c] == false){
        return true;
    }
    return false;
}

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
{
    // Code here
    int res = INT_MAX;
    vector<vector<bool>> visited(n , vector<bool>(n , false));
    queue<pair<pair<int , int> , int>> q;
    
    if(TargetPos[0] == KnightPos[0] && TargetPos[1] == KnightPos[1]){
        return 0;
    }
    
    q.push({{KnightPos[0]-1 , KnightPos[1]-1} , 0});
    visited[KnightPos[0]-1][KnightPos[1]-1] = true;
    
    
    
    while(!q.empty()){
        auto curr = q.front();
        int r = curr.first.first;
        int c = curr.first.second;
        int steps = curr.second;
        q.pop();
        
        if(r == TargetPos[0]-1 && c == TargetPos[1]-1){
            res = min(res , steps);
        }
        
        int dRow[] = {-2 , -2 , -1 , 1 , 2 , 2 , 1 , -1};
        int dCol[] = {-1 , 1 , 2 , 2 , 1 , -1 , -2 , -2};
        
        for(int i = 0 ; i<8 ; i++){
            int nRow = r + dRow[i];
            int nCol = c + dCol[i];
            
            if(isValid(visited , nRow , nCol , n)){
                q.push({{nRow , nCol} , steps + 1});
                visited[nRow][nCol] = true;
            }
        }
    }
    return res;
}
int main(){
    int n = 7;
    vector<int> StartPos = {4,5};
    vector<int> TargetPos = {5,6};
    
    int res = minStepToReachTarget(StartPos , TargetPos , n);
    cout<<res<<endl;

    return 0;
}