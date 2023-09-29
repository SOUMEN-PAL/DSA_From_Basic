#include<bits/stdc++.h>
using namespace std;

// naive solution //
bool search(vector<vector<int>> &arr , int n , int m , int target){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(arr[i][j] == target){
                cout<<"{ "<<i<<" , "<<j<<" }"<<endl;
                return true;
            }
        }
    }
    return false;
}

// Efficient solution //

bool Matrix_Search(vector<vector<int>> &arr , int r , int c , int target)
{
    int i = 0 , j = c-1;
    if(arr[0][0]>target){
        return false;
    }
    if(target>arr[r-1][c-1]){
        return false;
    }
    while(i<r && j>=0){
        if(arr[i][j] == target){
            cout<<i<<" "<<j<<endl;
            return true;
        }
        else if(arr[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> arr = {
        {10 ,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };
    int n = arr.size();
    int m = arr[0].size();
    int x = 39;
    bool k = search(arr , n , m ,x);
    bool l = Matrix_Search(arr , n , m , x);
    
    return 0;
}