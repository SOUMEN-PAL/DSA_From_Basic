#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int brr[] = {6,7,8,9,10};

    //merge two sworted array
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(brr)/sizeof(brr[0]);
    int i = 0 , j = 0;
    while(i<n && j<m){
        if(arr[i]<brr[j]){
            cout<<arr[i]<<" ";
            i++;
        }
        else{
            cout<<brr[j]<<" ";
            j++;
        }
    }
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
    while(j<m){
        cout<<brr[j]<<" ";
        j++;
    }

    
    return 0;
}