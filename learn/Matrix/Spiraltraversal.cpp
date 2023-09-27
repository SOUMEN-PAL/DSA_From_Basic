#include<bits/stdc++.h>
using namespace std;

void spiral_Traversal(vector<vector<int>> &arr , int r , int c){
    int top = 0 , bottom = r-1 , left = 0 , right = c-1;
    while(top<=bottom && left<=right)
    {
        for(int i = left ; i<=right ; i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i = top ; i<=bottom ; i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i = right ; i>=left ; i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i = bottom ; i>=top ; i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
    }
}


int main(){
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int n = arr.size();
    int m = arr[0].size();   
    spiral_Traversal(arr , n , m);
    return 0;
}