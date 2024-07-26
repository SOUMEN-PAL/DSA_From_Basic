#include<bits/stdc++.h>
using namespace std;

bool isValid(int row , int col , vector<vector<bool>> &visited , int n , int m){
    if(row < 0 || col <0 || row >= n || col >= m){
        return false;
    }

    if(visited[row][col] == true){
        return false;
    }

    return true;
}

void BFS(vector<vector<int>> arr , int n , int m , int row , int column){
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    queue<pair<int , int>> q;
    q.push({row , column});

    while(!q.empty()){
        auto curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();
        cout<<arr[x][y]<<" ";

        int rowD[] = {-1 , 0 , 1 , 0};
        int colD[] = {0 , 1 , 0 , -1};
        //Traversing Direction 
        for(int i = 0 ; i<4 ; i++){
            int adjX = x + rowD[i];
            int adjY = y + colD[i];
            if(isValid(adjX , adjY , visited , n , m)){
                q.push({adjX , adjY});
                visited[adjX][adjY] = true;
            }
        }
    }
}


int main(){
    vector<vector<int>> arr;
    arr.push_back({1,2,3,4,5});
    arr.push_back({6,7,8,9,10});
    arr.push_back({11,12,13,14,15});
    arr.push_back({16,17,18,19,20});
    arr.push_back({21,22,23,24,25});
    int n = arr.size();
    int m = arr[0].size();

    BFS(arr , n , m , 0 , 0);

    return 0;
}