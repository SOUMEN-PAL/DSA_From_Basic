#include <bits/stdc++.h>
using namespace std;

// naive solution //

void move(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        if(arr[i]==0){
            for(int j = i+1 ; j<n ; j++){
                if(arr[j]!=0){
                    swap(arr[i],arr[j]);
                }
            }
        }
    }
}

// efficient solution //
void move_zeros(int arr[] , int n ){
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]!=0){
            swap(arr[count],arr[i]);
            count++;
        }
    }
}


int main(){
    int arr[] = {1,4,5,6,7,0,0,0,3,5,6,0,5,0,7,333,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    move_zeros(arr , n);
    cout<<"[ ";
    for(int i = 0 ; i<n ; i++){
        
        cout<<arr[i]<<" ";
    }
    cout<<"]";



    return 0;
}