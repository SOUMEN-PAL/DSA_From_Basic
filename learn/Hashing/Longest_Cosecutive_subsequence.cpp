#include<bits/stdc++.h>
using namespace std;

// Naive Solution //
int longest(int arr[] , int n){
    sort(arr , arr+n); // Method 1 by sorting //
    int curr = 1;
    int res = 1;
    for(int i = 1 ; i<n ; i++){
        if(arr[i] == arr[i-1] + 1){
            curr++;
            res = max(res , curr);
        }
        else if(arr[i] != arr[i-1]){ // dealing and ignoring the repeated element buy not doing anythong for arr[i] == arr[i-1]//
            res = max(res , curr);
            curr = 1;
        }
    }
    return res;
}

// Efficient Solution //


int main(){
    int arr[] = {1,9,3,4,2,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longest(arr , n)<<endl;
    return 0;
}