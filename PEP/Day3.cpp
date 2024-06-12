#include<bits/stdc++.h>
using namespace std;

int first_occurence(int arr[] , int low , int high , int x , int n){
    if(high>=low){
        int mid = low+(high-low)/2;
        if((mid==0 || arr[mid-1]<x) && arr[mid]==x){
            return mid;
        }
        else if(x>arr[mid]){
            return first_occurence(arr , mid+1 , high , x , n);
        }
        else{
            return first_occurence(arr , low , mid-1 , x , n);
        }
    }
    else{
        return -1;
    }
}



int lasr_occurence(int arr[] , int x , int n){
    int high = n-1;
    int low = 0;
    while(high>=low){
        int mid = (low+high)/2;
        if((x<arr[mid+1] || mid == n-1) && arr[mid] == x ){
            return mid;
        }
        else if(x<arr[mid]){
            high = mid-1 ;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}




int main(){

    int arr[] = {1,1,2,2,2,2,3,4,5,5,6,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Last occurence: "<<lasr_occurence(arr , 2 , n)<<endl;
    cout<<"First occurence: "<<first_occurence(arr , 0 , n , 2 , n)<<endl;

    
    return 0;
}