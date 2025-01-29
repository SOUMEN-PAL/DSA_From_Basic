#include<bits/stdc++.h>
using namespace std;


void solve(int i , int j , vector<vector<int>> grid  , int n , int m , vector<string> &ans , string move , vector<vector<bool>> &visited){
    if(i == n-1 && j == m-1){
        ans.push_back(move);
        return;
    }
}



int main(){
    int n = 5 , m = 5;
    vector<vector<int>> maze = {
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {1,0,1,1,1}
    };

    
    return 0;
}