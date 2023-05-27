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






int main(){
    
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 6;

    cout<<binary_search_itre(arr , n , x)<<endl;
    cout<<(upper_bound(arr , arr+n , x)-arr)-1;





    return 0;
}