#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

bool isSafe(vector<vector<int>> &mat , int i , int j , int num){
    //checking the row and column
    for(int x = 0 ; x<9 ; x++){
        if(mat[i][x] == num || mat[x][j] == num){
            return false;
        }
    }

    //checking the square
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;

    for(int x = sx ; x < sx + 3 ; x++){
        for(int y = sy ; y < sy + 3 ; y++){
            if(mat[x][y] == num){
                return false;
            }
        }
    }

    return true;
}

void printGrid(vector<vector<int>> &grid){
    for(int i = 0;i<9 ; i++){
        for(int j = 0 ; j<9 ; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}


void solve(vector<vector<int>> &grid , int N , int i , int j){
    if(i == 9){
        printGrid(grid);

        return;
    }

    if(j == 9){
        solve(grid , N , i+1 , 0);
        return;
    }

    if(grid[i][j] != 0){
        solve(grid , N , i , j+1);
        return;
    }

    for(int num = 0 ; num <= 9 ; num++){
        if(isSafe(grid , i , j , num)){
            grid[i][j] = num;
            solve(grid , N , i , j+1);
            grid[i][j] = 0;
        }
    }

    return;

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = 9;
    vector<vector<int>> grid = { 
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } 
    }; 

    solve(grid , N , 0 , 0);


    return 0;
}