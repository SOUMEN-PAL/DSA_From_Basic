#include <bits/stdc++.h>
using namespace std;

void stock(int arr[] , int n){
    int maxi = 0;
    for(int i = 1 ; i<n ; i++){
        if(arr[i]>arr[i-1]){
            int c = arr[i] - arr[i-1];
            maxi = maxi + c;
        }
    }
    cout<<maxi<<endl;
}


int main(){
    int arr[] = {1,5,3,8,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    stock(arr , n);

    return 0;
}