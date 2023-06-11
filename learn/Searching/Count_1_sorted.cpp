#include<bits/stdc++.h>
using namespace std;

int count_ones(int arr[] , int n){
    int low = 0 , high = n-1;
    while(high>=low){
        int mid = (high + low)/2;
        if(arr[mid]==0){
            low = mid+1;
        }
        else{
            if(mid==0 || arr[mid - 1] != arr[mid]){
                return (n-mid);
            }
            else{
                high = mid - 1;
            }
        }
    }
}


int main(){
    int arr[] = {0,0,0,0,0,1,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<count_ones(arr , n)<<endl;
    return 0;
}