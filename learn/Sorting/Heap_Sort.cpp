#include<bits/stdc++.h>
using namespace std;

void maxHeap(int arr[] , int n  , int i){
    int largest = i , left = 2*i+1 , right = 2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest] , arr[i]);
        maxHeap(arr , n , largest);
    }
}

void buildHeap(int arr[]  , int n){
    for(int i = (n-2)/2 ; i>=0 ; i--){
        maxHeap(arr , n , i);
    }
}


void heap_sort(int arr[] , int n){
    buildHeap(arr , n);
    for(int i = n-1 ; i>=1 ; i--){
        swap(arr[0] , arr[i]);
        maxHeap(arr , i , 0);
    }
}

int main(){
    int arr[] = {50,20,10,4,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr , n);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}