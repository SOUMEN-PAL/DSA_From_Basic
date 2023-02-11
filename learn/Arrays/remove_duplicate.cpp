#include <bits/stdc++.h>
using namespace std;


// naive solution //
int rep(int arr[] , int n){
    int temp[n];
    temp[0] = arr[0];
    int res = 1;

    for(int i = 1 ; i<n ; i++){
        if(temp[res-1]!=arr[i]){
            temp[res] = arr[i];
            res++;
        }
    }

    for(int i = 0 ; i<res ; i++){
        arr[i] = temp[i];
    }
    for(int j = res ; j<n ; j++){
        arr[j] = 0;
    }
    return res;






}

// efficient solution //

int repeat(int arr[] , int n){
    int res = 1;

    for(int i = 1 ; i<n ; i++){

        if(arr[i]!=arr[i-1]){
            arr[res] = arr[i];
            res++;
        }




    }
    

    return res;


    
}






int main(){
    int arr[] = {10 , 10 , 10,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int soz = repeat(arr , n);
    for(int i = 0 ; i<soz ; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}