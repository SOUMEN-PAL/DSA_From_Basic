#include <bits/stdc++.h>
using namespace std;

// naive solution //
int trap_rain(int arr[] , int n){
    int res = 0;
    for(int  i = 1 ; i<n-1 ; i++){
        int lmax = arr[i];
        for(int j = 0 ; j<i ; j++){
            lmax = max(arr[j] , lmax);
        }

        int rmax = arr[i];
        for(int j = i+1 ; j<n ; j++){
            rmax = max(rmax , arr[j]);
        }

        res = res + (min(lmax , rmax)-arr[i]);
    }
    return res;
}


// efficient solution //

int t_rain(int arr[] , int n){
    int lmax[n] , rmax[n];
    lmax[0] = arr[0];

    int res = 0;
    // pre computing the left and right max //
    for(int i = 1 ; i<n ; i++){
        lmax[i] = max(arr[i] , lmax[i-1]);
    }

    rmax[n-1] = arr[n-1];
    for(int i = n-2 ; i>=0 ; i--){
        rmax[i] = max(arr[i] , rmax[i+1]);
    }

    for(int i = 1 ; i <n-1 ; i++ ){
        res = res + (min(lmax[i] , rmax[i]) - arr[i]); // ass all the values are precompute it is jst computing the amount of water that can be trap //
    }
    return res;
}



int main(){
    
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<trap_rain(arr , n)<<"    "<<t_rain(arr , n);



    return 0;
}