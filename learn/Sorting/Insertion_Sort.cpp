#include<bits/stdc++.h>
using namespace std;

void insertion_Sort(int arr[] , int n){
    for(int i = 1 ; i<n ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}





int main(){
    int arr[] {1,4,5,6,9,6,5,3,2,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_Sort(arr,n);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}