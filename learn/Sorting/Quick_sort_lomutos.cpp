#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],  int low , int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low ; j<=high-1 ; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i+1;
}


void quickSort(int arr[] , int low , int high){
    if(high>low){
        int p = partition(arr , low , high);
        quickSort(arr , low , p-1);
        quickSort(arr , p+1 , high);
    }
}


int main(){
    
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr , 0 , n-1);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}