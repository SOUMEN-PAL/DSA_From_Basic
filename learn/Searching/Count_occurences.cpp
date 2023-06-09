#include<bits/stdc++.h>
using namespace std;

int first_index(int arr[] , int n , int x){
    int h = n-1;
    int l = 0;
    while(h>=l){
        int mid = l + (h - l)/2;
        if((mid==0 || arr[mid-1]<x) && arr[mid]==x){
            return mid;
        }
        else if(x>arr[mid]){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }

    return -1;
}


int last_index(int arr[] , int n , int x){
    int h = n-1;
    int l = 0;
    while(h>=l){
        int mid = l + (h - l)/2;
        if((x<arr[mid+1] || mid == n-1) && arr[mid] == x){
            return mid;
        }
        else if(x>arr[mid]){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}




int main(){

    int arr[] = {1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int x;
    cin>>x;
    int f = last_index(arr , n , x);
  
    cout<<f;


    
    return 0;
}