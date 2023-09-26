#include<bits/stdc++.h>
using namespace std;

// c style passing 2d array //
void print(int **arr , int m , int n){
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            cout<<arr[i][j]<<" "; 
        }
        cout<<endl;
    }
}

// using aray of pointers //



int main(){
    int **arr;
    int m = 3 , n = 2;
    arr = new int *[m];
    for(int i = 0 ; i<m ; i++){
        arr[i] = new int[n];
        for(int j = 0 ; j<n ; j++){
            arr[i][j] = i;
        }
    }

    print(arr , m , n);
    return 0;
}