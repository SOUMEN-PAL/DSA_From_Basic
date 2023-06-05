#include<bits/stdc++.h>
using namespace std;

int fisrt_occurence(int arr[] , int low , int high , int x , int n){
    if(high>=low){
        int mid = (low+high)/2;
        if( x>arr[mid-1] && arr[mid]==x || mid==0){
            return mid;
        }
        else if(x>arr[mid]){
            return fisrt_occurence(arr , mid+1 , high , x , n);
        }
        else{
            return fisrt_occurence(arr , low , mid-1 , x , n);
        }
    }
}

int lasr_occurence(int arr[] , int low , int high , int x , int n){
    if(high>=low){
        int mid = (low+high)/2;
        if(x<arr[mid+1] && arr[mid] == x || mid == n-1){
            return mid;
        }
        else if(x<arr[mid]){
            return lasr_occurence(arr , low , mid-1 , x , n);
        }
        else{
            return lasr_occurence(arr , mid+1 , high , x , n);
        }
    }
}



int main(){

    int arr[] = {1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,5,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    int i = fisrt_occurence(arr , 0 , n-1 , key , n);
    int j = lasr_occurence(arr , 0 , n-1 , key , n);
    int count = j-i+1;
    cout<<count<<endl;



    
    return 0;
}