#include <bits/stdc++.h>
using namespace std;


// naive solution //
void rotate(int arr[], int n , int j)
{
    int temp = arr[n-1];
    for(int i = n-1 ; i>j ; i--){
        arr[i] = arr[i-1];
    }
    arr[j] = temp;
}



void alter(int arr[] , int n){
    for(int i = 0 ; i<n ; i=i+2){
        rotate(arr , n , i);
    }
}





int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    alter(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}