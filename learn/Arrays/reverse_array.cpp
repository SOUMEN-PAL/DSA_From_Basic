#include <bits/stdc++.h>
using namespace std;

void rev(int arr[] , int n){
    int m=n-1;
    for(int i = 0 ; i<n ; i++){
        if(i<m){
            arr[i] = arr[m];
        }
        else{
            arr[m]=arr[i];
        }
        m=m-1;
    }

    for(int j = 0 ; j<n ; j++){
        cout<<arr[j]<<" ";
    }
}



int main(){
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    rev(arr,n);

    
    return 0;
}