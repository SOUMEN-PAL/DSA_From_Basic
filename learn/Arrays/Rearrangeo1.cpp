#include <bits/stdc++.h>
using namespace std;

void arra(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        int x = arr[i]; // storing the current element at the index //
        int y = arr[x]; // the value thath hase to be there but in the combined way to extract the has to be value which is stored as indexing value //

        arr[i] = x + (y%n)*n;
    }

    for(int i = 0 ; i<n ; i++){
        arr[i] = arr[i]/n;
    }
}


int main(){
    
    int arr[] = {4,0,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    arra(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }  


    return 0;
}