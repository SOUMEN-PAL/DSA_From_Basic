#include<bits/stdc++.h>
using namespace std;

// given the fact that the array is sorted //
// naive solution is linear search //

// Binary search itreative solution //

int binary_search_itre(int arr[] , int n , int x){
    int low = 0 , high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]<x){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

// recurssive solution //
int binary_search_recurr(int arr[] , int low , int high , int x){
    int mid = (high+low)/2;
    if(low>high){
        return -1;
    }
    if(arr[mid]==x){
        return mid;
    }
    if(arr[mid]>x){
        return binary_search_recurr(arr , low , mid-1 , x);
    }
    else{
        return binary_search_recurr(arr , mid+1 , high , x);
    }
}






int main(){
    
    int arr[] = {1,2,3,4,5,6,7,34,5,6,7,8,9,0,4,3,32,4,4,59,4,2,2,3,4,5,6,7,8,444,6,4,3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 9;
    sort(arr , arr+n);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<binary_search_itre(arr , n , x)<<endl;
    cout<<binary_search_recurr(arr , 0 , n-1 , x)<<endl;





    return 0;
}