#include<bits/stdc++.h>
using namespace std;


int rem_dup(int arr[] , int n){
    int res = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i-1]!=arr[i]){
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}



int main(){
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a = rem_dup(arr , n);

    for(int i = 0 ; i<a ; i++){
        cout<<arr[i]<<" ";
    }




    return 0;
}