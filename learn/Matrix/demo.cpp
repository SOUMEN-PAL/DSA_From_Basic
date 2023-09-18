#include<bits/stdc++.h>
using namespace std;



int main(){
    pair<int , int> arr[4][4];
    for(int i = 0 ; i<4 ; i++){
        for(int j = 0 ; j<4 ; j++){
            arr[i][j] = make_pair(i , j);
        }
    } 
    for(int i = 0 ; i<4 ; i++){
        for(int j = 0 ; j<4 ; j++){
            cout<<"{"<<arr[i][j].first<<","<<arr[i][j].second<<"} ";
        }
        cout<<endl;
    } 
    return 0;
}