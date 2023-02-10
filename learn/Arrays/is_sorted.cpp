#include <bits/stdc++.h>
using namespace std;


// naive solution //
bool is_sorted(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[j]<arr[i]){
                return false;
            }
        }
    }
    return true;

}


// efficient solution //

bool if_sorted(int arr[] , int n){
    for(int i = 1 ; i<n ; i++){
        if(arr[i-1]>arr[i]){
            return false;
        }
    }
    return true;
}



int main(){


    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<is_sorted(arr , n)<<endl;
    cout<<if_sorted(arr , n)<<endl;


    return 0;
}