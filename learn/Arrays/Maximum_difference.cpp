#include <bits/stdc++.h>
using namespace std;

// naive solution //

void diff(int arr[] , int n){
    int temp = arr[1] - arr[0];
    for(int i = 0 ; i<n ; i++){
        for(int j = n-1 ; j>i ; j--){
            temp = max(temp , (arr[j]-arr[i]));
        }
    }

    cout<<temp<<endl;
}

// efficient solution //

void max_diff(int arr[] , int n){
    int temp = arr[1]-arr[0] , minvalue = arr[0];
    for(int i = 0 ; i<n ; i++){
        temp = max(temp , arr[i]-minvalue);
        minvalue = min(arr[i],minvalue);
    }

    cout<<temp<<endl;
}


int main(){
    int arr[] = {30,10,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    diff(arr , n);
    max_diff(arr , n);
    


    return 0;
}