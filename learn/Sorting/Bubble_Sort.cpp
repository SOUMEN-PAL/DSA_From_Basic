#include<bits/stdc++.h>
using namespace std;


// naive solution //
void bubbleSort(int arr[] , int n){
    for(int i = 0 ; i<n-1 ; i++){
        for(int j = 0 ; j<n-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

// Optiised Approach //
void Bubble_Sort(int arr[] , int n){
    for(int i = 0 ; i<n-1 ; i++){
        for(int j = 0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}


// Efficient solution //
void Sort_Bubble(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        bool swaped = false;
        for(int j = 0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
                swaped = true;
            }
        }
        if(swaped == false){
            break;
        }
    }
}



int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    Sort_Bubble(arr , n);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}