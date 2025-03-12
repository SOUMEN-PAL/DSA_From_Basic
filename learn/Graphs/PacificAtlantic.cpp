#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


class Solution {
private:
    int m, n;
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        
        for(auto [dr, dc] : directions) {
            int newR = r + dr;
            int newC = c + dc;
            
            if(newR >= 0 && newR < m && newC >= 0 && newC < n && 
               !visited[newR][newC] && heights[newR][newC] >= heights[r][c]) {
                dfs(newR, newC, heights, visited);
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};
        
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        
        for(int i = 0; i < m; i++) dfs(i, 0, heights, pacific);
        for(int j = 0; j < n; j++) dfs(0, j, heights, pacific);
        
        for(int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic);
        for(int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic);
        
        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}